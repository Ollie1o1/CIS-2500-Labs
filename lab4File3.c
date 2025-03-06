#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pizzaMaker {
    char topping[30];
    struct pizzaMaker *next; // pointer to next topping
};

typedef struct pizzaMaker pizzaNode;

pizzaNode *AddTopping1(char *s, pizzaNode *head);
void AddTopping2(char *s, pizzaNode *head);
void displayAllToppingsR(pizzaNode *head);
void clearList(pizzaNode *head);

int main(int argc, char *argv[]) {
    pizzaNode *headPizza = NULL;
    pizzaNode *ptr, *newNode;

    pizzaNode *pnode1 = malloc(sizeof(pizzaNode));
    if (!pnode1) {
        return 1; // Allocation failure
    }

    strcpy(pnode1->topping, "Onion");
    pnode1->next = NULL;
    headPizza = pnode1;

    newNode = malloc(sizeof(pizzaNode));
    if (!newNode) {
        free(pnode1);
        return 1;
    }

    strcpy(newNode->topping, "Mushroom");
    newNode->next = NULL;

    ptr = headPizza;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;

    ptr = headPizza;
    while (ptr != NULL) {
        printf("%s\n", ptr->topping);
        ptr = ptr->next;
    }

    headPizza = AddTopping1("Green Pepper", headPizza);

    printf("After inserting in beginning, current LL is:\n");
    ptr = headPizza;
    while (ptr != NULL) {
        printf("%s\n", ptr->topping);
        ptr = ptr->next;
    }

    AddTopping2("Jalapeno", headPizza);

    printf("After inserting at end, current LL is:\n");
    displayAllToppingsR(headPizza);

    clearList(headPizza);
    return 0;
}

void displayAllToppingsR(pizzaNode *head) {
    if (head != NULL) {
        printf("%s \n", head->topping);
        displayAllToppingsR(head->next);
    }
}

pizzaNode *AddTopping1(char *s, pizzaNode *head) {
    pizzaNode *newPtr = malloc(sizeof(pizzaNode));
    if (!newPtr) {
        return head; // Allocation failure
    }

    strcpy(newPtr->topping, s);
    newPtr->next = head;

    return newPtr; // New head of the list
}

void AddTopping2(char *s, pizzaNode *head) {
    if (!head) {
        return; // Avoid dereferencing NULL
    }

    pizzaNode *newPtr = malloc(sizeof(pizzaNode));
    if (!newPtr) {
        return; // Allocation failure
    }

    strcpy(newPtr->topping, s);
    newPtr->next = NULL;

    pizzaNode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newPtr;
}

void clearList(pizzaNode *head) {
    pizzaNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}