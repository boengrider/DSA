#include <stdio.h>
#include "glthread.h"
#include <stddef.h>


//#define offsetof(struct_name, field_name)  (unsigned int)&((struct_name *)0)->field_name

typedef struct emp_
{
    char name[30];
    unsigned long salary;
    char designation[30];
    unsigned int emp_id;
    glthread_node_t glue;
} emp_t;


typedef struct gll_
{
    char name[64]; //list name
    glthread_node_t *head; //1st node
} gll_t;

void gllListInsertAfter(glthread_node_t *glnode_new, glthread_node_t *glnode_after);
void gllListInit(gll_t *list, glthread_node_t *head, char *listName, size_t listNameLength);
void gllListAppend(glthread_node_t *glnode_new, gll_t *list);
void printEmpDetails(glthread_node_t*);

int main()
{
    unsigned long glueOffset = offsetof(emp_t, glue);

    //Declare 3 emp_t structures
    emp_t e1 = { "Jon Doe", 1000, "Engineer", 10, { NULL, NULL}};
    emp_t e2 = { "Jane Doe", 2000, "CEO", 1, {NULL, NULL}};
    emp_t e3 = { "Michael Scott", 1300, "Regional manager", 2, {NULL, NULL}};
    //Glued linked list
    gll_t emps;
    //Initialize linked list
    gllListInit(&emps, &e1.glue, "Emploeyees", sizeof("Emploeyees"));

    glthread_node_t *next = emps.head;


    printf("Printing employee details from the list '%s'\n", emps.name);
    while(next != NULL)
    {
        printEmpDetails(next);
        next = next->right;
    }

    printf("Adding additional employees to the list '%s'\n", emps.name);
    gllListAppend(&e2.glue, &emps);
    gllListAppend(&e3.glue, &emps);

    next = emps.head;
    printf("Printing employee details from the list '%s'\n", emps.name);
    while(next != NULL)
    {
        printEmpDetails(next);
        next = next->right;
    }
    

}

void gllListInit(gll_t *list, glthread_node_t *head, char *listName, size_t listNameLength)
{
    for(int i = 0; i < listNameLength; i++)
    {
        list->name[i] = *(listName + i);
    }
    list->name[listNameLength] = '\0';
    list->head = head;
}

void gllListInsertAfter(glthread_node_t *glnode_new, glthread_node_t *glnode_after)
{
    glnode_after->right = glnode_new;
}

void gllListAppend(glthread_node_t *glnode_new, gll_t *list)
{
    glthread_node_t *next = list->head;

    while(next->right != NULL)
    {
        next = next->right;
    }

    next->right = glnode_new;
}

void printEmpDetails(glthread_node_t *glnode)
{
    unsigned long nameOff = offsetof(emp_t, name);
    unsigned long salaryOff = offsetof(emp_t, salary);
    unsigned long desigantionOff = offsetof(emp_t, designation);
    unsigned long idOff = offsetof(emp_t, emp_id);

    void *pBase = (void*)glnode - sizeof(emp_t) + sizeof(glthread_node_t);

   
    printf("ID: %d\nName: %s\nDesignation: %s\nSalary: %lu\n", \
           *((unsigned int*)(pBase + idOff)), (char*)pBase + nameOff, \
           (char*)pBase + desigantionOff, *((unsigned long*)(pBase + salaryOff)));


}