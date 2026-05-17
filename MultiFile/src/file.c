//
// Created by Björn Kötter on 16.05.26.
//

#include "../file.h"

#include <stdio.h>
#include <sys/fcntl.h>

int openFile(const char* fileName, const char* mode)
{
    int fd = open(fileName, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
    }
    return fd;
}
