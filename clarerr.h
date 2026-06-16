typedef enum ClarErr {
    SUCCESS = 0, /* No errors or warnings */

    RANGE_WARNING_START, /* Warnings range start */
    RANGE_WARNING_END, /* Warning range end */

    RANGE_ERROR_START, /* Errors range start */
    ERROR_INVALID_PARAMETER, /* A parameter that was passed is invalid */
    ERROR_INVALID_STATE, /* An object that was passed is in an invalid state */
    ERROR_FAILED_ALLOCATION, /* An allocation failed to allocate the requested memory */
    RANGE_ERROR_END /* Errors range end */
} ClarErr;