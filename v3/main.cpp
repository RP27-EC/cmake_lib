#include <iostream>

#include "head.h"

int main()
{
    int a = 20;
    int b = 6;

    std::cout << a << " + " << b << " = " << add(a, b) << std::endl;
    std::cout << a << " - " << b << " = " << sub(a, b) << std::endl;
    std::cout << a << " * " << b << " = " << mult(a, b) << std::endl;
    std::cout << a << " / " << b << " = " << divide(a, b) << std::endl;

    return 0;
}
