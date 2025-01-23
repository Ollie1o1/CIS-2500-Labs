 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_EMP 10

typedef struct employee {
    char fname[20];
    char lname[20];
    int id;
    char dependents[3][20];
} Employees;
 
 
 int loadEmployees(Employees arr[], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    int count = 0;
    for (int i = 0; i < NUM_EMP; i++) {
        // Read data from file (assumes format: fname lname id dependent1 dependent2 dependent3)
        if (fscanf(file, "%19s %19s %d %19s %19s %19s",
                  arr[i].fname,
                  arr[i].lname,
                  &arr[i].id,
                  arr[i].dependents[0],
                  arr[i].dependents[1],
                  arr[i].dependents[2]) != 6) {
            break; 
        }
        count++;
    }

    fclose(file);
    return count;
 }

void printAnEmployee(Employees emp) {
    printf("Id: %d\n", emp.id);
    printf("Full Name: %s %s\n", emp.fname, emp.lname);
    printf("Dependents: %s %s %s\n",
           emp.dependents[0],
           emp.dependents[1],
           emp.dependents[2]);
}