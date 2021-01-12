#include <iostream>

#include "empty_stack.hpp"
#include "stack.h"

int main() {
    try {
        stack s* = new stack();
        s->pop();
    } catch (empty_stack& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}