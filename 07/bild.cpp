#include "bild.h"

#include <iostream>

using namespace std;

Bild::Bild(string titel, int jahr, string ort)
    : Medium(titel, jahr), ort(ort){};

void Bild::druckeDaten() {
    cout << "Bild(id: " << getId() << ", titel: " << getTitel()
         << ", jahr:" << getJahr() << ", ort: " << ort << ")" << endl;
}