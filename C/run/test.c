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

void printEmpDetails(glthread_node_t*);

int main()
{
    unsigned long glueOffset = offsetof(emp_t, glue);

    emp_t e1 = { "Jon Doe", 1000, "Engineer", 10};
    emp_t e2 = { "Jane Doe", 2000, "CEO", 1};

    e1.glue.left = NULL; //NO previous node
    e1.glue.right = &e2.glue;

    gll_t emps = { "Employees", &e1.glue};
    
    glthread_node_t *next = emps.head;

    while(next != NULL)
    {
        printEmpDetails(next);
        next = next->right;
    }

    

}

void printEmpDetails(glthread_node_t *glue)
{
    unsigned long nameOff = offsetof(emp_t, name);
    unsigned long salaryOff = offsetof(emp_t, salary);
    unsigned long desigantionOff = offsetof(emp_t, designation);
    unsigned long idOff = offsetof(emp_t, emp_id);

    void *pBase = (void*)glue - sizeof(emp_t) + sizeof(glthread_node_t);

    printf("Printing employee details\n");
    printf("ID: %d\nName: %s\nDesignation: %s\nSalary: %lu\n", \
           *((unsigned int*)(pBase + idOff)), (char*)pBase + nameOff, \
           (char*)pBase + desigantionOff, *((unsigned long*)(pBase + salaryOff)));


}