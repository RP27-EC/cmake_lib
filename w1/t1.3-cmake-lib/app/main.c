#include <stdio.h>
#include <stdlib.h>

#include "sampstat/sampstat.h"

#define CAP 64

int main(int argc, char **argv)
{
    int16_t buf[CAP];
    size_t n = 0;

    for (int i = 1; i < argc && n < CAP; i++) {
        buf[n++] = (int16_t)atoi(argv[i]);
    }

    if (n == 0) {
        fprintf(stderr, "用法: %s 1 2 3 ...\n", argv[0]);
        return 2;
    }

    sampstat_t st;
    int rc = sampstat_compute(buf, n, &st);
    if (rc != 0) {
        fprintf(stderr, "sampstat_compute 失败: %d\n", rc);
        return 1;
    }

    printf("n=%zu min=%d max=%d mean=%.3f var=%.3f\n",
           n, st.min, st.max, (double)st.mean, (double)st.var);
    return 0;
}
