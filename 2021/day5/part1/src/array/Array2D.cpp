#include "Purgato.h"

#include <stdlib.h>

namespace Purgato
{
    template<typename T>
    Array2D<T>::Array2D(const unsigned int rows, const unsigned int cols)
        : rows(rows), cols(cols)
    {
        this->length = rows * cols;
        this->data = static_cast<T*>( malloc(sizeof(T), this->length) );
    }

    template<typename T>
    Array2D<T>::~Array2D() { free(this->data); }
};