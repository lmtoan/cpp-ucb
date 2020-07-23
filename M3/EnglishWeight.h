// FILENAME: EnglishWeight.h
// PROGRAMMER: Toan Luong
// DATE: 07/23/2020
// COMPILER: MinGW-w64 GCC
// REQUIRED: EnglishWeight.cpp, EW_Driver.cpp
// PURPOSE:
//    Header file for EnglishWeight class.

#ifndef EnglishWeight_H_
#define EnglishWeight_H_
#include <ostream>
class EnglishWeight {
  private:
    int pounds;
    int ounces;

  public:
    EnglishWeight();
    EnglishWeight(int pd, int oc = 0);
    EnglishWeight operator+(const EnglishWeight &w) const;
    EnglishWeight operator-(const EnglishWeight &w) const;
    EnglishWeight operator/(const EnglishWeight &w) const;
    EnglishWeight operator*(double n) const;
    EnglishWeight operator/(double n) const;
    friend EnglishWeight operator*(double m, const EnglishWeight &w) { return w * m; }
    friend std::ostream &operator<<(std::ostream &os, const EnglishWeight &w);
    friend std::istream &operator>>(std::istream &str, EnglishWeight &w);
};
#endif