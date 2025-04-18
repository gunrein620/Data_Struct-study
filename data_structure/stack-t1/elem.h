#pragma once

typedef struct elem_t {
    int r;
    int c;
} elem_t;

extern elem_t err_elem;
char *str(elem_t);

