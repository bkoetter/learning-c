#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_the_flag(void)
{
    const char* filename = "/tmp/flag";
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Can't open flag file\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = malloc(size + 1);
    if (buffer == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return;
    }
    int count = fread(buffer, 1, size, file);
    if (count != size)
    {
        fprintf(stderr, "Failed to read the entire flag file\n");
        free(buffer);
        fclose(file);
        return;
    }
    buffer[size] = '\0';
    fclose(file);
    printf("%s\n", buffer);
    free(buffer);
}

int main(int argc, char* argv[])
{
    print_the_flag();
    return 0;
}
