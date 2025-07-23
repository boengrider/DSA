#include <stdio.h>
#include "glthread2.h"
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



extern void gllListInsertNodeAfter(glthread_node_t *glnode_new, glthread_node_t *glnode_after);
extern void gllListInit(gll_t *list, glthread_node_t *head, char *listName, int listNameLength);
extern void gllListAppendNode(glthread_node_t *glnode_new, gll_t *list);
extern void gllListRemoveNode(gll_t *list, glthread_node_t *removedNode);
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

    gllListAppendNode(&e2.glue,&emps);

    glthread_node_t *next = emps.head;

    while(next != NULL)
    {
        printEmpDetails(next);
        next = next->right;
    }

    printf("Removing head node\n");
    gllListRemoveNode(&emps, &e1.glue);


   
    

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

    printf("Node's %p right neighbour: %p\n", glnode, glnode->right);
    printf("Node's %p left nieghbour: %p\n", glnode, glnode->left);
}