#include <stdio.h>
#include "clarmem.h"

int main(void)
{
    clarmem_t test = {0};
    if(clarmem_create(&test, sizeof(int)) != SUCCESS) return 1;

    int in = 5;
    clarmem_write(&test, &in);

    int out = 1;
    printf("%d\n", out);
    clarmem_read(&test, &out);
    printf("%d\n", out);

    clarmem_destroy(&test);
    return 0;
}