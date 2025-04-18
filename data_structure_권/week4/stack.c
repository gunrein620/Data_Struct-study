// #include <stdio.h>
// #include "stack.h"

// void init(stack_t* sp)
// {
//     sp->top = 0;
// }

// void push(stack_t* sp, elem_t e)
// {
//     if (is_full(sp))
//     {
//         printf("스택 full, push 실패\n");
//         return;
//     }
//     sp->data[sp->top++] = e;
// }

// int is_full(stack_t* sp)
// {
//     return sp->top == MAX_STACK_SIZE;
// }

// elem_t pop(stack_t* sp) 
// {
//     if (is_empty(sp))
//     {
//         printf("스택 empty, pop 실패\n");
//         return -1;
//     }   
//     return sp->data[--(sp->top)];
// }

// int is_empty(stack_t* sp)
// {
//     return sp->top == 0;
// }

// void print_stack(stack_t* sp)
// {
//     for (int i = 0; i < sp->top; i++)
//         printf("%4s", sp->data[i]);
//     printf("\n");
// }
