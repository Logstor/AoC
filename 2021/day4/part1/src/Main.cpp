#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <array>

#include "Config.h"
#include "Board.hpp"
#include "Bingo.hpp"

int main(int argc, char** argv)
{
    std::cout << "Hello world - This is version: " << day4_VERSION_MAJOR << "." << day4_VERSION_MINOR << std::endl;

    if (argc != 2) { std::cout << "Only takes one file input!" << std::endl; }

    const char* inputFileName = argv[1];

    std::cout << "Using input file: " << inputFileName << std::endl;

    // Open file
    std::fstream input(inputFileName, std::ios_base::in);
    if (!input.is_open())
    {
        std::cout << "File couldn't be opened!" << std::endl;
        return 0;
    }

    // Read draw sequence
    std::vector<unsigned int> drawSeq;
    int currInt;
    while (input >> currInt)
    {
        // Insert into Draw sequence
        drawSeq.push_back(currInt);

        if (input.peek() == ',')
            input.ignore();
        
        else if (input.peek() == '\n')
        {
            input.ignore(); // Then the newline between draws and board is skipped
            break;
        }
    }

    // Read boards
    std::vector<Board*> boards;
    while (!input.eof())    // For every board
    {
        uint8_t numbers[5*5];
        // uint8_t* numbers = (uint8_t*) malloc(sizeof(uint8_t) * 25);
        int row = 0;
        while (!input.eof()) // For every board row
        {
            int col = 0;
            while(!input.eof()) // For every row int
            {
                // Check for newline or space
                const uint8_t currChar = input.peek();
                if (currChar == '\n' || currChar == '\r')
                {
                    input.ignore();
                    if (row == 0 && col == 0) continue;
                    else break;
                }

                if (currChar == ' ')
                {
                    input.ignore();
                    continue;
                }

                // Read next int
                input >> currInt;

                // Insert
                numbers[row * 5 + col] = currInt;

                // Increment col
                ++col;
            }

            // If newline then this board is done
            if (input.eof() || input.peek() == '\n')
            {
                input.ignore();
                break;
            }
            ++row;
        }

        // Create board
        Board* b = new Board(numbers, 5, 5);
        boards.push_back(b);
    };

    // Create bingo game
    const BoardSize boardSize = {5, 5};
    Bingo bingo(boardSize, drawSeq);

    // Insert Boards
    for (Board* board : boards)
        bingo.addBoard(board);

    //TODO: Play the game, and implemented calculating value for AoC
    bingo.play();

    std::cout << bingo.getWinnerScore() << std::endl;

    return 0;
}