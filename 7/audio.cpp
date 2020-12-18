#include "audio.h"

#include <iostream>

using namespace std;

Audio::Audio(string titel, int jahr, string interpret, int dauer)
    : Medium(titel, jahr), interpret(interpret), dauer(dauer){};

void Audio::druckeDaten() {
    cout << "Audio(id: " << getId() << ", titel: " << getTitel()
         << ", jahr:" << getJahr() << ", interpret: " << interpret
         << ", dauer:" << dauer << ")" << endl;
}