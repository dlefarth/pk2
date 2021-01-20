#ifndef ITERATOR_H
#define ITERATOR_H
namespace fhdo {
namespace pk2 {
template <typename T>
class Iterator {
   public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};
}  // namespace pk2
}  // namespace fhdo

#endif