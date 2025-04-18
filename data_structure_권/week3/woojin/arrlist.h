
typedef int elem_t;
struct tag
{
    int size;
    elem_t numbers[100];
} typedef arrlist_t;

void print_list(arrlist_t* listp);
void append(arrlist_t* left, arrlist_t* right);
void add(arrlist_t* result);
void common(arrlist_t* left, arrlist_t* right, arrlist_t* result);
void delete_list(arrlist_t* left, int index);
int sum_list(arrlist_t* left);
void reverse_list(arrlist_t* left);
int len(arrlist_t* left);
void add_list(arrlist_t* listp, elem_t e);
int find(arrlist_t* listp, elem_t e);

