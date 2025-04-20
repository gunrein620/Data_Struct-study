#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

void print_list(arrlist_t* li)
{
    printf("[");
    for (int i = 0; i < li->size; i++) {
        printf("%3d,", li->data[i]);
    }
    printf("]\n");
}

arrlist_t* merge(arrlist_t* li1, arrlist_t* li2)
{
    arrlist_t* result = (arrlist_t*)malloc(sizeof(arrlist_t));

    for (int i = 0; i < li1->size; i++)
        add_list(result, li1->data[i]);
    for (int i = 0; i < li2->size; i++)
        add_list(result, li2->data[i]);

    return result;
}

void add(arrlist_t* li1, arrlist_t* li2, arrlist_t* result)
{
    for (int i = 0; i < li1->size; i++)
        for (int j = i + 1; j < li2->size; j++)
            if ()
}

void common(arrlist_t*, arrlist_t*, arrlist_t*)
{

}

void delete_list(arrlist_t* li, int index)
{
    for (int i = index; i <= li->size - 1; i++)
        li->data[i] = li->data[i + 1];
}

void add_list(arrlist_t* li, elem_t e)
{
    li->data[li->size] = e;
}

void insert_list(arrlist_t* li, int index, elem_t e)
{
    if (li == NULL) return;

    for (int i = li->size; i > index; i--) {
        li->data[i] = li->data[i - 1];
    }
    li->data[index] = e;
    li->size++;
}