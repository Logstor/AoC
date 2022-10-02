#include "Board.hpp"

#include <stdlib.h>

Board::Board(const uint8_t* board, const unsigned int rows, const unsigned int cols)
    : rows(rows), cols(cols) 
{
}

Board::~Board() 
{ 
    delete[] this->array2D; 
}

inline unsigned int Board::getRows() const { return this->rows; }
inline unsigned int Board::getColumns() const { return this->cols; }

inline const Cell* Board::get(const unsigned int row, const unsigned int col) const
{
    return &this->array2D[row * this->rows + col];
}

inline Cell* Board::getCell(const unsigned int row, const unsigned int col) const
{
    return &this->array2D[row * this->rows + col];
}

inline bool Board::checkCol(const unsigned int col) const
{
    register unsigned int row;
    for (row = 0; row < this->rows; ++row)
    {
        if (!this->getCell(row, col)->marked)
            return false;
    }
    return true;
}

inline bool Board::checkRow(const unsigned int row) const 
{
    register unsigned int col;
    for (col = 0; col < this->cols; ++col)
    {
        if (!this->getCell(row, col)->marked)
            return false;
    }
    return true;
}

bool Board::onDraw(const unsigned int num)
{
    register unsigned int currCol, currRow;
    Cell* currCell;
    for (currRow = 0; currRow < this->rows; ++currRow)
    {
        for (currCol = 0; currCol < this->cols; ++currCol)
        {
            currCell = this->getCell(currRow, currCol);

            // Check if they're equal
            if (currCell->value == num)
            {
                currCell->marked = true;

                return this->checkCol(currCol) || this->checkRow(currRow);
            }
        }
    }

    return false;
}