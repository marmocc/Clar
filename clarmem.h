#ifndef CLARMEM_H
#define CLARMEM_H

#include <stddef.h>
#include <stdbool.h>
#include "clarerr.h"

typedef struct clarmem_s {
    void *data;
    size_t size;
} clarmem_t;

clarmem_t clarmem_new(const size_t size);
clarerr_t clarmem_resize(clarmem_t *mem, const size_t size);
clarerr_t clarmem_write(clarmem_t *mem, const void *src);
clarerr_t clarmem_read(const clarmem_t *mem, void *dst);
clarerr_t clarmem_dispose(clarmem_t *mem);

#endif /* CLARMEM_H */