#pragma once

#include <cstdint>
#include <vector>
#include <memory.h>
#include <string.h>

struct BitSeq
{
    BitSeq(const char bits[33])
        : length(strlen(bits))
    {
        memcpy(this->bits, bits, 33);
    }

    BitSeq(const char bits[33], const unsigned int length)
        : length(length)
    {
        memcpy(this->bits, bits, 33);
    }

    char bits[33];
    unsigned int length;
};

class DiagnosticReport
{
    private:
        struct PowerPair
        {
            char gamma[33];
            char epsilon[33];
        };

    public:
        DiagnosticReport(std::vector<BitSeq>& input)
            : InputBits(input) {}

        ~DiagnosticReport() {}

        void Analyze();
        uint32_t CalcPowerConsumption() const;
        uint32_t CalcLifeSupportRating() const;

        inline int32_t GetGammaRate() const { return this->GammaRate; }
        inline int32_t GetEpsilonRate() const { return this->EpsilonRate; }
        inline bool IsAnalyzed() const { return this->Analyzed; }

    private:
        PowerPair* FindPowerStringPair(const unsigned int bitLength);
        int32_t FindScrubRating() const;
        int32_t FindOxygenGenRating() const;
        char FindMostCommonBit(const unsigned int position, std::vector<const BitSeq*> bitRows) const;
        char FindLeastCommonBit(const unsigned int position, std::vector<const BitSeq*> bitRows) const;

    private:
        std::vector<BitSeq> InputBits;
        bool Analyzed = false;
        int32_t GammaRate       = 0;
        int32_t EpsilonRate     = 0;
        int32_t OxygenGenRating = 0;
        int32_t CO2ScrubRating  = 0;
};