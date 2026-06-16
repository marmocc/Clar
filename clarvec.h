#ifndef CLARVEC_H
#define CLARVEC_H

#include "clarmem.h"

typedef struct ClarVec {
    ClarMem memory;
    size_t stride;
    size_t capacity;
    size_t count;
} ClarVec;

#endif /* CLARVEC */