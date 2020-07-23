// FILENAME: EnglishWeight.cpp
// PROGRAMMER: Toan Luong
// DATE: 07/23/2020
// COMPILER: MinGW-w64 GCC
// REQUIRED: EnglishWeight.h, EW_Driver.cpp
// PURPOSE:
//    Provide definitions for EnglishWeight class.

#include "EnglishWeight.h"
#include <iostream>

EnglishWeight::EnglishWeight() {
    pounds = ounces = 0;
}
EnglishWeight::EnglishWeight(int h, int m) {
    pounds = h;
    ounces = m;
}
EnglishWeight EnglishWeight::operator+(const EnglishWeight &w) const {
    EnglishWeight sum;
    sum.ounces = ounces + w.ounces;
    sum.pounds = pounds + w.pounds + sum.ounces / 16;
    sum.ounces %= 16;
    return sum;
}
EnglishWeight EnglishWeight::operator-(const EnglishWeight &w) const {
    EnglishWeight diff;
    int tot1, tot2;
    tot1 = w.ounces + 16 * w.pounds;
    tot2 = ounces + 16 * pounds;
    diff.ounces = (tot2 - tot1) % 16;
    diff.pounds = (tot2 - tot1) / 16;
    return diff;
}
EnglishWeight EnglishWeight::operator/(const EnglishWeight &w) const {
    EnglishWeight diff;
    int tot1, tot2;
    tot1 = w.ounces + 16 * w.pounds;
    tot2 = ounces + 16 * pounds;
    diff.ounces = (tot2 / tot1) % 16;
    diff.pounds = (tot2 / tot1) / 16;
    return diff;
}
EnglishWeight EnglishWeight::operator*(double mult) const {
    EnglishWeight result;
    long totalounces = pounds * mult * 16 + ounces * mult;
    result.pounds = totalounces / 16;
    result.ounces = totalounces % 16;
    return result;
}
EnglishWeight EnglishWeight::operator/(double mult) const {
    EnglishWeight result;
    long totalounces = pounds * 16 / mult + ounces / mult;
    result.pounds = totalounces / 16;
    result.ounces = totalounces % 16;
    return result;
}
std::ostream &operator<<(std::ostream &os, const EnglishWeight &w) {
    os << w.pounds << " pounds, " << w.ounces << " ounces";
    return os;
}
std::istream &operator>>(std::istream &str, EnglishWeight &w) {
    str >> w.pounds;
    if (str.get() != '\'') {
        std::cerr << "*** Error extracting EnglishWeight.\n";
        exit(1);
    }
    str >> w.ounces;
    if (str.get() != '"') {
        std::cerr << "*** Error extracting EnglishWeight.\n";
        exit(1);
    }
    return str;
}