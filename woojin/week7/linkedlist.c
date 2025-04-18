#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

node_t* insert_first(node_t* hdr, elem_t e)
{
    node_t* p = new_node(e);
}

void insert_after(node_t*, node_t*, elem_t)
{

}

void print_list(node_t*)
{

}

node_t* find(node_t*, elem_t)
{

}

node_t* delete_val(node_t*, elem_t)
{

}

void delete_after(node_t*, node_t*)
{

}

void free_list(node_t*)
{

}

node_t* new_node(elem_t e)
{
    node_t* p = (node_t*)malloc(sizeof(node_t));
    p->data = e;
    p->next = NULL;
    return p;
}