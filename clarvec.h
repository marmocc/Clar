#ifndef CLARVEC_H
#define CLARVEC_H

#include "clarmem.h"

typedef struct ClarVec {
    ClarMem mem;
    size_t stride;
    int capacity;
    int count;
} ClarVec;

#endif /* CLARVEC */