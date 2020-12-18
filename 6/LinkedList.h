#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct list_element{
    const char* value;
    struct list_element* next;
};

class LinkedList {
    private:
        list_element* head;
        list_element* tail;

    public:
        LinkedList();
        ~LinkedList();
        int append(const char* text);
        int insert(const char* text, int p);
        int remove(int p);
        const char* get(int p);
        int index_of(const char *text);
        const char* first();
        const char* last();
        void visit_all(void (*work)(const char* t));
};

#endif