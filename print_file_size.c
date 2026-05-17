#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/stat.h>

void print_file_size(const char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        perror("Unable to open file.");
        exit(1);
    }
    struct stat *st = 0;
    fstat(fd, st);
    if (st != 0)
    {
        perror("Unable to stat file.");
        exit(1);
    }
    printf("%lld\n", st->st_size);
    close(fd);
}

int main(int argc, char *argv[])
{
    print_file_size(argv[1]);
}
