#ifndef CLARMEM_H
#define CLARMEM_H

#include <stddef.h>
#include <stdbool.h>
#include "clarerr.h"

typedef struct ClarMem {
    void* data;
    size_t size;
} ClarMem;

ClarErr clarmem_create(ClarMem *mem, const size_t size);
ClarErr clarmem_resize(ClarMem *mem, const size_t size);
ClarErr clarmem_write(ClarMem* mem, const void* src);
ClarErr clarmem_read(const ClarMem* mem, void* dst);
ClarErr clarmem_destroy(ClarMem* mem);

#endif /* CLARMEM_H */