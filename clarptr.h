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

/* Initialization */
ClarPtr clarptr_init();

/* Construction */
ClarErr clarptr_alloc(ClarPtr* ptr, size_t size);

/* Usage */
ClarErr clarptr_invalid(ClarPtr* ptr);

#define CLARPTR_UNSAFE_WRITE(ptr, type, value) \
    *( (type*) (ptr)->data ) = (value)

#define CLARPTR_UNSAFE_READ(ptr, type) \
    *( (type*) (ptr)->data )
    
ClarErr clarptr_free(ClarPtr* ptr);

#endif /* CLARPTR_H */
