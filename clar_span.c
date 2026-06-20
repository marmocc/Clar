#include "clar_span.h"
#include "clar_error.h"
#include <stdbool.h>
#include <string.h>

static inline bool is_valid(const clar_span span) {
    return span.size != 0 && span.data != NULL;
}

clar_fallible_void clar_span_write(clar_span span, const void *source) {
    if (source == NULL) return (clar_fallible_void){ .error = NULL_REFERENCE };
    if (!is_valid(span)) return (clar_fallible_void){ .error = INVALID_STATE };

    memcpy(span.data, source, span.size);
    return (clar_fallible_void){ .error = SUCCESS };
}

clar_fallible_void clar_span_read(const clar_span span, void *destination) {
    if (destination == NULL) return (clar_fallible_void){ .error = NULL_REFERENCE };
    if (!is_valid(span)) return (clar_fallible_void){ .error = INVALID_STATE };

    memcpy(destination, span.data, span.size);
    return (clar_fallible_void){ .error = SUCCESS };
}

clar_fallible_span clar_span_offset(const clar_span span, const size_t offset) {
    if (offset == 0) return (clar_fallible_span){ .error = INVALID_ARGUMENT };
    if (offset < span.size) return (clar_fallible_span){ .error = INVALID_ARGUMENT };
    if (!is_valid(span)) return (clar_fallible_span){ .error = INVALID_STATE };

    clar_span new_span = { .data = span.data + offset, .size = span.size - offset };
    return (clar_fallible_span){ .value = new_span, .error = SUCCESS };
}