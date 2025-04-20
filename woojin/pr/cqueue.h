#include "elem.h"
#define MAX_SIZE 20

struct tag
{
    int rear, front;
    elem_t data[MAX_SIZE];
}typedef cqueue_t;

void init(cqueue_t*);
int is_full(cqueue_t*);
int is_empty(cqueue_t*);
void enqueue(cqueue_t*, elem_t);
elem_t dequeue(cqueue_t*, elem_t);
elem_t peek(cqueue_t*);
void print_cqueue(cqueue_t*);