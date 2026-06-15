#include "clarptr.h"
#include <stdlib.h>

ClarErr clarptr_alloc(ClarPtr* ptr, size_t size) {
    if(ptr == NULL || size <= 0)
        return ERROR_INVALID_PARAMETER;

    ptr->data = malloc(size);
    if(!ptr->data) return ERROR_FAILED_ALLOCATION;
    
    ptr->size = size;
    return SUCCESS;
}

ClarErr clarptr_free(ClarPtr* ptr) {
    if(ptr == NULL) return ERROR_INVALID_PARAMETER;

    if(ptr->size <= CLARPTR_DEFAULT_SIZE
    || ptr->data == CLARPTR_DEFAULT_DATA)
        return ERROR_INVALID_FREE_OPERATION;

    free(ptr->data);
    ptr->data = CLARPTR_DEFAULT_DATA;
    ptr->size = CLARPTR_DEFAULT_SIZE;

    return SUCCESS;
}