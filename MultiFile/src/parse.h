//
// Created by Björn Kötter on 16.05.26.
//

#ifndef LEARNING_C_PARSE_H
#define LEARNING_C_PARSE_H
#include <stdio.h>
#include <unistd.h>

// Take a file-descriptor and read all non-empty lines and lines not starting with #
inline char readFile(const int fd)
{
    char buffer[1024];
    while (read(fd, buffer, sizeof(buffer)) > 0)
    {
        if (buffer[0] == '\n') continue;
        printf("%s", buffer);
    }
    return buffer;
}


#endif //LEARNING_C_PARSE_H
