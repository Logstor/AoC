#include "VentMap.h"
#include "Purgato.h"

#define ROWS 10
#define COLS 10

inline void makeHorizontalLine(const unsigned int y, const unsigned int start, const unsigned int end, Purgato::Array2D<uint8_t>* data);
inline void makeVerticalLine(const unsigned int x, const unsigned int start, const unsigned int end, Purgato::Array2D<uint8_t>* data);

VentMap::VentMap()
    : data(ROWS, COLS, true) {}

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
    for (unsigned int row=0; row < ROWS; ++row)
        for (unsigned int col=0; col < COLS; ++col)
            if (this->data.get(row, col) > 1)
                ++res;

    return res;
}

/// @brief Makes a horizontal line from start to end on the given y coordinate. 
/// @param y The given y coordinate the line goes along.
/// @param start The given start x coordinate.
/// @param end the given end x coordinate.
inline void makeHorizontalLine(const unsigned int y, const unsigned int start, const unsigned int end, Purgato::Array2D<uint8_t>* data)
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

inline void makeVerticalLine(const unsigned int x, const unsigned int start, const unsigned int end, Purgato::Array2D<uint8_t>* data)
{
    unsigned int y = start;

    // Mark first point
    data->set(x, y, data->get(y, x) + 1);
    while(y != end)
    {
        // Increment or decrement
        (start < end) ? ++y : --y;
        
        // Mark point
        data->set(x, y, data->get(y, x) + 1);
    }
}
