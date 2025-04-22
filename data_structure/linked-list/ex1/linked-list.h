#pragma once

typedef int elem_t;
elem_t err_elem;

typedef struct node 
{
  elem_t data;
  struct node *next;
}node_n;

void insert_frist(node_n* hdr, elem_t e);
void print_list(node_n* hdr);
void insert_after(node_n* hdr, node_n *prev, elem_t e);
node_n* delete_val(node_n* hdr, elem_t e);