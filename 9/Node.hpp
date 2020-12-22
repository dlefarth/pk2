#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T value;
    struct Node<T>* next;
    Node(T value, Node* next = nullptr) : value(value), next(next){};
    Node() : value(nullptr), next(nullptr){};
};

#endif