#include <stdio.h>
#include "linked_list.h"
#include <stdlib.h>
err_elem = -9999;

node_t* find(node_t* hdr, elem_t e){
  if (hdr == NULL) return hdr;
  node_t *p = hdr;
  while (p != NULL && p->data == e)
    p = p->next;
  return hdr;
}
void print_list(node_t* hdr){
  node_t *p = hdr;
  while (p != NULL)     
  {
    printf("%3d ->", p->data);
    p = p->next;
  }
  printf("\n");
}

node_t* insert_frist(node_t* hdr,elem_t e){
   node_t* p = new_node(e);
   p->next = hdr;
   return p;
}


void insert_after(node_t* hdr, node_t* prev, elem_t e){
  node_t *p = new_node(e);
  p->next = prev->next;
  prev->next = p;
}

node_t* delete_val(node_t* hdr, elem_t e){
  node_t* p = hdr;
  if(e == hdr->data)
    delete_frist(hdr); return;
    while (p->data != e)
    {
      if (p->next == NULL) return hdr;
      p = p->next;
    }
    delete_after(hdr, p);
    return hdr;
}

node_t* delete_frist(node_t* hdr){
  node_t *p = hdr;
  p = hdr->next;
  free(hdr);
  return p;
}

void delete_after(node_t* hdr, node_t* prev){
    node_t* p = prev->next;
    prev->next = p->next;
    free(p);
}

void free_list(node_t* hdr){
  node_t* ptr = hdr, *p;
  while (ptr != NULL)
  {
    p = ptr->next;
    free(ptr);
    ptr = p;
  }
}

node_t* new_node(elem_t e){
  node_t *p = (node_t*)malloc(sizeof(node_t));
  p->next = NULL;
  p->data = e;
  return p;
}