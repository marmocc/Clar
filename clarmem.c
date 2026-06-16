#include "clarmem.h"
#include <stdlib.h>
#include <string.h>

static inline bool clarmem_is_valid(const ClarMem *mem) {
    return mem->size != 0 && mem->data != NULL;
}

ClarErr clarmem_create(ClarMem *mem, const size_t size) {
    if(mem == NULL || size == 0) return INVALID_PARAMETER;

    void *data = malloc(size);
    if(!data) return FAILED_ALLOCATION;
    
    mem->data = data;
    mem->size = size;
    return SUCCESS;
}

ClarErr clarmem_resize(ClarMem *mem, const size_t size) {
    if (mem == NULL || size == 0) return INVALID_PARAMETER;
    if(!clarmem_is_valid(mem)) return INVALID_STATE;

    void *data = realloc(mem->data, size);
    if (!data) return FAILED_REALLOCATION;

    mem->data = data;
    mem->size = size;
    return SUCCESS;
}

ClarErr clarmem_write(ClarMem* mem, const void* src) {
    if(mem == NULL || src == NULL) return INVALID_PARAMETER;
    if(!clarmem_is_valid(mem)) return INVALID_STATE;

    memcpy(mem->data, src, mem->size);
    return SUCCESS;
}

ClarErr clarmem_read(const ClarMem* mem, void* dst) {
    if(mem == NULL || dst == NULL) return INVALID_PARAMETER;
    if(!clarmem_is_valid(mem)) return INVALID_STATE;

    memcpy(dst, mem->data, mem->size);
    return SUCCESS;
}

ClarErr clarmem_destroy(ClarMem *mem) {
    if(mem == NULL) return INVALID_PARAMETER;
    if(!clarmem_is_valid(mem)) return INVALID_STATE;

    free(mem->data);
    mem->data = NULL;
    mem->size = 0;
    return SUCCESS;
}