//Structure representing a single node in a list
typedef struct glthread_node_
{
    struct glthread_node_ *left; //Left node
    struct glthread_node_ *right; //Right node
} glthread_node_t;

typedef struct gldll_
{
    char name[64]; // List name
    glthread_node_t *head; // First node of the list
    int (*key_match)(void*, void*);
    int (*comparison_fn)(void*, void*);
    unsigned int offset;

} gldll_t;

void gldll_init(gldll_t *list, glthread_node_t *head, int(*key_match_fn)(void*,void*), int(*key_compare_fn)(void*, void*));
void gldll_insert(gldll_t *list, glthread_node_t *node);

