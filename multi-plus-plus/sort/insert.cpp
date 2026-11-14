#include "sort.h"
#include "calc.h"
#include <stdio.h>

// 插入排序：把每个数插到前面已经排好的部分里
void insertSort(int *array, int len)
{
    int number = add(1,23);
    printf("number = %d\n", number);
    for (int i = 1; i < len; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}
