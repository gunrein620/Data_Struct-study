#include <stdio.h>
#include "linked_list.h"
#include <stdlib.h>
err_elem = -9999;

node_t* find(node_t* hdr, elem_t e){
  node_t* p = hdr;
  while (p != NULL)
  {
    if (p->data == e)
    break;
    p = p->next;
  }
  return p;
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

node_t* find_prev(node_t* hdr, elem_t e){
  node_t* p = hdr;
  if (p == NULL) return p;
  while (p->next != NULL && p->next->data !=e)
      p = p->next;
  if(p->next == NULL) return NULL;
  return p;    
}

node_t* delete_val(node_t* hdr, elem_t e){
  node_t* p;
  if(hdr == NULL) return hdr;
  if(hdr->data == e)
    return delete_frist(p);
  p = find_prev(hdr, e);
  
  if (p == NULL) return hdr;
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