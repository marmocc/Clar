#ifndef CLAR_SPAN_H
#define CLAR_SPAN_H

#include <stddef.h>
#include "clar_error.h"

typedef struct {
    void *data;
    size_t size;
} clar_span;

CLAR_FALLIBLE_GENERATE(clar_span, span);
clar_fallible_void clar_span_write(clar_span span, const void *source);
clar_fallible_void clar_span_read(const clar_span span, void *destination);

#endif /* CLAR_SPAN_H */