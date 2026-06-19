#include "clar_span.h"
#include <string.h>

clar_fallible_void clar_span_write(clar_span span, const void *source) {
    memcpy(span.address, source, span.length);
    return (clar_fallible_void){ .error = SUCCESS };
}

clar_fallible_void clar_span_read(const clar_span span, void *destination) {
    memcpy(destination, span.address, span.length);
    return (clar_fallible_void){ .error = SUCCESS };
}