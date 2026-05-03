#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void write_to_file(const char *path, const char *data)
{
    int fd = open(path, O_WRONLY | O_CREAT, 0666);
    write(fd, data, strlen(data));
    close(fd);
}

int main(int argc, char *argv[]) {
	char *path = "student.txt";
	char *data = "Fred,Feuerstein,2026/09/01\n";
	write_to_file(path, data);
}
