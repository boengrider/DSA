#include <stddef.h>
//Return codes
typedef enum GLL_OP_RESULT
{
    GLL_OP_RES_REMOVED,
    GLL_OP_RES_EMPTY,
    GLL_OP_RES_NOTENLISTED
    
} GLL_OP_RES_CODE;

//Options
typedef enum GLL_OPTION
{
    GLL_OPTION_TRAVERSE, //Traverse the list in order to determine wheter node is in the list
    GLL_OPTION_ASSUME    //Asume the node is not in the list if both L and R pointers are null
} GLL_OPTION_CODE;

//Structure representing a single node in a list
typedef struct glthread_node_
{
    struct glthread_node_ *left; //Left node
    struct glthread_node_ *right; //Right node
} glthread_node_t;


typedef int(*comparator)(void*,void*);
//Glued linked list
typedef struct gll_
{
    char name[64]; // List name
    glthread_node_t *head; // First node of the list
    comparator key_compare;
    unsigned int offset;

} gll_t;

void gllListInit(gll_t *_list, glthread_node_t *_head, char *_listName, int _nameLen, comparator _c, unsigned int _glueOffset);
void gllListInsertNodeAfter(glthread_node_t *_newNode, glthread_node_t *_afterNode, gll_t *_list);
void gllListAppendNode(glthread_node_t *_newNode, gll_t *_list);
GLL_OP_RES_CODE gllListRemoveNode(gll_t *_list, glthread_node_t *_removedNode, GLL_OPTION_CODE _options);

