//
// Created by topwuther on 7/6/23.
//

#ifndef ZYGISK_MODULE_SAMPLE_FDUTILS_H
#define ZYGISK_MODULE_SAMPLE_FDUTILS_H

#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include "log.h"

class fdutils {
public:
    static std::string readToString(int fd);
    static void writeFromString(int fd,const std::string& content);
};


#endif //ZYGISK_MODULE_SAMPLE_FDUTILS_H
