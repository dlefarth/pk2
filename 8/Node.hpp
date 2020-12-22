#ifndef NODE_H
#define NODE_H

struct Node {
    const char* value;
    struct Node* next;
    Node(const char* value, Node* next = nullptr) : value(value), next(next){};
    Node() : value(nullptr), next(nullptr){};
};

#endif