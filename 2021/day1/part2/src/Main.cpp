#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>

#include "headers/Config.h"

int countGreaterThanLast(std::ifstream&);
int countGreaterThanLastWindow(std::ifstream&);

int main(int argc, char** argv)
{
    std::cout << "Hello world - This is version: " << day1_VERSION_MAJOR << "." << day1_VERSION_MINOR << std::endl;

    if (argc != 2) { std::cout << "Only takes one file input!" << std::endl; }

    const char* inputFileName = argv[1];

    std::cout << "Using input file: " << inputFileName << std::endl;

    // Open file
    std::ifstream file(inputFileName, std::ios::in);
    
    if (file.is_open())
    {
        // Count greater than last window
        const int greaterThanLastWindow = countGreaterThanLastWindow(file);
        std::cout << "There was " << greaterThanLastWindow << " read windows that were greater than the previous window" << std::endl;
    }
    else 
    {
        std::cout << "Unable to open input file" << std::endl;
        return 1;
    }

    // Close file
    file.close();

    return 0;
}

int countGreaterThanLast(std::ifstream& file)
{
    // Resulting variable
    uint32_t res = 0;


    int32_t last = 0;
    int32_t curr;
    while(file.peek() != EOF)
    {
        file >> curr;
        
        // Check
        if (curr > last) ++res;

        // Update last
        last = curr;
    }

    return res;
}

int countGreaterThanLastWindow(std::ifstream& file)
{
    // Result
    int res = 0;

    // Vector contained all the values
    std::vector<int32_t> values;
    values.reserve(2001);

    // // Read all ints into vector
    int32_t curr;
    while(file.peek() != EOF)
    {
        file >> curr;
        values.push_back(curr);
    }

    // Calc first window
    int32_t last = 0;
    int i = 0;
    for (i = 0; i < 3; ++i)
    {
        last += values[i];
    }

    // Calculate rest
    while (i < values.size())
    {
        // Go back to start of next window and reset
        curr = 0;
        i -= 2;

        // Calc window
        int end = i + 3;
        for (; i < end; ++i)
        {
            curr += values[i];
        }

        // Compare windows
        if (curr > last) ++res;

        // Update last
        last = curr;
    }

    return res;
}