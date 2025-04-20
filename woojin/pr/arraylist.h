#include "elem.h"

struct tag
{
    int size;
    elem_t data[100];    
} typedef arrlist_t;

void print_list(arrlist_t*);
void append(arrlist_t*, arrlist_t*);
void add(arrlist_t*);
void common(arrlist_t*, arrlist_t*, arrlist_t*);
void delete_list(arrlist_t*, int);
int sum_list(arrlist_t*);
void reverse_list(arrlist_t*);
int len(arrlist_t*);
void add_list(arrlist_t*, elem_t);
int find(arrlist_t*, elem_t);
