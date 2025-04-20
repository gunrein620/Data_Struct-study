#include <stdio.h>
#include "elem.h"

elem_t err_elem = {-1, -1};
char buf[30];

char* str(elem_t e)
{    
    sprintf(buf, "(%d, %d)", e.r, e.c);
    return buf;
}

