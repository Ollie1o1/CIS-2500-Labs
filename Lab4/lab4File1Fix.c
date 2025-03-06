#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(sizeof(int) * 10);
    arr[0] = 42;
    printf("Value: %d\n", arr[0]);
    free(arr); // Fix: Free allocated memory
    return 0;
}