#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListIterator.hpp"
#include "Node.hpp"

namespace fhdo {
namespace pk2 {
template <typename T>
class LinkedList {
   private:
    Node<T>* head;
    Node<T>* tail;

   public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList() {
        Node<T>* ptr = head;
        Node<T>* del = NULL;

        if (ptr == nullptr) return;

        while (ptr->next != nullptr) {
            del = ptr;
            ptr = ptr->next;
            delete ptr;
        }
    }
    LinkedList(LinkedList<T>& originalList) {
        if (originalList.head == nullptr) {
            head = nullptr;
            return;
        }
        head = new Node<T>(originalList.head->value);
        Node<T>* newPtr =
            head;  // is one before original because next gets set in loop
        Node<T>* originalPtr = originalList.head->next;

        while (originalPtr != nullptr) {
            newPtr->next = new Node<T>(originalPtr->value);
            originalPtr = originalPtr->next;
            newPtr = newPtr->next;
        }
        tail = newPtr;
    }
    fhdo::pk2::Iterator<T>* iterator() {
        return new ListIterator<T>(head);
    }
    int append(T text) {
        Node<T>* temp = new Node<T>(text);

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

    int insert(T text, int p) {
        if (head == nullptr) {
            return append(text);
        }

        Node<T>* prev = nullptr;
        Node<T>* ptr = head;

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

        Node<T>* newElement = new Node<T>(text, ptr);
        if (prev == nullptr) {
            head = newElement;
        } else {
            prev->next = newElement;
        }
    }
    int remove(int p) {
        int i = 0;
        Node<T>* ptr = head;
        Node<T>* prev = nullptr;

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
    T get(int p) {
        int i = 0;
        Node<T>* ptr = head;

        if (ptr == nullptr) return nullptr;

        while (i < p && ptr->next != nullptr) {
            i++;
            ptr = ptr->next;
        }

        return ptr->value;
    }
    int index_of(T value) {
        int i = 0;
        Node<T>* ptr = new Node<T>;
        ptr = head;

        if (ptr == nullptr) return -1;

        while (1) {
            if (strcmp(ptr->value, value) == 0) return i;

            if (ptr->next == nullptr) return -1;
            i++;
            ptr = ptr->next;
        };
    }
    T first() { return head->value; }
    T last() { return tail->value; }
    void visit_all(void (*work)(T t)) {
        Iterator<T>* iter = iterator();

        while (iter->hasNext()) {
            (*work)(iter->next());
        }
    }
};
}  // namespace pk2
}  // namespace fhdo

#endif