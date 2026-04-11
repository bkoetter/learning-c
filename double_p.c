#include <stdio.h>
#include <stdlib.h>

void change_size(int **ptr, int num) {
    int *temp = realloc(*ptr, num);
    if (temp == NULL) {
        printf("realloc failed\n");
        return;
    };
    *ptr = temp;
}

int main(int argv, char **args) {
    int value = 10;
    int *ptr = (int *)malloc(sizeof(value));
    if (ptr == NULL) {
        printf("alloc failed\n");
        return -1;
    }
    int **dptr = &ptr;
    printf("Number: %d\n", **dptr);

    change_size(&ptr, sizeof(value));
    printf("New size of ptr: %lu\n", sizeof(ptr));

    return 0;
}
