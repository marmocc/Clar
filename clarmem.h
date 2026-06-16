#ifndef CLARMEM_H
#define CLARMEM_H

#include <stddef.h>
#include <stdbool.h>
#include "clarerr.h"

#define CLARMEM_DEFAULT_DATA NULL
#define CLARMEM_DEFAULT_SIZE 0

typedef struct ClarMem {
    void* data;
    size_t size;
} ClarMem;

/* Initialization */
ClarMem clarmem_init(void);

/* Usage */
ClarErr clarmem_alloc(ClarMem* mem, const size_t size);
ClarErr clarmem_realloc(ClarMem *mem, const size_t size);
ClarErr clarmem_write(ClarMem* mem, const void* src);
ClarErr clarmem_read(const ClarMem* mem, void* dst);
ClarErr clarmem_free(ClarMem* mem);

#endif /* CLARMEM_H */