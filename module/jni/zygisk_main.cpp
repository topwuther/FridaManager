/* Copyright 2022-2023 John "topjohnwu" Wu
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#include "include/zygisk_main.hpp"


using zygisk::Api;
using zygisk::AppSpecializeArgs;
using zygisk::ServerSpecializeArgs;


class FridaManager : public zygisk::ModuleBase {
public:
    void onLoad(Api *api, JNIEnv *env) override {
        this->api = api;
        this->env = env;
    }

    void preAppSpecialize(AppSpecializeArgs *args) override {
        // Use JNI to fetch our process name
        const char *process = env->GetStringUTFChars(args->nice_name, nullptr);
        preSpecialize(process);
        env->ReleaseStringUTFChars(args->nice_name, process);
    }

private:
    Api *api;
    JNIEnv *env;
    void preSpecialize(const char *_process) {

        //Set process and pid
        std::string process = _process;
        pid_t pid = getpid();

        //Set json string use to send data
        Json::Value json;
        json["process"] = process;
        json["pid"] = pid;
        Json::StreamWriterBuilder writerBuilder;
        std::string jsonString = Json::writeString(writerBuilder, json);
//        LOGD("Send=[%s]\n",jsonString.c_str());

        //Connect and send json data
        int fd = api->connectCompanion();
        fdutils::writeFromString(fd,jsonString);
        close(fd);
        api->setOption(zygisk::Option::DLCLOSE_MODULE_LIBRARY);
    }

};

static void companion_handler(int fd) {
    std::string data = fdutils::readToString(fd);
//    LOGD("Data=[%s]",data.c_str());

    //Parse data
    Json::Reader reader;
    Json::Value json;
    reader.parse(data, json);
    std::string process = json["process"].asString();
    int pid = json["pid"].asInt();
//    LOGD("Process=[%s],pid=[%d]\n",process.c_str(),pid);

    std::string script;
    std::string config = fileutils::readFile(CONFIG_PATH);
    reader.parse(config,json);
    for (auto & item : json) {
        std::string package = item["package"].asString();
        if(package == process){
            script = item["script"].asString();
            break;
        }
    }
    if(!script.empty()){
//        LOGD("Run script=[%s]\n",script.c_str());
        std::string command = fmt::format("{} -p {} -s {}{} -e",FRIDA_EXECUTE,pid,SCRIPT_DIR,script);
//        LOGD("Command=[%s]\n",command.c_str());
        int status = std::system(command.c_str());
//        LOGD("Result=[%d]\n",status);
    }
}


// Register our module class and the companion handler function
REGISTER_ZYGISK_MODULE(FridaManager)
REGISTER_ZYGISK_COMPANION(companion_handler)
