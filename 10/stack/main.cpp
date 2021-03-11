#include <iostream>

#include "empty_stack.hpp"
#include "stack.h"

int main() {
    stack s;
    try {
        s.pop();
    } catch (empty_stack& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}