#include <stdio.h>
#include "log.h"

void* safe_calloc(size_t count_els, size_t el_size)
{
    void* p = calloc(count_els,  el_size);
    if (!p) {
        LOG_FATAL("Can't get memory !");
    }

    return p;
}

void* safe_realloc(void* ptr, size_t new_size)
{
    void* p = realloc(ptr, new_size);
    if (!p) {
        LOG_FATAL("Can't realloc memory !");
    }

    return p;
}

