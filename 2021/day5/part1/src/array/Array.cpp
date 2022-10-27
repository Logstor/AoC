#include "Purgato.h"

namespace Purgato
{
    template<typename T>
    Array<T>::Array()
        : length(0), data(nullptr) {}

    template<typename T>
    Array<T>::~Array() {}
};
