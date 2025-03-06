#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    head->next = malloc(sizeof(struct Node));

    free(head->next); // Free inner block first
    free(head);       // Then free outer block
    return 0;
}