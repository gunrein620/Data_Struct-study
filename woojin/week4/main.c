#include <stdio.h>
#include <string.h>
#include "stack.h"

// void main(void)
// {
//     stack_t s;
//     init(&s);
//     char op[5];
//     int val;
    
//     while (1)
//     {
//         print_stack(&s);
//         scanf("%s", op);
//         if (op[0] == '+')
//         {
//             scanf("%d", &val);
//             push(&s, val);
//         }
//         else if (op[0] == '-')
//         {
//             val = pop(&s);
//         }
//         else if (op[0] == '0')
//             break;
//     }
    
// }

// int check_matching(char*);

// int main(void)
// {
//     while (1)
//     {
//         char line[30];
//         fgets(line, sizeof(line), stdin);
    
//         if (check_matching(line))
//             printf("%s 괄호검사 성공\n", line);
//         else
//             printf("%s 괄호검사 실패\n", line);
//     }
    
//     return 0;
// }

// int is_open(char ch) 
// {
//     return (ch == '(' || ch == '{' || ch == '[');
// }

// int is_closing(char ch) 
// {
//     return (ch == ')' || ch == '}' || ch == ']');
// }

// int matching(char open_ch, char ch) 
// {
//     return (open_ch == ch ? 1 : -1);
// }

// int check_matching(char* in)
// {
//     stack_t s;
//     elem_t ch, open_ch;
//     int n = strlen(in);
//     init(&s);

//     for (int i = 0; i < n; i++)
//     {
//         ch = in[i];
//         if (is_open(ch))
//             push(&s, ch);
//         else if (is_closing(ch))
//         {
//             if (is_empty(&s)) return 0;
//             open_ch = pop(&s);
//             if (!matching(open_ch, ch))
//                 return 0;
//         }
//         else
//             continue;
//         printf("%20s", in + i);
//         print_stack(&s);
//     }

//     if (!is_empty(&s)) return 0;
//     return 1;
// }