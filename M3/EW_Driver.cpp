// FILENAME: EW_Driver.cpp
// PROGRAMMER: Toan Luong
// DATE: 07/23/2020
// COMPILER: MinGW-w64 GCC
// REQUIRED: EnglishWeight.cpp, EnglishWeight.h
// PURPOSE:
//    Provide interfaces to enter 2 weights and a constant.
//    Perform 6 demo operations.

#include "EnglishWeight.h"
#include <iostream>

int main() {
    int xp, xo;
    int yp, yo;
    double n;
    std::cout << "Enter 2 weights in pounds and ounces:\n";
    std::cin >> xp >> xo;
    std::cin >> yp >> yo;
    std::cout << "Enter a number constant:\n";
    std::cin >> n;
    EnglishWeight ew1(xp, xo);
    EnglishWeight ew2(yp, yo);
    std::cout << ew1 << " + " << ew2 << " = " << ew1 + ew2 << std::endl;
    std::cout << ew1 << " - " << ew2 << " = " << ew1 - ew2 << std::endl;
    std::cout << ew1 << " / " << ew2 << " = " << ew1 / ew2 << std::endl;
    std::cout << ew1 << " * " << n << " = " << ew1 * n << std::endl;
    std::cout << n << " * " << ew1 << " = " << n * ew1 << std::endl;
    std::cout << ew1 << " / " << n << " = " << ew1 / n << std::endl;
    std::cout << ew2 << " / " << n << " = " << ew2 / n << std::endl;
    return 0;
}
