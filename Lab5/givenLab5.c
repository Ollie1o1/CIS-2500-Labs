#include "headerLab5.h"

int main () {
    
    Stack s;           // declare a stack variable
    int element;
    
    s = createNewStack ();          // create an empty stack
    
    /* pushing 4 elements onto stack s*/
    push (3, &s);
    push (4, &s);
    push (10, &s);
    push (20, &s);
    
    printf ("Popping all elements:");
    
    while ((!isEmpty(s))) {
      
      element = pop(&s);
      printf ("%d ", element);
   }
   
   printf ("\n");
    
}

/*this function pushes an element to stack s
 Note that the stack is passed-by-reference because pushing an element
 will not only add the element to the top of the stack, but also change
 the top of the stack */

void push (int element, Stack * s ) {
        
    s->top = s->top + 1;
    s->stack[s->top] = element;
    
}

/*this function removes the top element from stack s
 Note that the stack is passed-by-reference because popping an element
 will not only remove the top element of the stack, but also change
 the top of the stack */

int pop (Stack * s) {
    
    int element;
    
    element = s->stack [s->top];
    s->top = s->top - 1;
    
    return element;
}

Stack createNewStack (void) {

    Stack s;

    s.top = -1;    // empty stack
    return s;
}

int isEmpty (Stack s) {
   
   return s.top < 0; // empty stack - could have used == -1
   
}

