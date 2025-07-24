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
    int age;
    glthread_node_t glue;
} emp_t;



extern void gllListInsertNodeAfter(glthread_node_t *glnode_new, glthread_node_t *glnode_after, gll_t *list);
extern void gllListInit(gll_t *list, glthread_node_t *head, char *listName, int listNameLength, comparator c, unsigned int glue_offset);
extern void gllListAppendNode(glthread_node_t *glnode_new, gll_t *list);
extern GLL_OP_RES_CODE gllListRemoveNode(gll_t *list, glthread_node_t *removedNode, GLL_OPTION_CODE options);
void printEmpDetails(glthread_node_t*);
int compareEmpsBySalary(void*, void*);
int compareEmpsByAge(void*, void*);
void printEmpList(gll_t*);

int main()
{
    unsigned long glueOffset = offsetof(emp_t, glue);

    //Declare 3 emp_t structures
    emp_t e1 = { "Jon Doe", 1000, "Engineer", 10, 20,{ NULL, NULL}};
    emp_t e2 = { "Jane Doe", 2000, "CEO", 1, 25, {NULL, NULL}};
    emp_t e3 = { "Michael Scott", 1300, "Regional manager", 2, 30, {NULL, NULL}};
    //Glued linked list
    gll_t emps;

    if(gllListRemoveNode(&emps, &e1.glue, GLL_OPTION_ASSUME) == GLL_OP_RES_EMPTY)
        printf("List is empty, nothing was removed\n");

    
    
    //Initialize linked list
    gllListInit(&emps, &e1.glue, "Emploeyees", sizeof("Emploeyees"), compareEmpsBySalary, offsetof(gll_t, offset));
    gllListAppendNode(&e2.glue,&emps);
    gllListAppendNode(&e3.glue, &emps);

    int salaryComparison = emps.key_compare((void*)&e1, (void*)&e2);

    switch (salaryComparison) {
        case 0:
            printf("Salaries are equal\n");
            break;

        case 1:
            printf("Employee A's salary is greater than employess B's salary\n");
            break;

        case 2:
            printf("Employee A's salary is less than employees B's salary\n");
            break;
    }

    printf("Switching comparator to age comparator\n");
    emps.key_compare = compareEmpsByAge;
    int ageComparison = emps.key_compare((void*)&e1, (void*)&e2);
    
     switch (ageComparison) {
        case 0:
            printf("Both employees are the same age\n");
            break;

        case 1:
            printf("Employee A is older than employee B\n");
            break;

        case 2:
            printf("Employee A is younger than employee B\n");
            break;
    }

    printEmpList(&emps);
    

}

void printEmpList(gll_t *list)
{
    unsigned long nameOff = offsetof(emp_t, name);
    glthread_node_t *next = list->head;

    void *pBase = (void*)next - sizeof(emp_t) + sizeof(glthread_node_t);

    while(next != NULL)
    {
        printf("%s-->", (char*)pBase + nameOff);
        next = next->right;
        pBase = (void*)next->right - sizeof(emp_t) + sizeof(glthread_node_t);
    }
    printf("\n");
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

int compareEmpsBySalary(void *n1, void *n2)
{
    printf("Comparing object A at %p and object B at %p\n", n1, n2);

    emp_t *e1 = (emp_t*)n1;
    emp_t *e2 = (emp_t*)n2;

    if(e1->salary == e2->salary)
        return 0;

    if(e1->salary > e2->salary)
        return 1;

    if(e1->salary < e2->salary)
        return 2;
    
}

int compareEmpsByAge(void *n1, void *n2)
{
    printf("Comparing object A at %p and object B at %p\n", n1, n2);

    emp_t *e1 = (emp_t*)n1;
    emp_t *e2 = (emp_t*)n2;

    if(e1->age == e2->age)
        return 0;

    if(e1->age > e2->age)
        return 1;

    if(e1->age < e2->age)
        return 2;
    
}