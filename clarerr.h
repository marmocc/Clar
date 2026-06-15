typedef enum ClarErr {
    SUCCESS = 0, // No errors or warnings

    _WARNINGS, // Warnings range start
    _END_WARNINGS, // Warning range end

    _ERRORS, // Errors range start
    ERROR_INVALID_PARAMETER, // A parameter that was passed is invalid
    ERROR_FAILED_ALLOCATION, // An allocation failed to allocate the requested memory
    ERROR_INVALID_FREE_OPERATION, // A requested free operation was invalid
    _END_ERRORS // Errors range end
} ClarErr;