#pragma once

#include <cstdint>

struct Cell
{
    uint8_t value;
    bool marked;
};

class Board
{
    public:
        Board(const uint8_t* board, const unsigned int rows, const unsigned int cols);
        ~Board();

        inline unsigned int getRows() const;
        inline unsigned int getColumns() const;

        inline const Cell* get(const unsigned int row, const unsigned int col) const;

        bool onDraw(const unsigned int num);

    private:
        inline Cell* getCell(const unsigned int row, const unsigned int col) const;
        inline bool checkCol(const unsigned int col) const;
        inline bool checkRow(const unsigned int row) const;

    private:
        unsigned int rows;
        unsigned int cols;
        Cell* array2D;
};