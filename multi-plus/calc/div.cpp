#include "calc.h"

int divide(int a, int b)
{
    if (b == 0) {
        return 0;  // 除数为 0 时返回 0，避免程序崩溃
    }
    return a / b;
}
