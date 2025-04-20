#include <stdio.h>
#include "linkedlist.h"

node_t* add(node_t*, node_t*, node_t*);

void main(void)
{
    node_t* f1_hdr = NULL;
    node_t* f2_hdr = NULL;
    node_t* result_hdr = NULL;

    elem_t f1[3] = {{3, 12}, {2, 8}, {1, 0}};
    for (int i = 2; i >= 0; i--)
        f1_hdr = insert_first(f1_hdr, f1[i]);

    elem_t f2[3] = {{8, 12}, {-3, 10}, {10, 6}};
    for (int i = 2; i >= 0; i--)
        f2_hdr = insert_first(f2_hdr, f2[i]);

    print_list(f1_hdr);
    printf("\n");
    print_list(f2_hdr);
    printf("\n");

    result_hdr = add(f1_hdr, f2_hdr, result_hdr);
    print_list(result_hdr);
    
}

node_t* add(node_t* a, node_t* b, node_t* result)
{
    elem_t tmp;
    while (a != NULL && b != NULL) {
        if (a->data.exp == b->data.exp) {
            int sum = a->data.coef + b->data.coef;
            if (sum != 0) {
                tmp.coef = sum;
                tmp.exp = a->data.exp;
            }
            a = a->next;
            b = b->next;
        } else if (a->data.exp > b->data.exp) {
            tmp.coef = a->data.coef;
            tmp.exp = a->data.exp;
            a = a->next;
        } else {
            tmp.coef = b->data.coef;
            tmp.exp = b->data.exp;
            b = b->next;
        }
        result = insert_first(result, tmp);
    }
    if (a == NULL) {
        while (b != NULL)
        {
            result = insert_first(result, b->data);
            b = b->next;
        }
    } else if (b == NULL) {
        while (a != NULL)
        {
            result = insert_first(result, a->data);
            a = a->next;
        }
    }
    return result;
}