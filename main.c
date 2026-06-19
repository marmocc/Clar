#include <stdio.h>
#include "clar_memory.h"

int main(void)
{
    clar_fallible_memory test = clar_memory_new(sizeof(int));
    if(test.error != SUCCESS) return test.error;

    clar_fallible_span span = clar_memory_span(&test.value, sizeof(int));

    int source = 5;
    clar_span_write(span.value, &source);

    int destination = 1;
    printf("%d\n", destination);
    clar_span_read(span.value, &destination);
    printf("%d\n", destination);

    clar_fallible_void dis = clar_memory_dispose(&test.value);
    if(dis.error != SUCCESS) return dis.error;

    return 0;
}