#include <stdio.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

node_t* insert_first(node_t* hdr, elem_t e)
{
    node_t* p = new_node(e);
    if (hdr == NULL) {
        p->next = p->prev = p;
        return p;
    }

    p->next = hdr;
    p->prev = hdr->prev;
    p->prev->next = p;
    p->next->prev = p;
    return p;
}

node_t* insert_after(node_t* hdr, node_t* prev, elem_t e)
{
    if (hdr == NULL) return new_node(e);
    node_t* p = new_node(e);
    p->next = prev->next;
    p->prev = prev;
    p->prev->next = p;
    p->next->prev = p;
    return hdr;
}

void print_list(node_t* hdr)
{
    if (hdr == NULL) return;

    node_t* p = hdr;
    while (1)
    {
        printf("%3d ->", p->data);
        p = p->next;
        if (p == hdr) break;
    }
    printf("\n");
}

node_t* new_node(elem_t e)
{
    node_t* p = (node_t*)malloc(sizeof(node_t));
    p->prev = p;
    p->next = p;
    p->data = e;
    return p;
}

node_t* find(node_t* hdr, elem_t e)
{
    if (hdr == NULL) return NULL;

    node_t* p = hdr;
    while (1)
    {
        if (p->data == e) break;
        p = p->next;
        if (p == hdr) break;
    }
    return p;
}

node_t* delete_val(node_t* hdr, elem_t e)
{
    if (hdr == NULL) return hdr;
    node_t* p = find(hdr, e);
    if (p == NULL || p->data != e) return hdr;
    if (hdr == p && hdr->next == hdr) {
        free(p);
        return NULL;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;

    node_t* new_head = hdr;
    if (p == hdr) {
        new_head = hdr->next;
    }
    free(p);
    return new_head;
}

void free_list(node_t* hdr)
{
    if (hdr == NULL) return;

    node_t* p = hdr->next;
    while (p != hdr)
    {
        node_t* next = p->next;
        free(p);
        p = next;
    }
    free(hdr);
}

// node_t* delete_first(node_t* hdr)
// {
//     if (!hdr) return NULL;
//     node_t* p = hdr->next;
//     p->prev->next = p->next;
//     p->next->prev = p->prev;
//     return p;
// }

