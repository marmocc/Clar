#ifndef CLARPTR_H
#define CLARPTR_H

#include <stddef.h>
#include "clarerr.h"

#define CLARPTR_DEFAULT_DATA NULL
#define CLARPTR_DEFAULT_SIZE 0

typedef struct ClarPtr {
    void* data;
    size_t size;
} ClarPtr;

ClarErr clarptr_alloc(ClarPtr* ptr, size_t size);
ClarErr clarptr_free(ClarPtr* ptr);

#endif // CLARPTR_H