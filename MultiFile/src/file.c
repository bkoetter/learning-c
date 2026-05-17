//
// Created by Björn Kötter on 16.05.26.
//

#include "../src/file.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>

int openFile(const char* fileName, const char* mode)
{
    const int fd = open(fileName, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(1);
    }
    return fd;
}
