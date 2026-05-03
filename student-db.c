#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_the_flag() {
  open("/tmp/flag")
  printf("%s\n", argv[0]);
}

int main(int argc, char *argv[]) {

