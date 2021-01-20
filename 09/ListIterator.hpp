#include "Iterator.hpp"
#include "Node.hpp"

namespace fhdo {
namespace pk2 {
template <typename T>
class ListIterator : public fhdo::pk2::Iterator<T> {
   private:
    Node<T>* node;

   public:
    ListIterator(Node<T>* node) : node(node) {}
    bool hasNext() { return node != nullptr; }
    T next() {
        T val = node->value;
        node = node->next;
        return val;
    }
};

}  // namespace pk2
}  // namespace fhdo
