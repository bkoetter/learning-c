#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct employee {
    int id;
    float income;
    bool staff;
};

int initialize_employee(struct employee *employees) {
    static int numEmployee = 0;

    employees->id = numEmployee;
    employees->income = 0;
    employees->staff = false;

    if (numEmployee == 5) {
        employees->income = 3000;
        printf("Set income to 3000\n");
    }
    numEmployee++;
    return numEmployee;
}

int main(int argv, char **args) {
    int count = 10;
    struct employee *employees = malloc(sizeof(struct employee) * count);
    if (employees == NULL) {
        printf("The allocator failed.\n");
        return -1;
    }

    for (int i=0; i<count; i++) {
        int num = initialize_employee(&employees[i]);
        printf("Employee number: %i\n", num);
        printf("Employee income: %f\n", employees[i].income);
    }
    printf("Employee number 5 income: %f\n", employees[5].income);

    free(employees);
    employees = NULL;
}
