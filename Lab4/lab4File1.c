#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(sizeof(int) * 10); // Allocate memory
    arr[0] = 42;
    printf("Value: %d\n", arr[0]);
    // Missing free(arr)
    return 0;
}