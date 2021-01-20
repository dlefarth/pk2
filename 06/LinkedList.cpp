#include "LinkedList.h"

#include <string.h>

#include <iostream>
#include <new>

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

int LinkedList::append(const char* text) {
    Node* temp = new Node(text);

    if (head == nullptr) {
        head = temp;
        tail = temp;
        temp = nullptr;
    } else {
        tail->next = temp;
        tail = temp;
    }
    return 1;
}

int LinkedList::insert(const char* text, int p) {
    if (head == nullptr) {
        return append(text);
    }

    Node* prev = new Node;
    Node* ptr = new Node;
    ptr = head;

    int i = 0;
    while (i <= p) {
        prev = ptr;
        if (ptr->next != nullptr) {
            ptr = ptr->next;
            i++;
        } else {
            return append(text);
        }
    }

    Node* newElement = new Node(text, ptr);
    if (prev == nullptr) {
        head = newElement;
    } else {
        prev->next = newElement;
    }
}

int LinkedList::remove(int p) {
    int i = 0;
    Node* ptr = head;
    Node* prev = nullptr;

    if (ptr == nullptr) return 0;

    while (i < p && ptr->next != nullptr) {
        i++;
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == tail && ptr == head) {
        head = nullptr;
        tail = nullptr;
    } else if (ptr == tail) {
        tail = prev;
        prev->next = nullptr;
    } else if (ptr == head) {
        head = ptr->next;
    } else {
        prev->next = ptr->next;
    }

    delete ptr;
    return 1;
}

const char* LinkedList::get(int p) {
    int i = 0;
    Node* ptr = new Node;
    ptr = head;

    if (ptr == nullptr) return nullptr;

    while (i < p && ptr->next != nullptr) {
        i++;
        ptr = ptr->next;
    }

    return ptr->value;
}

int LinkedList::index_of(const char* text) {
    int i = 0;
    Node* ptr = new Node;
    ptr = head;

    if (ptr == nullptr) return -1;

    while (1) {
        if (strcmp(ptr->value, text) == 0) return i;

        if (ptr->next == nullptr) return -1;
        i++;
        ptr = ptr->next;
    };
}

void LinkedList::visit_all(void (*work)(const char* t)) {
    if (head == nullptr) return;

    Node* ptr = new Node;
    ptr = head;

    while (1) {
        (*work)(ptr->value);
        if (ptr->next == nullptr) {
            return;
        }
        ptr = ptr->next;
    }
}

const char* LinkedList::first() { return head->value; }

const char* LinkedList::last() { return tail->value; }

LinkedList::~LinkedList() {
    Node* ptr = head;
    Node* del = NULL;

    if (ptr == nullptr) return;

    while (ptr->next != nullptr) {
        del = ptr;
        ptr = ptr->next;
        delete ptr;
    }
}

LinkedList::LinkedList(LinkedList& originalList) {
    if (originalList.head == nullptr) {
        head = nullptr;
        return;
    }
    head = new Node(originalList.head->value);
    Node* newPtr = head;  // is one before original because next is set
    Node* originalPtr = originalList.head->next;

    while (originalPtr != nullptr) {
        newPtr->next = new Node(originalPtr->value);
        originalPtr = originalPtr->next;
        newPtr = newPtr->next;
    }
    tail = newPtr;
}