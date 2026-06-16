#ifndef CLARERR_H
#define CLARERR_H

typedef enum ClarErr {
    SUCCESS = 0,
    INVALID_PARAMETER, /* A parameter that was passed is invalid */
    INVALID_STATE, /* An object that was passed is in an invalid state */
    FAILED_ALLOCATION, /* An alloc failed to allocate the requested memory */
    FAILED_REALLOCATION /* A realloc failed, but the original memory is untouched */
} ClarErr;

#endif /* CLARERR_H */