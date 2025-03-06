#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    head->next = malloc(sizeof(struct Node)); // Nested allocation
    // Missing frees for head->next and head
    return 0;
}