#include "clar_memory.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static inline bool is_valid(const clar_memory *memory) {
    return memory->size != 0 && memory->data != NULL;
}

clar_fallible_memory clar_memory_new(const size_t size) {
    if (size == 0) return (clar_fallible_memory){ .error = INVALID_ARGUMENT };

    void *data = malloc(size);
    if (!data) return (clar_fallible_memory){ .error = FAILED_ALLOCATION };
    clar_memory memory = { .data = data, .size = size };
    return (clar_fallible_memory){ .value = memory, .error = SUCCESS };
}

clar_fallible_span clar_memory_span(clar_memory *memory, const size_t length) {
    if (memory == NULL) return (clar_fallible_span){ .error = NULL_REFERENCE };
    if (length == 0) return (clar_fallible_span){ .error = INVALID_ARGUMENT };
    if (!is_valid(memory)) return (clar_fallible_span){ .error = INVALID_STATE };

    size_t actual_length = length < memory->size ? length : memory->size;
    clar_span span = { .data = memory->data, .size = actual_length };
    return (clar_fallible_span){ .value = span, .error = SUCCESS };
}

clar_fallible_void clar_memory_resize(clar_memory *memory, const size_t size) {
    if (memory == NULL) return (clar_fallible_void){ .error = NULL_REFERENCE };
    if (size == 0) return (clar_fallible_void){ .error = INVALID_ARGUMENT };
    if (!is_valid(memory)) return (clar_fallible_void){ .error = INVALID_STATE };

    void *data = realloc(memory->data, size);
    if (!data) return (clar_fallible_void){ .error = FAILED_REALLOCATION };
    (*memory) = (clar_memory){ .data = data, .size = size };
    return (clar_fallible_void){ .error = SUCCESS };
}

clar_fallible_void clar_memory_dispose(clar_memory *memory) {
    if (memory == NULL) return (clar_fallible_void){ .error = NULL_REFERENCE };
    if (!is_valid(memory)) return (clar_fallible_void){ .error = INVALID_STATE };

    free(memory->data);
    (*memory) = (clar_memory){0};
    return (clar_fallible_void){ .error = SUCCESS };
}