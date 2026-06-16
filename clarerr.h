#ifndef CLARERR_H
#define CLARERR_H

typedef enum clarerr_e {
    SUCCESS = 0,

    NULL_REFERENCE, /* A pointer that was passed was NULL */
    INVALID_ARGUMENT, /* An argument that was passed was invalid */
    INVALID_STATE_STRUCT, /* A struct that was passed was in an invalid state */
    UNINITIALIZED_STRUCT, /* A struct that was passed wasn't initialized to {0} */
    FAILED_ALLOCATION, /* An alloc operation failed to allocate the requested memory */
    FAILED_REALLOCATION /* A realloc operation failed, but the original memory is untouched */
} clarerr_t;

#endif /* CLARERR_H */