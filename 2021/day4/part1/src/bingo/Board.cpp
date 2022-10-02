#include "Board.hpp"

#include <stdlib.h>

Board::Board(const uint8_t* board, const unsigned int rows, const unsigned int cols)
    : array2D(board), rows(rows), cols(cols) 
{
    this->colResList = (unsigned int*) calloc(cols, sizeof(unsigned int));
    this->rowResList = (unsigned int*) calloc(rows, sizeof(unsigned int));
}

Board::~Board() 
{ 
    delete[] this->array2D; 
    delete[] this->colResList;
    delete[] this->rowResList;
}

inline unsigned int Board::getRows() const { return this->rows; }
inline unsigned int Board::getColumns() const { return this->cols; }

inline uint8_t Board::get(const unsigned int row, const unsigned int col) const
{
    return this->array2D[row * this->rows + col];
}

bool Board::onDraw(const unsigned int num)
{
    register unsigned int currCol, currRow;
    for (currRow = 0; currRow < this->rows; ++currRow)
    {
        for (currCol = 0; currCol < this->cols; ++currCol)
        {
            // Check if they're equal
            if (this->get(currRow, currCol) == num)
            {
                // Increment res lists and check
                ++this->colResList[currCol];
                ++this->rowResList[currRow];

                if( !(this->colResList[currCol] < this->cols) ||
                    !(this->rowResList[currRow] < this->rows) )
                    return true;

                return false;
            }
        }
    }

    return false;
}