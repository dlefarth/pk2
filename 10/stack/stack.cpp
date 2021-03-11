#include "stack.h"

#include "empty_stack.hpp"

stack::stack() : top{nullptr} {}

stack::~stack() {
    while (true) {
        try {
            pop();
        } catch (empty_stack &e) {
            break;
        }
    }
}

stack::stack(const stack &orig) : stack{} {
    stack tmp;
    element *ptr = orig.top;
    while (ptr != nullptr) {
        tmp.push(ptr->key);
        ptr = ptr->next;
    }
    int k;
    while ((k = tmp.pop()) != -1) {
        this->push(k);
    }
}

int stack::push(int k) {
    element *neu = new element{k, top};
    if (neu) {
        top = neu;
        return 1;
    } else {
        return 0;
    }
}

int stack::pop() {
    if (top != nullptr) {
        int k = top->key;
        element *tmp = top;
        top = top->next;
        delete tmp;
        return k;
    } else {
        throw empty_stack();
    }
}
