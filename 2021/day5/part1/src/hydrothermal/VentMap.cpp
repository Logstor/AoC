#include "VentMap.h"
#include "Purgato.h"

#include <sstream>
#include <iostream>

#define ROWS 1000
#define COLS 1000

inline void makeHorizontalLine(const unsigned int y, const unsigned int start, const unsigned int end, Purgato::Array2D<uint16_t>* data);
inline void makeVerticalLine(const unsigned int x, const unsigned int start, const unsigned int end, Purgato::Array2D<uint16_t>* data);

VentMap::VentMap()
    : data(ROWS, COLS, true) {}

VentMap::VentMap(unsigned int rows, unsigned int cols)
    : data(rows, cols, true) {}

VentMap::~VentMap() {}

void VentMap::putCoordinateSet(CoordinateSet* set)
{
    // Calc the diffs
    const int xDiff = set->x1 - set->x2;
    const int yDiff = set->y1 - set->y2;

    // Ignore if not vertical or horizontal
    if (xDiff && yDiff) return;

    // Put horizontal
    if (xDiff)
        makeHorizontalLine(set->y1, set->x1, set->x2, &this->data);

    // Put vertical
    else
        makeVerticalLine(set->x1, set->y1, set->y2, &this->data);

    // std::cout << '\n' << '(' << set->x1 << ',' << set->y1 << "), (" << set->x2 << ',' << set->y2 << ')' << std::endl;
    // std::cout << this->toString() << std::endl;
}

void VentMap::putCoordinateSets(std::vector<CoordinateSet*>& sets)
{
    // Iterate through sets and put
    for (auto set : sets)
        this->putCoordinateSet(set);
}

unsigned int VentMap::overlappingPoints() const
{
    unsigned int res = 0;
    for (unsigned int row=0; row < this->data.rows; ++row)
        for (unsigned int col=0; col < this->data.cols; ++col)
            if (this->data.get(row, col) > 1)
                ++res;

    return res;
}

std::string VentMap::toString() const
{
    std::stringstream ss;

    for (unsigned int row=0; row < this->data.rows; ++row)
    {
        ss << row << ": ";
        for (unsigned int col=0; col < this->data.cols; ++col)
        {
            unsigned int num = this->data.get(row, col);
            if (num > 0)
                ss << num;
            else ss << ".";
        }
        ss << '\n';
    }

    return ss.str();
}

/// @brief Makes a horizontal line from start to end on the given y coordinate. 
/// @param y The given y coordinate the line goes along.
/// @param start The given start x coordinate.
/// @param end the given end x coordinate.
inline void makeHorizontalLine(const unsigned int y, const unsigned int start, const unsigned int end, Purgato::Array2D<uint16_t>* data)
{
    unsigned int x = start;

    // Mark first point
    data->set(y, x, data->get(y, x) + 1);
    while(x != end)
    {
        // Increment or decrement
        (start < end) ? ++x : --x;

        // Mark point
        data->set(y, x, data->get(y, x) + 1);
    }
}

inline void makeVerticalLine(const unsigned int x, const unsigned int start, const unsigned int end, Purgato::Array2D<uint16_t>* data)
{
    unsigned int y = start;

    // Mark first point
    data->set(y, x, data->get(y, x) + 1);
    while(y != end)
    {
        // Increment or decrement
        (start < end) ? ++y : --y;
        
        // Mark point
        data->set(y, x, data->get(y, x) + 1);
    }
}
