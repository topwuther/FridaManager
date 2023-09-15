//
// Created by topwuther on 7/6/23.
//

#ifndef ZYGISK_MODULE_SAMPLE_FILEUTILS_H
#define ZYGISK_MODULE_SAMPLE_FILEUTILS_H

#include <iostream>
#include <fstream>
#include "log.h"

class fileutils {
public:
    static std::string readFile(const std::string& filepath);
};


#endif //ZYGISK_MODULE_SAMPLE_FILEUTILS_H
