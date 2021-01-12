#include <stdexcept>

using namespace std;

class empty_stack : public invalid_argument {
   public:
    empty_stack() : invalid_argument("stack is empty"){};
};