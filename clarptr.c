#include "clarptr.h"
#include <stdlib.h>

ClarPtr clarptr_init(void) {
    ClarPtr newClarPtr;
    newClarPtr.data = CLARPTR_DEFAULT_DATA;
    newClarPtr.size = CLARPTR_DEFAULT_SIZE;
    return newClarPtr;
}

ClarErr clarptr_alloc(ClarPtr* ptr, size_t size) {
    if(ptr == NULL || size == 0)
        return ERROR_INVALID_PARAMETER;

    ptr->data = malloc(size);
    if(!ptr->data) return ERROR_FAILED_ALLOCATION;
    
    ptr->size = size;
    return SUCCESS;
}

ClarErr clarptr_invalid(ClarPtr *ptr) {
    if(ptr == NULL) return ERROR_INVALID_PARAMETER;

    if(ptr->data == CLARPTR_DEFAULT_DATA
    || ptr->size == CLARPTR_DEFAULT_SIZE)
        return ERROR_INVALID_STATE;

    return SUCCESS; 
}

ClarErr clarptr_free(ClarPtr* ptr) {
    ClarErr err = clarptr_invalid(ptr);
    if(err != SUCCESS) return err;

    free(ptr->data);
    ptr->data = CLARPTR_DEFAULT_DATA;
    ptr->size = CLARPTR_DEFAULT_SIZE;

    return SUCCESS;
}
