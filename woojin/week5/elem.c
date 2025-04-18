#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elem.h"
char outbuf[10];
char* str(elem_t e) {
    sprintf(outbuf, "(%d, %d)", e.r, e.c);
    return outbuf;
}
