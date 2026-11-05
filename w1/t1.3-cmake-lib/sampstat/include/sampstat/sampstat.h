#ifndef SAMPSTAT_H
#define SAMPSTAT_H

#include <stddef.h>
#include <stdint.h>

/* 一次统计的结果。方差用总体方差（除以 n）。 */
typedef struct {
    int16_t min;
    int16_t max;
    float   mean;
    float   var;
} sampstat_t;

/*
 * 计算采样序列的最小值/最大值/平均值/方差。
 *
 * samples: 采样数组，长度 n
 * out:     结果输出
 *
 * 返回 0 成功；参数非法返回负值（具体值由实现者定义并写进 README）。
 */
int sampstat_compute(const int16_t *samples, size_t n, sampstat_t *out);

#endif /* SAMPSTAT_H */
