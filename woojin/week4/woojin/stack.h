#define MAX_STACK_SIZE 50
typedef int elem_t;
struct tag
{
    int top;
    elem_t data[MAX_STACK_SIZE];
} typedef stack_t;

void init(stack_t*);
elem_t pop(stack_t*);
void push(stack_t*, elem_t);
int is_empty(stack_t*);
int is_full(stack_t*);
void peek(stack_t*);
void print_stack(stack_t*);


