#include "clarmem.h"
#include <stdlib.h>

ClarMem clarmem_init(void) {
    ClarMem newClarMem;
    newClarMem.data = CLARMEM_DEFAULT_DATA;
    newClarMem.size = CLARMEM_DEFAULT_SIZE;
    return newClarMem;
}

ClarErr clarmem_check(const ClarMem *mem) {
    if(mem == NULL) return INVALID_PARAMETER;

    if(mem->data == CLARMEM_DEFAULT_DATA
    || mem->size == CLARMEM_DEFAULT_SIZE)
        return INVALID_STATE;

    return SUCCESS; 
}

inline bool clarmem_is_valid(const ClarMem* mem) {
    return clarmem_check(mem) == SUCCESS;
}

ClarErr clarmem_alloc(ClarMem *mem, size_t size) {
    if(mem == NULL || size == 0)
        return INVALID_PARAMETER;
    if(clarmem_is_valid(mem))
        return ALLOCATION_ON_VALID;

    void *data = malloc(size);
    if(!data) return FAILED_ALLOCATION;
    
    mem->data = data;
    mem->size = size;
    return SUCCESS;
}

ClarErr clarmem_realloc(ClarMem *mem, size_t size) {
    if (mem == NULL || size == 0)
        return INVALID_PARAMETER;
    if(!clarmem_is_valid(mem))
        return REALLOCATION_ON_INVALID;

    void *data = realloc(mem->data, size);
    if (!data) return FAILED_REALLOCATION;

    mem->data = data;
    mem->size = size;
    return SUCCESS;
}

ClarErr clarmem_free(ClarMem *mem) {
    ClarErr err = clarmem_check(mem);
    if(err != SUCCESS) return err;

    free(mem->data);
    mem->data = CLARMEM_DEFAULT_DATA;
    mem->size = CLARMEM_DEFAULT_SIZE;

    return SUCCESS;
}