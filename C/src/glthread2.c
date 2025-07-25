#include "glthread2.h"
#include <stdio.h>

void gllListInit(gll_t *list, glthread_node_t *head, char *listName, int listNameLength, comparator c, unsigned int glueOffset)
{
    //Initializes empty list. Call once. Head left and right members point to the head itself at this point
    for(int i = 0; i < listNameLength; i++)
    {
        list->name[i] = *(listName + i);
    }
    list->name[listNameLength] = '\0';
    list->head = head;
    list->head->right = head;
    list->head->left = head;
    list->key_compare = c;
    list->offset = glueOffset;

}

void gllListInsertNodeAfter(gll_t *list, glthread_node_t *glnode_new, glthread_node_t *glnode_after)
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

void gllListAppendNode(gll_t *list, glthread_node_t *glnode_new)
{
    glthread_node_t *next = list->head;

    if(list->head->left == list->head->right) {
        list->head->right = glnode_new;
    } else {
        //Determine the tail node
        while(next->right != NULL)
        {
            next = next->right;
        }

        next->right = glnode_new;
        glnode_new->left = next;
        
    }
}

GLL_OP_RES_CODE gllListRemoveNode(gll_t *list, glthread_node_t *glnode, GLL_OPTION_CODE options)
{

    //List is empty
    if(list->head == NULL)
        return GLL_OP_RES_LIST_EMPTY;

    
    //This node is not in the list
    if(glnode->left == NULL && glnode->right == NULL)
        return GLL_OP_RES_NOT_ENLISTED;

    return GLL_OP_RES_NODE_REMOVED;

}

glthread_node_t* gllListRemoveNode2(glthread_node_t *node)
{
    //Empty noe
    if(node == NULL) {
        printf("Empty node\n");
        return NULL;
    }

    //Node not in the list
    if(node->left == NULL && node->right == NULL) {
        printf("Node not in the list\n");
        return NULL;
    }

    //Node is the head node
    if(node->left == node->right) {
        printf("Removing head node\n");
        node->left = node->right = NULL;
        return node;
    }

    //Node is the leaf node
    if(!node->right)
    {
        printf("Removing leaf node\n");
        //Leaf node
        node->left->right = NULL;
        return node;
    } 

    printf("Removing non-head non-leaf node\n");
    node->left->right = node->right;
    node->right->left = node->left;
        
    return node;
}