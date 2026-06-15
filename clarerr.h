typedef enum ClarErr {
    SUCCESS = 0, // No errors or warnings

    _WARNINGS, // Warnings range start
    _END_WARNINGS, // Warning range end

    _ERRORS, // Errors range start
    ERROR_INVALID_PARAMETER, // A parameter that was passed is invalid
    ERROR_INVALID_STATE, // An object that was passed is in an invalid state
    ERROR_FAILED_ALLOCATION, // An allocation failed to allocate the requested memory
    _END_ERRORS // Errors range end
} ClarErr;