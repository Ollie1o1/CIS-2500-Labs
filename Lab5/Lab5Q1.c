#include "headerLab5.h"

void enqueue(int element, Stack *s) {
    push(element, s);
}

int dequeue(Stack *s) {
    Stack temp = createNewStack();
    int dequeued_element;

    // Pop all elements from s to temp
    while (!isEmpty(*s)) {
        int elem = pop(s);
        push(elem, &temp);
    }

    // The front element is at the top of temp
    dequeued_element = pop(&temp);

    // Push remaining elements back to s
    while (!isEmpty(temp)) {
        int elem = pop(&temp);
        push(elem, s);
    }

    return dequeued_element;
}

void implementLab5Q1(Stack s) {
    // Enqueue elements 10, 20, 30
    enqueue(10, &s);
    enqueue(20, &s);
    enqueue(30, &s);

    int sum = 0;
    int elements[3];
    int count = 0;

    // Dequeue elements to calculate sum
    while (!isEmpty(s)) {
        int elem = dequeue(&s);
        elements[count++] = elem;
        sum += elem;
    }

    // Print the sum in the specified format
    printf("Sum of ( ");
    for (int i = 0; i < count; ++i) {
        printf("%d", elements[i]);
        if (i < count - 1) {
            printf(" + ");
        }
    }
    printf(" ) = %d\n", sum);
}