#include <stdio.h>
#include <stdlib.h>

typedef int elem_t;
elem_t err_elem;
typedef struct node
{
  elem_t data;
  struct node *next;
}node_t;

node_t* find(node_t* hdr, elem_t e);
void print_list(node_t*);
node_t* insert_frist(node_t*,elem_t);
void insert_after(node_t*, node_t*, elem_t);
node_t* delete_val(node_t* hdr, elem_t e);
void delete_after(node_t*, node_t*);
void free_list(node_t*);




