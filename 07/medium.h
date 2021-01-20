#ifndef MEDIUM_H
#define MEDIUM_H
#include <string>

using namespace std;

class Medium {
   private:
    static int lastId;
    const int id;
    string titel;
    int jahr;

   public:
    Medium(string titel, int jahr);
    int alter() { return 2020 - jahr; };
    int getJahr() { return jahr; };
    string getTitel() { return titel; };
    int getId() { return id; };
    virtual void druckeDaten() = 0;
};

#endif