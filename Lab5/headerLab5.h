#include <stdio.h>
#include <stdlib.h>
#define MAX 6

// Implementing Stacks using arrays

typedef struct {
    
    int stack[MAX];          // stack as an array
    int top;                 // top of the stack
    
} Stack;

/* given function definitions */
int pop (Stack * s);
void push (int element, Stack * s);
int isEmpty (Stack s);      // if s.top == -1, stack is empty
Stack createNewStack (void);

/* TO DO for lab 5 Question 1 - Write the function definitions for the following*/
void enqueue (int element, Stack * qAsStack);
int dequeue (Stack * qAsStack);

/* TO DO for lab 5 Question 2 - Write the function definition for the following*/
void implementLab5Q1 (Stack s);
