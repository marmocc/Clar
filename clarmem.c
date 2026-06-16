#include "clarmem.h"
#include <stdlib.h>

ClarMem clarmem_init(void) {
    ClarMem newClarMem;
    newClarMem.data = CLARMEM_DEFAULT_DATA;
    newClarMem.size = CLARMEM_DEFAULT_SIZE;
    return newClarMem;
}

ClarErr clarmem_alloc(ClarMem* ptr, size_t size) {
    if(ptr == NULL || size == 0)
        return ERROR_INVALID_PARAMETER;

    ptr->data = malloc(size);
    if(!ptr->data) return ERROR_FAILED_ALLOCATION;
    
    ptr->size = size;
    return SUCCESS;
}

ClarErr clarmem_invalid(ClarMem *ptr) {
    if(ptr == NULL) return ERROR_INVALID_PARAMETER;

    if(ptr->data == CLARMEM_DEFAULT_DATA
    || ptr->size == CLARMEM_DEFAULT_SIZE)
        return ERROR_INVALID_STATE;

    return SUCCESS; 
}

ClarErr clarmem_free(ClarMem* ptr) {
    ClarErr err = clarmem_invalid(ptr);
    if(err != SUCCESS) return err;

    free(ptr->data);
    ptr->data = CLARMEM_DEFAULT_DATA;
    ptr->size = CLARMEM_DEFAULT_SIZE;

    return SUCCESS;
}
