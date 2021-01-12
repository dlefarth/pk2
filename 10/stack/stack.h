#include <iostream>

class stack {
   private:
    struct element {
        int key;
        element *next;
        ~element() {}
        element(int key, element *ptr) : key{key}, next{ptr} {}
    };

    element *top;

   public:
    stack();
    ~stack();
    stack(const stack &orig);
    int push(int key);
    int pop();
};