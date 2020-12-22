#include <iostream>

#include "../7/audio.h"
#include "../7/bild.h"
#include "LinkedList.hpp"

using namespace std;
using namespace fhdo::pk2;

void print(Medium* val) { val->druckeDaten(); }

// Test der LinkedListKlasse
int main() {
    using namespace std;
    LinkedList<Medium*> liste;
    liste.append(new Audio("It means nothing", 2007, "Stereophonics", 229));
    liste.append(new Bild("Gebaeude FB Informatik", 2018, "Dortmund"));

    liste.visit_all(print);
    return 0;
}