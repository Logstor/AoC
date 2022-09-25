#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

#include "headers/Config.h"

int countGreaterThanLast(std::ifstream&);

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
        // Count number of lines
        const int greaterThanLast = countGreaterThanLast(file);

        std::cout << "There was " << greaterThanLast << " readings that were greater than the previous" << std::endl;
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
    uint32_t res = 0;
    int32_t last; file >> last;
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