#include <stdio.h>
#include <string.h>
#include "stack.h"

void delZeroIdx(char* str)
{
    if (strlen(str) == 0)
        return;
    for (int i = 1; i < strlen(str); i++)
    {
        str[i - 1] = str[i];
    }
    str[strlen(str) - 1] = '\0';
}

void main(void)
{
    char buf[MAX_STACK_SIZE];
    int tmp;
    int i = 0;
    stack_t sp;
    elem_t val = 0;

    init(&sp);
    
    printf("후위표기식: ");
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = '\0';
    printf("%-30s", buf);
    print_stack(&sp);

    while (buf[0] != '\0')
    {
        char token = buf[0];
        while (buf[0] == ' ')
            delZeroIdx(buf);
        switch (buf[0])
        {
        case '+':
            tmp = pop(&sp);
            val = pop(&sp) + tmp;
            push(&sp, val);
            break;
        case '-':
            tmp = pop(&sp);
            val = pop(&sp) - tmp;
            push(&sp, val);
            break;
        case '/':
            tmp = pop(&sp);
            val = pop(&sp) / tmp;
            push(&sp, val);
            break;
        case '*':
            tmp = pop(&sp);
            val = pop(&sp) * tmp;
            push(&sp, val);
            break;
        default:
            push(&sp, buf[i] - '0');
            break;
        }
        
        delZeroIdx(buf);
        while (buf[0] == ' ')
            delZeroIdx(buf);
            printf("%-28s%c", buf, token);
        printf("  ");
        print_stack(&sp);
    }
    
}