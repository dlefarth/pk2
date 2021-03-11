#include <iostream>
using namespace std;

#include "LinkedList.h"

void print(const char* val) { cout << val << endl; }

int main() {
    LinkedList list = LinkedList();
    list.append("Hallo");
    list.append("Test");
    list.append("R");
    list.remove(2);

    list.visit_all(print);
    return 0;
}
