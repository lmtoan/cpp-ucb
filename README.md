# C++ Berkeley Course

## Useful Links

https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/
- When the compiler compiles a multi-file program, it may compile the files in any order.

https://www.learncpp.com/cpp-tutorial/header-guards/
- Header guards prevent codes from showing up in a few times

https://stackoverflow.com/questions/48290197/ostream-in-class-does-not-have-a-type
- `using namespace std` is bad practice

Command-line arguments: https://stackoverflow.com/questions/50021775/command-line-arguments-to-execute-a-c-program

Read a file line by line
```cpp
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
    std::ifstream input(argv[1]);
    if (!input.is_open())
        std::perror("is_open() returned false. error state");
    int xp, xo;
    int yp, yo;
    double n;
    input >> xp >> xo;
    input >> yp >> yo;
    input >> n;
}
```

Declarations (in header files) != Definitions (in cpp files): https://www.cplusplus.com/forum/beginner/263131/

Type Casting: http://www.cplusplus.com/doc/tutorial/typecasting/
- Done by constructor
- Done by assignment
- Done by type-cast (to basic types)

https://www.educative.io/edpresso/pass-by-value-vs-pass-by-reference
- Pass by value vs. pass by reference
- Pass by value if the function does not want to modify the parameter and the value is cheap to copy (int, double, float, char, bool, etc... Notice that std::string, std::vector, and the rest of the containers in the standard library are NOT)
- Pass by const pointer if the value is expensive to copy and the function does not want to modify the value pointed to and NULL is a value that the function handles.
- Pass by non-const pointer if the value is expensive to copy and the function wants to modify the value pointed to and NULL is a value that the function handles.
- Pass by const reference when the value is expensive to copy and the function does not want to modify the value referred to and NULL would not be a valid value if a pointer was used instead.
- Pass by non-const reference when the value is expensive to copy and the function wants to modify the value referred to and NULL would not be a valid value if a pointer was used instead.

https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html
- Pointers vs. Reference
