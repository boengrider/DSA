#include "glthread2.h"

void gllListInit(gll_t *list, glthread_node_t *head, char *listName, int listNameLength, comparator c, unsigned int glueOffset)
{
    for(int i = 0; i < listNameLength; i++)
    {
        list->name[i] = *(listName + i);
    }
    list->name[listNameLength] = '\0';
    list->head = head;
    list->key_compare = c;
    list->offset = glueOffset;

}

void gllListInsertNodeAfter(glthread_node_t *glnode_new, glthread_node_t *glnode_after, gll_t *list)
{
    
    if(list->head == NULL)
    {
        list->head = glnode_new;
    } else if(glnode_after->right != NULL)
    {
        glnode_after->right->left = glnode_new;
        glnode_after->right = glnode_new;
    } else {
        glnode_after->right = glnode_new;
    }

}

void gllListAppendNode(glthread_node_t *glnode_new, gll_t *list)
{
    glthread_node_t *next = list->head;

    //Determine the tail node
    while(next->right != NULL)
    {
        next = next->right;
    }

    next->right = glnode_new;
    glnode_new->left = next;
    
}

GLL_OP_RES_CODE gllListRemoveNode(gll_t *list, glthread_node_t *glnode, GLL_OPTION_CODE options)
{

    //List is empty
    if(list->head == NULL)
        return GLL_OP_RES_EMPTY;

    
    //This node is not in the list
    if(glnode->left == NULL && glnode->right == NULL)
        return GLL_OP_RES_NOTENLISTED;

    return GLL_OP_RES_REMOVED;

}