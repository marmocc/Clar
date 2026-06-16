#include <stdio.h>
#include "clarptr.h"

int main(void)
{
    ClarPtr test = clarptr_init();
    clarptr_alloc(&test, sizeof(int));
    if(!clarptr_invalid(&test)) CLARPTR_UNSAFE_WRITE(&test, int, 5);
    if(!clarptr_invalid(&test)) printf("%d\n", CLARPTR_UNSAFE_READ(&test, int));
    clarptr_free(&test);
}