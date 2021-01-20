#include "audio.h"
#include "bild.h"

int main() {
    int size = 2;
    Medium* bilder[size];
    bilder[0] = new Audio("It means nothing", 2007, "Stereophonics", 229);
    bilder[1] = new Bild("Gebaeude FB Informatik", 2018, "Dortmund");

    for (int i = 0; i < size; i++) {
        bilder[i]->druckeDaten();
    }

    return 0;
}