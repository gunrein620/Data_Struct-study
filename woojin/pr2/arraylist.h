#pragma once
#include "elem.h"
#define MAX_ARRAY_SIZE 10

struct tag
{
    int size;
    elem_t data[MAX_ARRAY_SIZE];
} typedef arrlist_t;

void print_list(arrlist_t*);
arrlist_t* merge(arrlist_t*, arrlist_t*);
void add(arrlist_t*, arrlist_t*, arrlist_t*);
void common(arrlist_t*, arrlist_t*, arrlist_t*);
void delete_list(arrlist_t*, int);
void add_list(arrlist_t*, elem_t);

