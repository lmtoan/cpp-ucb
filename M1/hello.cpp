// FILENAME:   hello.cpp
// PROGRAMMER: Toan Luong
// DATE:       06/17/2020
// COMPILER:   MinGW-w64 GCC
// REQUIRED:   hello.cpp
// PURPOSE:
//	Illustrate the basic form of a C++ program.
//	Illustrate the use of // which means what follows is a comment.
//	Illustrate the use of << which is used to output stuff.

#include <iostream> // Allows use of << and >> operators.
using namespace std;

int main(void) {
    const int nameSize = 100;
    char name[nameSize];
    cout
        << "Hello world!\n"
        << "What's Your First Name?"
        << endl;
    cin >> name;
    cout << "Your First Name is " << name << "\n";
    system("pause"); // required by some compilers to keep output window open.
    return 0;
}
