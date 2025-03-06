#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = malloc(10);
    ptr = realloc(ptr, 100); // Overwrite ptr without checking
    free(ptr);
    return 0;
}