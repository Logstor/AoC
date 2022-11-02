#include "Purgato.h"

#include <stdlib.h>

namespace Purgato
{
    template<typename T>
    Array2D<T>::Array2D(const unsigned int rows, const unsigned int cols)
        : Array2D(rows, cols, false) {}

    template<typename T>
    Array2D<T>::Array2D(const unsigned int rows, const unsigned int cols, const bool zeroInit)
        : Array<T>(
            rows * cols, 
            static_cast<T*>( zeroInit ? calloc(rows*cols, sizeof(T)) : malloc(sizeof(T) * rows*cols) )
        ), 
        rows(rows), 
        cols(cols) {}

    template<typename T>
    Array2D<T>::~Array2D() { free(this->data); }

    template class Array2D<u_int8_t>;
};