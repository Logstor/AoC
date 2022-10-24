#include "Board.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

Board::Board(const uint8_t* board, const unsigned int rows, const unsigned int cols)
    : rows(rows), cols(cols) 
{
    this->array2D = (Cell*) malloc(sizeof(Cell) * rows * cols);

    // Fill Board
    for (unsigned int row=0; row < rows; ++row)
    {
        for (unsigned int col=0; col < cols; ++col)
        {
            this->array2D[row * this->rows + col].marked = false;
            this->array2D[row * this->rows + col].value = board[row * rows + col];
        }
    }
}

Board::~Board() 
{ 
    delete[] this->array2D; 
}

bool Board::checkCol(const unsigned int col) const
{
    unsigned int row;
    for (row = 0; row < this->rows; ++row)
    {
        if (!this->getCell(row, col).marked)
            return false;
    }
    return true;
}

bool Board::checkRow(const unsigned int row) const 
{
    unsigned int col;
    for (col = 0; col < this->cols; ++col)
    {
        if (!this->getCell(row, col).marked)
            return false;
    }
    return true;
}

std::string Board::toString() const
{
    // Create buffer
    std::stringstream ss;

    ss << "--------------------" << std::endl;
    for (unsigned int row=0; row < this->rows; ++row)
    {
        for (unsigned int col=0; col < this->cols; ++col)
        {
            Cell currCell = this->getCell(row, col);
            ss << std::to_string(currCell.value) << " " << std::to_string(currCell.marked) << ",\t";
        }
        ss << std::endl;
    }
    ss << "--------------------" << std::endl;

    // Return as string
    return ss.str();
}

unsigned int Board::sumAllUnmarked() const
{
    unsigned int col, row, sum = 0;
    for (row = 0; row < this->rows; ++row)
    {
        for (col = 0; col < this->cols; ++col)
        {
            if (!this->get(row, col)->marked)
                sum += this->get(row, col)->value;
        }
    }

    return sum;
}

bool Board::onDraw(const unsigned int num)
{
    unsigned int currCol, currRow;
    Cell* currCell;
    for (currRow = 0; currRow < this->rows; ++currRow)
    {
        for (currCol = 0; currCol < this->cols; ++currCol)
        {
            currCell = this->getCellP(currRow, currCol);

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