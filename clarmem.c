#include "clarmem.h"
#include <stdlib.h>

ClarMem clarmem_init(void) {
    ClarMem newClarMem;
    newClarMem.data = CLARMEM_DEFAULT_DATA;
    newClarMem.size = CLARMEM_DEFAULT_SIZE;
    return newClarMem;
}

ClarErr clarmem_alloc(ClarMem* mem, size_t size) {
    if(mem == NULL || size == 0)
        return ERROR_INVALID_PARAMETER;

    mem->data = malloc(size);
    if(!mem->data) return ERROR_FAILED_ALLOCATION;
    
    mem->size = size;
    return SUCCESS;
}

ClarErr clarmem_invalid(ClarMem *mem) {
    if(mem == NULL) return ERROR_INVALID_PARAMETER;

    if(mem->data == CLARMEM_DEFAULT_DATA
    || mem->size == CLARMEM_DEFAULT_SIZE)
        return ERROR_INVALID_STATE;

    return SUCCESS; 
}

ClarErr clarmem_free(ClarMem* mem) {
    ClarErr err = clarmem_invalid(mem);
    if(err != SUCCESS) return err;

    free(mem->data);
    mem->data = CLARMEM_DEFAULT_DATA;
    mem->size = CLARMEM_DEFAULT_SIZE;

    return SUCCESS;
}
