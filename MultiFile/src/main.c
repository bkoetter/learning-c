//
// Created by Björn Kötter on 16.05.26.
//

#include <sys/fcntl.h>

#include "file.h"

int main(int argc, char* argv[])
{
    int fd = openFile(argv[1], O_RDONLY);
}
