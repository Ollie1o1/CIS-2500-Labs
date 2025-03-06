#include <stdlib.h>
#include <stdio.h>

void process_data(int * data, int size);
int * allocate_array(int size);

int main() {
   
   int * data = allocate_array(5);
   for (int i = 0; i < 5; ++i) {
           data[i] = i * 10;
   }
   
    process_data(data, 5);

    int * more_data = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        more_data[i] = i;
    }
    free(data);
    return 0;
}

void process_data(int * data, int size) {
   
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    printf("Sum: %d\n", sum);
}

int * allocate_array(int size) {
   
    int * array = malloc(size * sizeof(int));
    return array;
}
