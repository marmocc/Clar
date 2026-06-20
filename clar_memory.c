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

clar_fallible_void clar_memory_zero(clar_memory *memory) {
    if (memory == NULL) return (clar_fallible_void){ .error = NULL_REFERENCE };
    if (!is_valid(memory)) return (clar_fallible_void){ .error = INVALID_STATE };

    memset(memory->data, 0, memory->size);
    return (clar_fallible_void){ .error = SUCCESS };
}

clar_fallible_span clar_memory_span(const clar_memory *memory) {
    if (memory == NULL) return (clar_fallible_span){ .error = NULL_REFERENCE };
    if (!is_valid(memory)) return (clar_fallible_span){ .error = INVALID_STATE };

    clar_span span = { .data = memory->data, .size = memory->size };
    return (clar_fallible_span){ .value = span, .error = SUCCESS };
}

clar_fallible_void clar_memory_resize(clar_memory *memory, const size_t new_size) {
    if (new_size == 0) return (clar_fallible_void){ .error = INVALID_ARGUMENT };
    if (memory == NULL) return (clar_fallible_void){ .error = NULL_REFERENCE };
    if (!is_valid(memory)) return (clar_fallible_void){ .error = INVALID_STATE };

    void *data = realloc(memory->data, new_size);
    if (!data) return (clar_fallible_void){ .error = FAILED_REALLOCATION };
    (*memory) = (clar_memory){ .data = data, .size = new_size };
    return (clar_fallible_void){ .error = SUCCESS };
}

clar_fallible_void clar_memory_dispose(clar_memory *memory) {
    if (memory == NULL) return (clar_fallible_void){ .error = NULL_REFERENCE };
    if (!is_valid(memory)) return (clar_fallible_void){ .error = INVALID_STATE };

    free(memory->data);
    (*memory) = (clar_memory){0};
    return (clar_fallible_void){ .error = SUCCESS };
}