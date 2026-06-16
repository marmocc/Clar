#include <stdio.h>
#include "clarmem.h"

int main(void)
{
    ClarMem test = clarmem_init();
    clarmem_alloc(&test, sizeof(int));

    int in = 5;
    clarmem_write(&test, &in);

    int out = 1;
    printf("%d\n", out);
    clarmem_read(&test, &out);
    printf("%d\n", out);
    
    clarmem_free(&test);
}