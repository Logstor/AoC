#pragma once

#include <cstdint>
#include <vector>

#include "Board.hpp"

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
        inline const Board* getWinner() const { return this->winner; }
        unsigned int getWinnerScore() const;

        void addBoard(Board* board);
        void play();

    private:
        const BoardSize boardSize;
        const std::vector<unsigned int> draws;
        std::vector<Board*> boards;
        Board* winner = nullptr;
        unsigned int latestDraw = -1;
};