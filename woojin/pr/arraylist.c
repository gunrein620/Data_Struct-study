#include <stdio.h>
#include "arraylist.h"

void print_list(arrlist_t* list)
{
    printf("[ ");
    for (int i = 0; i < list->size; i++)
        printf("%2d", list->data[list->size]);
    printf(" ]\n");
}

void append(arrlist_t* li1, arrlist_t* li2)
{
    for (int i = 0; i < li2->size; i++) {
        add_list(li1, li2->data[i]);
    }
}

void add(arrlist_t* li)
{
    for (int i = 0; i < li->size; i++)
        for (int j = i + 1; j < li->size; j++)
            if (li->data[i] == li->data[j])
                delete_list(li, j);
}

void common(arrlist_t* li1, arrlist_t* li2, arrlist_t* result)
{
    for (int i = 0; i < li1->size; i++)
    {
        int flag = find(li2, li1->data[i]);
        if (flag != -1)
            result->data[result->size++] = li1->data[i];
    }
}
void delete_list(arrlist_t* li, int idx)
{
    for (int i = idx; i < li->size - 1; i++)
        li->data[i] = li->data[i + 1];
    li->size--;
}

int sum_list(arrlist_t*);
void reverse_list(arrlist_t*);
int len(arrlist_t*);

void add_list(arrlist_t* li, elem_t e)
{
    li->data[li->size++] = e;
}

int find(arrlist_t* li, elem_t e)
{
    for (int i = 0; i < li->size; i++) {
        if (li->data[i] == e)
            return i;
    }
    return -1;
}