#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListIterator.hpp"
#include "Node.hpp"

namespace fhdo {
namespace pk2 {
class LinkedList;
}  // namespace pk2
}  // namespace fhdo

using fhdo::pk2::LinkedList;

class LinkedList {
   private:
    Node* head;
    Node* tail;

   public:
    LinkedList();
    ~LinkedList();
    LinkedList(LinkedList& list);
    Iterator* iterator();
    int append(const char* text);
    int insert(const char* text, int p);
    int remove(int p);
    const char* get(int p);
    int index_of(const char* text);
    const char* first();
    const char* last();
    void visit_all(void (*work)(const char* t));
};

#endif