#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argv, char **args) {
    int fd = open("asdf", O_RDONLY);
    if (fd == -1) {
        perror("myerror");
    }
}
