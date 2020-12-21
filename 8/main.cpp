#include <iostream>
using namespace std;

#include "LinkedList.h"

void print(const char* val) { cout << val << endl; }

int _main() {
    LinkedList list = LinkedList();
    list.append("Hallo");
    list.append("Test");
    list.append("R");
    list.remove(2);

    list.visit_all(print);
    return 0;
}

void ausgabe(const char* text) { std::cout << text << std::endl; }
// Test der LinkedListKlasse
int main() {
    using namespace std;
    LinkedList liste;
    liste.append("Element 1");
    liste.insert("Element 2", 2);
    LinkedList liste2 = liste;
    cout << "Liste:" << endl;
    liste.visit_all(ausgabe);
    liste.remove(2);
    cout << "Liste:" << endl;
    liste.visit_all(ausgabe);
    cout << "Liste2:" << endl;
    liste2.visit_all(ausgabe);
    return 0;
}