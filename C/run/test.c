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



extern void gllListInsertNodeAfter(gll_t *list, glthread_node_t *glnode_new, glthread_node_t *glnode_after);
extern void gllListInit(gll_t *list, glthread_node_t *head, char *listName, int listNameLength, comparator compare_fn, unsigned int glue_offset);
extern void gllListAppendNode(gll_t *list, glthread_node_t *glnode_new);
extern GLL_OP_RES_CODE gllListRemoveNode(gll_t *list, glthread_node_t *removedNode, GLL_OPTION_CODE options);
extern glthread_node_t* gllListRemoveNode2(glthread_node_t *node);
void printEmpDetails(gll_t*, glthread_node_t*);
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

    //Init the list. Sets the head and points it's right and left pointers to itself
    gllListInit(&emps, &e1.glue, "Employee list", 13, compareEmpsByAge, offsetof(emp_t, glue));

    //Append a few more nodes
    gllListAppendNode(&emps, &e1.glue);
    gllListAppendNode(&emps, &e2.glue);
    gllListAppendNode(&emps, &e3.glue);
    

    //Remove e3
    gllListRemoveNode2(&e3.glue);
    //Remove e2
    gllListRemoveNode2(&e2.glue);
    //Remove e1
    gllListRemoveNode2(&e1.glue);



   

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


void printEmpDetails(gll_t *list, glthread_node_t *glnode)
{
    unsigned long nameOff = offsetof(emp_t, name);
    unsigned long salaryOff = offsetof(emp_t, salary);
    unsigned long desigantionOff = offsetof(emp_t, designation);
    unsigned long idOff = offsetof(emp_t, emp_id);

    void *pBase = (void*)glnode - list->offset;

   
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
    
    return 0;
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

    return 0;
    
}