#ifndef ITERATOR_H
#define ITERATOR_H
namespace fhdo {
namespace pk2 {
class Iterator;
}
}  // namespace fhdo

class fhdo::pk2::Iterator {
   public:
    virtual bool hasNext() = 0;
    virtual const char* next() = 0;
};

#endif