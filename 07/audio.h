#include "medium.h"

class Audio : public Medium {
   private:
    string interpret;
    int dauer;

   public:
    Audio(string titel, int jahr, string interpret, int dauer);
    void druckeDaten() override;
};