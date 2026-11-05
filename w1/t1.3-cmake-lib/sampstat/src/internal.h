#ifndef SAMPSTAT_INTERNAL_H
#define SAMPSTAT_INTERNAL_H

/* 库内部用的东西放这里：app 不应该、也不需要看到它。 */

#include <stdint.h>

static inline int32_t abs32(int32_t v)
{
    return v < 0 ? -v : v;
}

#endif /* SAMPSTAT_INTERNAL_H */
