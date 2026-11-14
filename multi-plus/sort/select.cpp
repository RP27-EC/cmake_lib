#include "sort.h"

// 选择排序：每一轮找出剩下的数里最小的，放到前面
void selectSort(int *array, int len)
{
    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            int tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }
}
