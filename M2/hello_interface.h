// FILENAME:   hello_interface.h
// PROGRAMMER: Toan Luong
// DATE:       06/17/2020
// COMPILER:   MinGW-w64 GCC
// REQUIRED:   hello_interface.cpp
// PURPOSE:
//  Provide forward declarations

#ifndef _HELLO_INTERFACE_
#define _HELLO_INTERFACE_

#include <string>
using namespace std;

string getName();
void printName(string name);

#endif