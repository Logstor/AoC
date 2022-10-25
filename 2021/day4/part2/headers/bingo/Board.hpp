#pragma once

#include <cstdint>
#include <string>

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

        inline unsigned int getRows() const { return this->rows; }
        inline unsigned int getColumns() const { return this->cols; }
        inline bool isWon() const { return this->m_isWon; }

        inline const Cell* get(const unsigned int row, const unsigned int col) const { return &this->array2D[row * this->rows + col]; }

        std::string toString() const;

        unsigned int sumAllUnmarked() const;
        bool onDraw(const unsigned int num);

    private:
        inline Cell getCell(const unsigned int row, const unsigned int col) const { return this->array2D[row * this->rows + col]; }
        inline Cell* getCellP(const unsigned int row, const unsigned int col) const { return &this->array2D[row * this->rows + col]; }
        bool checkCol(const unsigned int col) const;
        bool checkRow(const unsigned int row) const;

    private:
        bool m_isWon = false;
        unsigned int rows;
        unsigned int cols;
        Cell* array2D;
};