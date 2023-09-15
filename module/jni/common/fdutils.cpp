//
// Created by topwuther on 7/6/23.
//

#include "fdutils.h"


std::string fdutils::readToString(int fd) {

    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];

    std::string fileContents;
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
        fileContents.append(buffer, bytesRead);
    }

    if (bytesRead == -1) {
        LOGD("Failed to read from the file descriptor.\n");
    }

    return fileContents;
}

void fdutils::writeFromString(int fd, const std::string& content) {
    write(fd, content.c_str(), content.size());
}
