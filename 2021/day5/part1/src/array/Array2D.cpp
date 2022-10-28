#include "Purgato.h"

#include <stdlib.h>

namespace Purgato
{
    template<typename T>
    Array2D<T>::Array2D(const unsigned int rows, const unsigned int cols)
        : Array2D(rows, cols, false) {}

    template<typename T>
    Array2D<T>::Array2D(const unsigned int rows, const unsigned int cols, const bool zeroInit)
        : rows(rows), cols(cols)
    {
        this->length = rows * cols;
        this->data = static_cast<T*>( zeroInit ? calloc(this->length, sizeof(T)) : malloc(sizeof(T), this->length) );
    }

    template<typename T>
    Array2D<T>::~Array2D() { free(this->data); }
};