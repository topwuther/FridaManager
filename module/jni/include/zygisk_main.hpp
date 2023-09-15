//
// Created by topwuther on 7/5/23.
//

#include <cstdlib>

#include "include/zygisk.hpp"
#include "log.h"
#include "fdutils.h"
#include "fileutils.h"
#include <iostream>
#include "json/json.h"
#include "fmt/format.h"
#define FRIDA_EXECUTE "/data/adb/frida/frida-inject"
#define CONFIG_DIR "/data/adb/frida/"
#define SCRIPT_DIR "/data/adb/frida/script/"
#define CONFIG_FILE "config.json"
#define CONFIG_PATH CONFIG_DIR CONFIG_FILE

