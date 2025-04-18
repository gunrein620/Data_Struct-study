typedef int elem_t;

typedef struct node 
{
    elem_t data;
    struct node* next;
} node_t;

node_t* insert_first(node_t*, elem_t);
void insert_after(node_t*, node_t*, elem_t);
void print_list(node_t*);
node_t* find(node_t*, elem_t);
node_t* delete_val(node_t*, elem_t);
void delete_after(node_t*, node_t*);
void free_list(node_t*);