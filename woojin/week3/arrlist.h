
typedef int elem_t;
struct tag
{
    int size;
    elem_t numbers[100];
}typedef arrlist_t;

void add_list(arrlist_t*, elem_t);
void insert_list(arrlist_t*, int, elem_t);
elem_t delete_list(arrlist_t*, elem_t);
elem_t update_list(arrlist_t*, int, elem_t);
elem_t get_at(arrlist_t* listp, int index);
int len(arrlist_t* listp);
int find(arrlist_t* listp, elem_t e);
void hap(arrlist_t*, arrlist_t*, arrlist_t*);

