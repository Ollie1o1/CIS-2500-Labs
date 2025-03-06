#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = malloc(10);
    char *tmp = realloc(ptr, 100);
    if (tmp == NULL) {
        free(ptr); // Handle realloc failure
        return 1;
    }
    ptr = tmp;
    free(ptr);
    return 0;
}