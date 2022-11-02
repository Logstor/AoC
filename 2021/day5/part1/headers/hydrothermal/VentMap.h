#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include "Purgato.h"
#include "CoordinateSet.h"

class VentMap
{
    public:
        VentMap();
        VentMap(unsigned int rows, unsigned int cols);
        ~VentMap();

        void putCoordinateSet(CoordinateSet* set);
        void putCoordinateSets(std::vector<CoordinateSet*>& sets);
        unsigned int overlappingPoints() const;
        std::string toString() const;

    private:
        Purgato::Array2D<uint16_t> data;
};