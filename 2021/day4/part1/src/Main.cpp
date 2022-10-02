#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <array>

#include "Config.h"
#include "Submarine.hpp"
#include "DiagnosticReport.hpp"

int main(int argc, char** argv)
{
    std::cout << "Hello world - This is version: " << day4_VERSION_MAJOR << "." << day4_VERSION_MINOR << std::endl;

    if (argc != 2) { std::cout << "Only takes one file input!" << std::endl; }

    const char* inputFileName = argv[1];

    std::cout << "Using input file: " << inputFileName << std::endl;

    // Open file
    FILE* file = fopen(inputFileName, "r");

    // Read each line into vector
    std::vector<BitSeq> bitRows; bitRows.reserve(1001);
    char bitRow[33];
    while (fscanf(file, "%s\n", bitRow) != EOF)
    {
        bitRows.emplace_back(bitRow);
    }

    std::cout << "Capacity: " << bitRows.capacity() << ", Size: " << bitRows.size() << std::endl;

    // Close file
    fclose(file);

    // Create DiagnosticReport
    DiagnosticReport report(bitRows);

    // Analyze
    report.Analyze();

    // Print result
    std::cout << "The total power consumption was: " << report.CalcRes() << std::endl;

    return 0;
}