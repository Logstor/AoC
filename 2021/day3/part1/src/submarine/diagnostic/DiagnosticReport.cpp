#include "DiagnosticReport.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>

DiagnosticReport::StringPair* DiagnosticReport::FindStringPair(const unsigned int bitLength)
{
    // Result string
    StringPair* pair = (StringPair*) malloc(sizeof(StringPair));

    // For every column
    unsigned int zero, one;
    char currBit;
    for (unsigned int i=0; i < bitLength; ++i)
    {
        // Reset
        zero = one = 0;

        // Go through every bit row
        for (BitSeq row : this->InputBits)
        {
            currBit = row.bits[i];

            // Check what kind
            if (currBit == '1')
                ++one;
            else if (currBit == '0')
                ++zero;
            else
                std::cout << "Error! Bit now recognized: " << currBit << std::endl;
        }

        // Set the bit
        if (zero > one)
        {
            pair->gamma[i] = '0';
            pair->epsilon[i] = '1';
        }
        else
        {
            pair->gamma[i] = '1';
            pair->epsilon[i] = '0';
        }
    }

    return pair;
}

void DiagnosticReport::Analyze()
{
    const unsigned int bitLength = this->InputBits[0].length;

    StringPair* pair = FindStringPair(bitLength);

    // Convert to ints
    char* end;
    this->GammaRate = strtoul(pair->gamma, &end, 2);
    this->EpsilonRate = strtoul(pair->epsilon, &end, 2);

    // Clean up
    free(pair);
}

uint32_t DiagnosticReport::CalcRes() const
{
    return (uint32_t) (this->EpsilonRate * this->GammaRate);
}