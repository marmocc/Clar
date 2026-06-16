#include "clarmem.h"
#include <stdlib.h>
#include <string.h>

static inline bool clarmem_is_initialized(const clarmem_t *mem) {
    return mem->size == 0 && mem->data == NULL;
}

static inline bool clarmem_is_valid(const clarmem_t *mem) {
    return mem->size != 0 && mem->data != NULL;
}

clarerr_t clarmem_create(clarmem_t *mem, const size_t size) {
    if (mem == NULL) return NULL_REFERENCE;
    if (size == 0) return INVALID_ARGUMENT;
    if (!clarmem_is_initialized(mem)) return UNINITIALIZED_STRUCT;

    void *data = malloc(size);
    if (!data) return FAILED_ALLOCATION;

    mem->data = data;
    mem->size = size;
    return SUCCESS;
}

clarerr_t clarmem_resize(clarmem_t *mem, const size_t size) {
    if (mem == NULL) return NULL_REFERENCE;
    if (size == 0) return INVALID_ARGUMENT;
    if (!clarmem_is_valid(mem)) return INVALID_STATE_STRUCT;

    void *data = realloc(mem->data, size);
    if (!data) return FAILED_REALLOCATION;

    mem->data = data;
    mem->size = size;
    return SUCCESS;
}

clarerr_t clarmem_write(clarmem_t *mem, const void *src) {
    if(mem == NULL || src == NULL) return NULL_REFERENCE;
    if(!clarmem_is_valid(mem)) return INVALID_STATE_STRUCT;

    memcpy(mem->data, src, mem->size);
    return SUCCESS;
}

clarerr_t clarmem_read(const clarmem_t *mem, void *dst) {
    if(mem == NULL || dst == NULL) return NULL_REFERENCE;
    if(!clarmem_is_valid(mem)) return INVALID_STATE_STRUCT;

    memcpy(dst, mem->data, mem->size);
    return SUCCESS;
}

clarerr_t clarmem_destroy(clarmem_t *mem) {
    if(mem == NULL) return NULL_REFERENCE;
    if(!clarmem_is_valid(mem)) return INVALID_STATE_STRUCT;

    free(mem->data);
    mem->data = NULL;
    mem->size = 0;
    return SUCCESS;
}