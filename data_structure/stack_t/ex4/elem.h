#pragma once

typedef struct tag{
  int r;
  int c;
}elem_t;

extern elem_t err_elem;

char *str(elem_t e);

