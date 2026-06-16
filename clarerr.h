#ifndef CLARERR_H
#define CLARERR_H

typedef enum clarerr_e {
    SUCCESS = 0,
    INVALID_PARAMETER, /* A parameter that was passed is invalid for the requested operation */
    INVALID_STATE, /* An object that was passed is in an invalid state for the requested operation */
    FAILED_ALLOCATION, /* An alloc operation failed to allocate the requested memory */
    FAILED_REALLOCATION /* A realloc operation failed, but the original memory is untouched */
} clarerr_t;

#endif /* CLARERR_H */