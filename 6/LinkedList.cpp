#include "LinkedList.h"

#include <string.h>

#include <iostream>
#include <new>

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

int LinkedList::append(const char* text) {
    list_element* temp = new list_element;
    temp->value = text;
    temp->next = nullptr;

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

int LinkedList::remove(int p) {
    int i = 0;
    list_element* ptr = head;
    list_element* prev = nullptr;

    if (ptr == nullptr) return 0;

    while (i < p && ptr->next != nullptr) {
        i++;
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == tail && ptr == head) {
        head = tail = nullptr;
    } else if (ptr == tail) {
        tail = prev;
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
    list_element* ptr = head;

    if (ptr == nullptr) return nullptr;

    while (i < p && ptr->next != nullptr) {
        i++;
        ptr = ptr->next;
    }

    return ptr->value;
}

int LinkedList::index_of(const char* text) {
    int i = 0;
    list_element* ptr = head;

    if (ptr == nullptr) return -1;

    while(1) {
        if (strcmp(ptr->value, text) == 0) return i;

        if(ptr->next == nullptr) return -1;
        i++;
        ptr = ptr->next;
    };
}

void LinkedList::visit_all(void (*work)(const char* t)) {
    list_element* ptr = head;

    if (ptr == nullptr) return;

    while (1) {
        (*work)(ptr->value);
        if(ptr -> next == nullptr) return;
        ptr = ptr->next;
    }
}

const char* LinkedList::first() { return head->value; }

const char* LinkedList::last() { return tail->value; }

LinkedList::~LinkedList() {
    list_element* ptr = head;
    list_element* del = NULL;

    if (ptr == nullptr) return;

    while (ptr->next != nullptr) {
        del = ptr;
        ptr = ptr->next;
        delete ptr;
    }
}