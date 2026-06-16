#ifndef CLARMEM_H
#define CLARMEM_H

#include <stddef.h>
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
ClarErr clarmem_alloc(ClarMem* ptr, size_t size);

/* Usage */
ClarErr clarmem_invalid(ClarMem* ptr);
#define CLARMEM_UNSAFE_WRITE(ptr, type, value) \
    *( (type*) (ptr)->data ) = (value)
#define CLARMEM_UNSAFE_READ(ptr, type) \
    *( (type*) (ptr)->data )

/* Destruction */
ClarErr clarmem_free(ClarMem* ptr);

#endif /* CLARMEM_H */
