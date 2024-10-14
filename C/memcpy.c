#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

typedef struct person {
    char firstName[20];
    char lastName[20];
    char age;
} Person;

int main() {
    Person p1 = {"Jon", "Doe", 20};
    void *p2 = malloc(sizeof(Person));
    void *result = memcpy(p2,&p1,sizeof(Person));

    printf("Person p2's name is %s\n", ((Person*)p2)->firstName);

    printf("%p\n",result);
    printf("%p\n",p2);
    
}


