#include "Iterator.hpp"
#include "Node.hpp"

namespace fhdo {
namespace pk2 {
class ListIterator;
}  // namespace pk2
}  // namespace fhdo

using fhdo::pk2::ListIterator;

class ListIterator : public fhdo::pk2::Iterator {
   private:
    Node* node;

   public:
    ListIterator(Node* node);
    bool hasNext() override;
    const char* next() override;
};
