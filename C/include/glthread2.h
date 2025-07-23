#include <stddef.h>
//Structure representing a single node in a list
typedef struct glthread_node_
{
    struct glthread_node_ *left; //Left node
    struct glthread_node_ *right; //Right node
} glthread_node_t;

typedef struct gll_
{
    char name[64]; // List name
    glthread_node_t *head; // First node of the list
    int (*key_match)(void*, void*);
    int (*comparison_fn)(void*, void*);
    unsigned int offset;

} gll_t;

void gllListInit(gll_t *_list, glthread_node_t *_head, char *_listName, int nameLen);
void gllListInsertNodeAfter(glthread_node_t *_newNode, glthread_node_t *_afterNode);
void gllListAppendNode(glthread_node_t *_newNode, gll_t *_list);
void gllListRemoveNode(gll_t *_list, glthread_node_t *_removedNode);

