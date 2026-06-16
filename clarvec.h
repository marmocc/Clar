#ifndef CLARVEC_H
#define CLARVEC_H

#include "clarmem.h"

typedef struct clarvec_s {
    clarmem_t memory;
    size_t stride;
    size_t capacity;
    size_t count;
} clarvec_t;

#endif /* CLARVEC_H */