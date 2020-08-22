// FILENAME: stack_driver.cpp
// PROGRAMMER: Toan Luong
// DATE: 08/14/2020
// COMPILER: MinGW-w64 GCC
// REQUIRED: dblstk.cpp, dblstk.h
// PURPOSE:
//    Perform 7 demo operations to a double-typed Stack: print, push, pop, capacity, size, copy, equal

#include "dblstk.h"
#include <iostream>

using namespace std;

int main() {
    DoubleStack st1(10);
    DoubleStack st2(10);
    int choice;
    bool stopProgram = false;

    while (!stopProgram) {
        cout << "\n*******************************\n";
        cout << "1 - Display stack 1.\n";
        cout << "2 - Place a double value onto the top of stack 1.\n";
        cout << "3 - Remove a value from the top of stack 1.\n";
        cout << "4 - Check the total capacity stack 1.\n";
        cout << "5 - Check current number of items on stack 1.\n";
        cout << "6 - Copy stack 1 to stack 2.\n";
        cout << "7 - Check to see if the two stacks are equal.\n";
        cout << "8 - Quit.\n";
        cout << "Enter menu selection: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
        case 1:
            if (st1.empty()) {
                cout << "Stack 1 is Empty!\n";
            } else {
                size_t i;
                for (i = 0; i < st1.size(); ++i) {
                    if (i == 0)
                        cout << st1[i];
                    else
                        cout << ", " << st1[i];
                }
                cout << "\n";
            }
            break;
        case 2:
            if (st1.size() == st1.capacity()) {
                cout << "Stack 1 is Full!\n";
            } else {
                double input;
                cout << "Enter a double number: ";
                cin >> input;
                st1.push(input);
                cout << "Added " << input << " to stack 1.\n";
            }
            break;
        case 3:
            if (st1.empty()) {
                cout << "Stack 1 is Empty!\n";
            } else {
                double output;
                st1.pop(output);
                cout << "Popped " << output << " out of stack 1.\n";
            }
            break;
        case 4:
            cout << "Stack 1 Capacity = " << st1.capacity() << endl;
            break;
        case 5:
            cout << "Current Number of Items of Stack 1 = " << st1.size() << endl;
            break;
        case 6:
            st2 = st1;
            cout << "Successfully copied Stack 1 to Stack 2!\n";
            break;
        case 7:
            if (st1 == st2)
                cout << "Stack 1 is Equal to Stack 2!\n";
            else
                cout << "Stack 1 is NOT Equal to Stack 2!\n";
            break;
        case 8:
            cout << "End of Program.\n";
            stopProgram = true;
            break;
        default:
            cout << "Not a Valid Choice. \n";
            cout << "Choose again.\n";
            cin >> choice;
            break;
        }
    }
    return 0;
}