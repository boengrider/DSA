#include "Glthreads.h" // Glued doubly linked list
#include <stddef.h>

void glll_init(glll_t *list) {
    list->head = NULL;
}

void glll_add(glll_t *list, glthread_node_t *new) {
    
    
    if(!list->head) {
        list->head = new;
        list->head->left = NULL;
        list->head->right = NULL;
        return;
    }

    glthread_node_t *node = list->head;

    while(node->right) 
        node = node->right;

    node->right = new;
    new->left = node;
    new->right = NULL;

}

void glll_remove(glthread_node_t *node) {
    
    //removing tail
    if(!node->right) {
        node->left->right = NULL;
    //removing head
    } else if(!node->left) {
        node->right->left = NULL;
    //removing other 
    } else {
        node->left->right = node->right;
        node->right->left = node->left;
    }
}