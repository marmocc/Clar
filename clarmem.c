#include "clarmem.h"
#include <stdlib.h>
#include <string.h>

static inline bool clarmem_is_valid(const clarmem_t *mem) {
    return mem->size != 0 && mem->data != NULL;
}

clarmem_t clarmem_create(const size_t size) {
    clarmem_t new_clarmem = {0};

    void *data = malloc(size);
    if(!data) return new_clarmem;
    
    new_clarmem.data = data;
    new_clarmem.size = size;
    return new_clarmem;
}

clarerr_t clarmem_resize(clarmem_t *mem, const size_t size) {
    if (mem == NULL || size == 0) return INVALID_PARAMETER;
    if(!clarmem_is_valid(mem)) return INVALID_STATE;

    void *data = realloc(mem->data, size);
    if (!data) return FAILED_REALLOCATION;

    mem->data = data;
    mem->size = size;
    return SUCCESS;
}

clarerr_t clarmem_write(clarmem_t *mem, const void *src) {
    if(mem == NULL || src == NULL) return INVALID_PARAMETER;
    if(!clarmem_is_valid(mem)) return INVALID_STATE;

    memcpy(mem->data, src, mem->size);
    return SUCCESS;
}

clarerr_t clarmem_read(const clarmem_t *mem, void *dst) {
    if(mem == NULL || dst == NULL) return INVALID_PARAMETER;
    if(!clarmem_is_valid(mem)) return INVALID_STATE;

    memcpy(dst, mem->data, mem->size);
    return SUCCESS;
}

clarerr_t clarmem_destroy(clarmem_t *mem) {
    if(mem == NULL) return INVALID_PARAMETER;
    if(!clarmem_is_valid(mem)) return INVALID_STATE;

    free(mem->data);
    mem->data = NULL;
    mem->size = 0;
    return SUCCESS;
}