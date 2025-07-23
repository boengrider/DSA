#include "glthread2.h"

void gllListInit(gll_t *list, glthread_node_t *head, char *listName, int listNameLength)
{
    for(int i = 0; i < listNameLength; i++)
    {
        list->name[i] = *(listName + i);
    }
    list->name[listNameLength] = '\0';
    list->head = head;

}

void gllListInsertNodeAfter(glthread_node_t *glnode_new, glthread_node_t *glnode_after)
{
    glnode_after->right = glnode_new;

}

void gllListAppendNode(glthread_node_t *glnode_new, gll_t *list)
{
    glthread_node_t *next = list->head;

    while(next->right != NULL)
    {
        next = next->right;
    }

    next->right = glnode_new;
    glnode_new->left = next;
    
}

void gllListRemoveNode(gll_t *list, glthread_node_t *glnode)
{
    //Only remove if there's at least one node
    if(list->head != NULL)
    {
        
        if(list->head == glnode) //This node is the head node
        {   
          
            list->head = NULL;
        } else if (glnode->right == NULL) //This node is the tail node
        {
            
            glnode->left->right = NULL;
        } else //Removing other node
        {
           
            glnode->left->right = glnode->right;
            glnode->right->left = glnode->left;
        }


    }
}