#pragma once

#include <cstdint>
#include <vector>

#include "Purgato.h"
#include "CoordinateSet.h"

class VentMap
{
    public:
        VentMap();
        ~VentMap();

        void putCoordinateSet(CoordinateSet* set);
        void putCoordinateSets(std::vector<CoordinateSet*>& sets);
        unsigned int overlappingPoints() const;

    private:
        Purgato::Array2D<uint8_t> data;
};