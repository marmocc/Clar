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

/* Construction */
ClarErr clarmem_alloc(ClarMem* mem, size_t size);
ClarErr clarmem_realloc(ClarMem *mem, size_t size);

/* Usage */
ClarErr clarmem_check(const ClarMem* mem);
bool clarmem_is_valid(const ClarMem* mem);
#define CLARMEM_UNSAFE_WRITE(mem, type, value) \
    *( (type*) (mem)->data ) = (value)
#define CLARMEM_UNSAFE_READ(mem, type) \
    *( (type*) (mem)->data )

/* Destruction */
ClarErr clarmem_free(ClarMem* mem);

#endif /* CLARMEM_H */
