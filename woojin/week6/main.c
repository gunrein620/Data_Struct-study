#include <stdio.h>
#include "queue.h"

void main(void) 
{
    queue_t q;
    init_queue(&q);
    char op[5];
    int val;

    while (1) 
    {
        print_queue(&q);
        scanf("%s", op);

        if (op[0] == '+')
        {
            scanf("%d", &val);
            enqueue(&q, val);
        } 
        else if (op[0] == '-')
        {
            val = dequeue(&q);
        }
        else if (op[0] == '0')
            break;
    }
}