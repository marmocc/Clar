#ifndef CLAR_ERROR_H
#define CLAR_ERROR_H

typedef enum {
    SUCCESS = 0,

    NULL_REFERENCE, /* A pointer that was passed was NULL */
    INVALID_ARGUMENT, /* An argument that was passed was invalid */
    INVALID_STATE, /* A struct that was passed was in an invalid state */
    FAILED_ALLOCATION, /* An alloc operation failed to allocate the requested memory */
    FAILED_REALLOCATION /* A realloc operation failed, but the original memory is untouched */
} clar_error;

#define CLAR_FALLIBLE_GENERATE(T, NAME) \
    typedef struct { \
        T value; \
        clar_error error; \
    } clar_fallible_##NAME

typedef struct {
    clar_error error;
} clar_fallible_void;

CLAR_FALLIBLE_GENERATE(void*, voidptr);
CLAR_FALLIBLE_GENERATE(int, int);
CLAR_FALLIBLE_GENERATE(char, char);

#endif /* CLAR_ERROR_H */