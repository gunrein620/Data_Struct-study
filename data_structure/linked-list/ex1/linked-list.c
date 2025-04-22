#include <stdio.h>
#include "linked-list.h"


node_n* find(node_n* hdr,elem_t e){
  node_n* p = hdr;
  while (p != NULL)
  {
    if(p->data == e)
    break;
    p = p->next;
  }
  return p;
}

node_n* new_node(elem_t e){
  node_n *p = (node_n*)malloc(sizeof(node_n));
  p->data = e;
  p->next = NULL;
  return p;
}


// 호출부 hdr = insert_frist(hdr, 3);
void insert_frist(node_n* hdr, elem_t e){
  node_n *p = new_node(e);
  p->next = hdr;
  return p;
}


void print_list(node_n* hdr){
  node_n *p = hdr;
  while (p != NULL)
  {
    printf("%d ,", p->data);
    p = p->next;
  }
  printf("%d", p->data);
}

void insert_after(node_n* hdr, node_n *prev, elem_t e){
  node_n *p = new_node(e);
  p->next = prev->next;
  prev->next = p;
}

node_n* find_prev(node_n* hdr, elem_t e){
  
  node_n *p = hdr;
  if (p == NULL) return err_elem;
  while (p->next->data != e)
  {
    p = p->next;
    if (p->next == NULL) return err_elem;
  }
  return p;
}

void delete_after(node_n* hdr, node_n* prev){
  node_n *p = prev->next;
  prev->next = p->next;
  free(p);
}

