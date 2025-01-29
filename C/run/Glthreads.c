#include "Glthreads.h"
#include <stdio.h>
#include <stddef.h>



typedef struct emp_ {
    char name[30];
    int salary;
    char position[30];
    unsigned int emp_id;
    glthread_node_t glnode;
} emp_t;

void printEmployeeInfo(glthread_node_t*);
void glll_print_db(glll_t*);

int main() {

    
    emp_t emp1 = {{"Jon Doe"}, 2500, {"Manager"}, 1000, {NULL, NULL}};
    emp_t emp2 = {{"Jane Doe"}, 3000, {"CEO"}, 1, {NULL, NULL}};
    emp_t emp3 = {{"Mark Simpleton"}, 2390, {"Worker"}, 340, {NULL, NULL}};

    glll_t employees; // Glued doubly linked list of employees
    glll_init(&employees); // Initialize the list

    glll_add(&employees, &emp1.glnode); // Adds first employee. Head is null at this point so the 1st element will become head
    glll_add(&employees, &emp2.glnode); // Adds second employee
    glll_add(&employees, &emp3.glnode); // Adds third employee



    
    printf("List prior deletion\n\n");
    glll_print_db(&employees);

    
    glll_remove(&emp2.glnode);
    printf("\n\n");

    printf("List after deletion\n\n");
    glll_print_db(&employees);
    

    glll_add(&employees, &emp2.glnode);

    printf("List prior addition\n\n");
    glll_print_db(&employees);

}

void glll_print_db(glll_t *list) {
     //Iterate over glthreads list
    glthread_node_t *node = list->head;
    while(node) {
        printEmployeeInfo(node);
        node = node->right;
    }
}

void printEmployeeInfo(glthread_node_t* node) {
    //base pointer
    void *base = (void*)node - offsetof(emp_t, glnode);
    
    //Print name
    printf("Name -> %s\n", (char*)(base));

    //Print salary
    printf("Salary -> %d\n", *(int*)(base + offsetof(emp_t, salary)));

    //Print position
    printf("Position -> %s\n", (char*)(base + offsetof(emp_t, position)));

    //Print id
    printf("ID -> %d\n", *(unsigned int*)(base + offsetof(emp_t, emp_id)));
    
}


