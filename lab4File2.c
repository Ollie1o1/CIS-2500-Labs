#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tag {
    char *name;
};

typedef struct tag Person;

Person *createPerson(const char *name);
void deletePerson(Person *p);
void processPersons();

int main() {
    processPersons();
    return 0;
}

Person *createPerson(const char *name) {
    Person *p = malloc(sizeof(Person));
    if (p == NULL) {
        return NULL;
    }

    p->name = malloc(strlen(name) + 1);
    if (p->name == NULL) {
        free(p);
        return NULL;
    }

    strcpy(p->name, name);
    return p;
}

void deletePerson(Person *p) {
    if (p) {
        free(p->name); // Fix: Free allocated memory for name
        free(p);
    }
}

void processPersons() {
    Person *janice = createPerson("Janice");
    Person *bob = createPerson("Bob");

    if (janice && bob) {
        printf("Processing persons: %s, %s\n", janice->name, bob->name);
    }

    deletePerson(janice);
    deletePerson(bob);
}