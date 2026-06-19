#ifndef CLARMEM_H
#define CLARMEM_H

#include <stddef.h>
#include "clar_error.h"

typedef struct {
    void *address;
    size_t length;
} clar_span;

CLAR_FALLIBLE_GENERATE(clar_span, span);
clar_fallible_void clar_span_write(clar_span span, const void *source);
clar_fallible_void clar_span_read(const clar_span span, void *destination);

#endif /* CLARMEM_H */