typedef struct e
{
    int coef;
    int exp;
} elem_t;

struct node
{
    elem_t data;
    struct node* next;
};
typedef struct node node_t;
void print_list(node_t* hdr);
node_t* find(node_t* hdr, elem_t e);
node_t* insert_first(node_t* hdr, elem_t e);
void insert_after(node_t* hdr, node_t* prev, elem_t e);
node_t* delete_val(node_t* hdr, elem_t e);
node_t* delete_first(node_t* hdr);
void delete_after(node_t* hdr, node_t* prev);
void free_list(node_t* hdr);
node_t* new_node(elem_t e);