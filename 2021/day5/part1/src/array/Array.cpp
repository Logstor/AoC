#include "Purgato.h"

#include <cstdint>

namespace Purgato
{
    template<typename T>
    Array<T>::Array(const unsigned int length, T* data)
        : data(data), length(length) {}

    template<typename T>
    Array<T>::~Array() {}

    template class Array<uint8_t>;
};
