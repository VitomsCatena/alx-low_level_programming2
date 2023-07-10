#include <stddef.h>

void *_memcpy(void *dest, const void *src, size_t n) {
    char *cdest = dest;
    const char *csrc = src;
    for (size_t i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }
    return dest;
}

