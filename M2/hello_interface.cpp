// FILENAME:   hello_interface.cpp
// PROGRAMMER: Toan Luong
// DATE:       06/17/2020
// COMPILER:   MinGW-w64 GCC
// REQUIRED:   hello_interface.h
// PURPOSE:
//  Provide function definitions

#include "hello_interface.h"
#include <iostream>
#include <string>
using namespace std;

string getName() {
    string name;
    cout
        << "Hello world!\n"
        << "What's Your First Name?"
        << endl;
    cin >> name;
    return name;
}

void printName(string name) {
    cout << "First Name is " << name << endl;
}