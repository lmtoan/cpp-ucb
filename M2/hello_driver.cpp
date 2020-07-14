// FILENAME:   hello.cpp
// PROGRAMMER: Toan Luong
// DATE:       06/17/2020
// COMPILER:   MinGW-w64 GCC
// REQUIRED:   hello_interface.cpp, hello_interface.h
// PURPOSE:
//	Get user first name and print

#include "hello_interface.h"
#include <string>
using namespace std;

int main() {
    string name = getName();
    printName(name);
}
