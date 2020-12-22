#include "ListIterator.hpp"

using fhdo::pk2::ListIterator;

ListIterator::ListIterator(Node* node) : node(node) {}

bool ListIterator::hasNext() { return node != nullptr; }

const char* ListIterator::next() {
    const char* val = node->value;
    node = node->next;
    return val;
}
