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

