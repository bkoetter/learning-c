#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 128

int main(int argc, char **argv) {
    char *buf = malloc(BUF_SIZE);
    if (buf == NULL) {
        printf("Unabled to allocate memory.\n");
        return 1;
    }

    ssize_t bytes_read = read(0, buf, BUF_SIZE - 1);

    if (bytes_read < 0) {
        perror("Read error");
        free(buf);
        return 1;
    }

    buf[bytes_read] = '\0';

    printf("%s\n", buf);

    free(buf);
    return 0;
}
