#pragma once

#include <cstdint>
#include <vector>

#include "Board.hpp"

/// @brief Symbolizes a board win.
struct Win
{
    /// @brief On what number the board won on.
    const unsigned int winNumber;

    /// @brief The board that won.
    const Board* board;
};

struct BoardSize
{
    uint16_t rows;
    uint16_t cols;
};

class Bingo
{
    public:
        Bingo(const BoardSize boardSize, const std::vector<unsigned int>& draws);
        ~Bingo();

        inline const std::vector<Board*> getBoards() const;
        inline const Board* getWinner() const { return this->winners[0].board; }
        unsigned int getWinnerScore() const;

        void addBoard(Board* board);
        void play();

    private:
        const BoardSize boardSize;
        const std::vector<unsigned int> draws;
        std::vector<Board*> boards;
        std::vector<Win> winners;
};