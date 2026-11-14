#include <stdio.h>
#include "sort.h"

static void print(const char *title, const int *array, int len)
{
    printf("%s", title);
    for (int i = 0; i < len; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int a1[] = {5, 2, 9, 1, 7, 3};
    int a2[] = {5, 2, 9, 1, 7, 3};
    int len = sizeof(a1) / sizeof(a1[0]);

    print("排序前:   ", a1, len);

    insertSort(a1, len);
    print("插入排序: ", a1, len);

    selectSort(a2, len);
    print("选择排序: ", a2, len);

    return 0;
}
