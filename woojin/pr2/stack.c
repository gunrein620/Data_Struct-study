#include <stdio.h>
#include "stack.h"

void init(stack_t* sp)
{
    sp->top = 0;
}

int is_full(stack_t* sp)
{
    return sp->top == MAX_STACK_SIZE;
}

int is_empty(stack_t* sp)
{
    return sp->top == 0;
}

void push(stack_t* sp, elem_t e)
{
    if (is_full(sp)) {
        printf("꽉참\n");
        return;
    }
    sp->data[sp->top++] = e;
}

elem_t pop(stack_t* sp)
{
    if (is_empty(sp)) {
        printf("비었음\n");
        return err_elem;
    }
    sp->data[--sp->top];
}

elem_t peek(stack_t* sp)
{
    if (is_empty(sp)) {
        printf("비었음\n");
        return err_elem;
    }
    sp->data[sp->top - 1];
}