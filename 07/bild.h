#include "medium.h"

class Bild : public Medium {
   private:
    string ort;

   public:
    Bild(string titel, int jahr, string ort);
    void druckeDaten() override;
};
