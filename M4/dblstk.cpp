// FILENAME: dblstk.cpp
// PROGRAMMER: Toan Luong
// DATE: 08/14/2020
// COMPILER: MinGW-w64 GCC
// REQUIRED: dblstk.h, stack_driver.cpp
// PURPOSE:
// - Provide definitions for DoubleStack class

#include "dblstk.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

DoubleStack::DoubleStack(size_t capacity) {
    size_t i;
    tos = 0;
    stack_size = capacity;
    data = new double[capacity];
    if (!data) {
        std::cerr << "*** Memory Allocation Failed. \n";
        exit(1);
    }
    for (i = 0; i < capacity; ++i) {
        data[i] = 0;
    }
}

// Copy Constructor.

DoubleStack::DoubleStack(const DoubleStack &rhs) {
    size_t i;
    stack_size = rhs.stack_size;
    data = new double[rhs.stack_size];
    if (!data) {
        std::cerr << "*** Memory Allocation Failed. \n";
        exit(1);
    }
    for (i = 0; i < rhs.stack_size; ++i) {
        data[i] = rhs.data[i];
    }
    tos = rhs.tos;
}

// Destructor.

DoubleStack::~DoubleStack(void) {
    delete data;
    stack_size = 0;
    tos = 0;
}

// Assignment operator=.

DoubleStack &DoubleStack::operator=(DoubleStack &rhs) {
    size_t i;
    if (this == &rhs) return *this;
    if (stack_size != rhs.stack_size) {
        delete data; // Deallocate current space.
        data = new double[rhs.stack_size];
        if (!data) {
            std::cerr << "*** Memory Allocation Failed. \n";
            exit(1);
        }
        stack_size = rhs.stack_size;
    }
    for (i = 0; i < stack_size; ++i) {
        data[i] = rhs.data[i];
    }
    tos = rhs.tos;
    return *this;
}

// Add item to stack, making it the topmost item.
// Return value 1=success/0=failure.

int DoubleStack::push(double &item) {
    if (tos < stack_size) {
        data[tos++] = item;
        return 1;
    }
    return 0;
}

// Remove top item from stack and return it in item.
// Return value 1=success/0=failure.

int DoubleStack::pop(double &item) {
    if (empty()) return 0;
    item = data[--tos];
    return 1;
}

// Determine if the stack is empty.
// Return value 1=empty/0=non-empty.

int DoubleStack::empty(void) {
    return tos == 0;
}

// Inquire the capacity of the stack.

size_t DoubleStack::capacity(void) {
    return stack_size;
}

// Inquire the number of items on the stack.

size_t DoubleStack::size(void) {
    return tos;
}

// Compare 2 stacks to see if the contain the same data.

int DoubleStack::operator==(DoubleStack &rhs) {
    size_t i;
    if (stack_size != rhs.stack_size) return 0;
    for (i = 0; i < stack_size; ++i) {
        if (data[i] != rhs.data[i]) return 0;
    }
    return 1;
}

double &DoubleStack::operator[](long subscript) {
    if (subscript < 0 || subscript > (stack_size - 1)) {
        std::cerr << "*** Out of range subscript = "
                  << subscript << std::endl;
        exit(1);
    }
    return data[subscript];
}