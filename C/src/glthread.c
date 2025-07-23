#include "glthread.h"
#include <stddef.h>

void gldll_init(gldll_t *list, glthread_node_t *head, \
int(*key_match_fn)(void*,void*), int(*key_compare_fn)(void*, void*))
{
    list->head = head;
    list->comparison_fn = key_compare_fn;
    list->key_match = key_match_fn;

}

void gldll_insert(gldll_t *list, glthread_node_t *node)
{
    glthread_node_t *__last = list->head;

    while(__last->right != NULL)
    {
        __last = __last->right;
    }

    __last->right = node;


}