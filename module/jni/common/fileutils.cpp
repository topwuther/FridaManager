//
// Created by topwuther on 7/6/23.
//

#include "fileutils.h"


std::string fileutils::readFile(const std::string &filepath) {
    std::string content;
    std::ifstream file(filepath);
    if (!file.is_open()) {
        LOGE("Failed to open the file.\n");
    }
    else {
        std::string line;
        while (std::getline(file, line)) { // Read each line from the file
            content += line;
        }
    }
    return content;
}
