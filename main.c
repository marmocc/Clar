#include <stdio.h>
#include "clarptr.h"

int main(void)
{
    ClarPtr test;
    clarptr_alloc(&test, sizeof(int));
    CLARPTR_WRITE(&test, int, 5);
    printf("%d\n", CLARPTR_READ(&test, int));
    clarptr_free(&test);
}