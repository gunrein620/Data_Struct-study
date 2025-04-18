#include <stdio.h>
#include <stdlib.h>
#include "elem.h"

elem_t err_elem = { -1, -1 };

char* str(elem_t e) {
    static char buf[32];
    sprintf(buf, "(%d,%d)", e.r, e.c);
    return buf;
}
