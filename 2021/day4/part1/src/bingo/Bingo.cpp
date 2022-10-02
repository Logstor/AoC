#include "Bingo.hpp"

#include <iostream>

Bingo::Bingo(const BoardSize boardSize, const std::vector<unsigned int>& draws)
    : boardSize(boardSize), draws(draws) {}

Bingo::~Bingo() 
{
    for (Board* board : this->boards)
        delete board;
}

inline const std::vector<Board*> Bingo::getBoards() const { return this->boards; }

inline const Board* Bingo::getWinner() const { return this->winner; }

void Bingo::addBoard(Board* board)
{
    // Make sure board is of correct size
    if (board->getRows() != this->boardSize.rows)
        std::cout << "Rows doesn't match!" << std::endl;
    if (board->getColumns() != this->boardSize.cols)
        std::cout << "Cols doesn't match!" << std::endl;

    // Add board
    this->boards.push_back(board);
}

void Bingo::play()
{
    // Go through every draw
    for (unsigned int draw : this->draws)
    {
        // Go through every board
        for (Board* board : this->boards)
        {
            if (board->onDraw(draw))
            {
                this->winner = board;
                return;
            }
        }
    }
}