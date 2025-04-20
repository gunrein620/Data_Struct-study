#include <stdio.h>
#include "stack.h"

void init(stack_t* sp)
{
    sp->top = 0;
}

void push(stack_t* sp, elem_t e)
{
    if (is_full(sp)) {
        printf("스택이 꽉 찼습니다.\n");
        return;
    }
    sp->datas[sp->top++] = e;
}

elem_t pop(stack_t* sp) 
{
    if (is_empty(sp)) {
        printf("스택이 비었습니다.\n");
        return err_elem;
    }
    return sp->datas[--sp->top];
}

int is_empty(stack_t* sp)
{
    return sp->top == 0;
}

int is_full(stack_t* sp)
{
    return sp->top == MAX_SIZE;
}

elem_t peek(stack_t* sp)
{
    return sp->datas[sp->top - 1];
}