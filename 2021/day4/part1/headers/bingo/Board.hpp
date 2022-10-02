#pragma once

#include <cstdint>

class Board
{
    public:
        Board(const uint8_t* board, const unsigned int rows, const unsigned int cols);
        ~Board();

        inline unsigned int getRows() const;
        inline unsigned int getColumns() const;

        inline uint8_t get(const unsigned int row, const unsigned int col) const;

        bool onDraw(const unsigned int num);

    private:
        unsigned int rows;
        unsigned int cols;
        unsigned int* colResList;
        unsigned int* rowResList;
        const uint8_t* array2D;
};