#include "medium.h"

int Medium::lastId = 0;

Medium::Medium(string titel, int jar)
    : titel(titel), jahr(jahr), id(++Medium::lastId){};
