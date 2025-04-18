#include <stdio.h>
#include "stack.h"

void init(stack_t* sp)
{
    sp->top = 0;
}

elem_t pop(stack_t* sp)
{
    if (is_empty(sp))
    {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    return sp->data[--sp->top];
}

void push(stack_t* sp, elem_t val)
{
    if (is_full(sp))
    {
        printf("스택이 꽉찼습니다.\n");
        return;
    }
    sp->data[sp->top++] = val; 
}

int is_empty(stack_t* sp)
{
    return (sp->top == 0);
}

int is_full(stack_t* sp)
{
    return (sp->top == MAX_STACK_SIZE);
}

void peek(stack_t* sp) 
{
    printf("%c\n", sp->data[sp->top - 1]);
}

void print_stack(stack_t* sp)
{

    printf("[");
    if (is_empty(sp))
    {
        printf("]\n");
        return;
    }
    for (int i = 0; i < sp->top; i++)
        printf("%d ", sp->data[i]);
    printf("\b]\n");
}

