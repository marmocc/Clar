#ifndef CLAR_MEMORY_H
#define CLAR_MEMORY_H

#include <stddef.h>
#include "clar_error.h"
#include "clar_span.h"

typedef struct {
    void *data;
    size_t size;
} clar_memory;

CLAR_FALLIBLE_GENERATE(clar_memory, memory);
clar_fallible_memory clar_memory_new(const size_t size);
clar_fallible_void clar_memory_zero(clar_memory *memory);
clar_fallible_span clar_memory_span(const clar_memory *memory);
clar_fallible_void clar_memory_resize(clar_memory *memory, const size_t new_size);
clar_fallible_void clar_memory_dispose(clar_memory *memory);

#endif /* CLAR_MEMORY_H */