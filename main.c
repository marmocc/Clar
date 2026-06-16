#include <stdio.h>
#include "clarmem.h"

int main(void)
{
    ClarMem test = clarmem_init();
    clarmem_alloc(&test, sizeof(int));
    if(clarmem_is_valid(&test)) CLARMEM_UNSAFE_WRITE(&test, int, 5);
    if(clarmem_is_valid(&test)) printf("%d\n", CLARMEM_UNSAFE_READ(&test, int));
    clarmem_free(&test);
}