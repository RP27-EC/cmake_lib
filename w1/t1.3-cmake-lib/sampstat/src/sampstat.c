#include <sampstat/sampstat.h>
#include "internal.h"

int sampstat_compute(const int16_t *samples, size_t n, sampstat_t *out)
{
    /* TODO 1：参数校验。samples/out 为 NULL 或 n == 0 时，返回什么？
     *         （返回值约定自己定，写进 README） */
    (void)samples;
    (void)n;
    (void)out;

    /* TODO 2：为什么求和要用 int64_t，而不是 int32_t 或 int16_t？
     *         手算一下 32767 * 32767 放进 int16_t 会怎样。 */

    /* TODO 3：填 out->min / max / mean / var。
     *         var 用总体方差：先求 mean，再累加 (x-mean)^2，最后除以 n。 */

    return -1; /* 实现好后改成 0 */
}
