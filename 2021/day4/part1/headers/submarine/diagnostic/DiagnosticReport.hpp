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
        struct StringPair
        {
            char gamma[33];
            char epsilon[33];
        };

    public:
        DiagnosticReport(std::vector<BitSeq>& input)
            : InputBits(input) {}

        ~DiagnosticReport() {}

        void Analyze();
        uint32_t CalcRes() const;

        inline int32_t GetGammaRate() const { return this->GammaRate; }
        inline int32_t GetEpsilonRate() const { return this->EpsilonRate; }
        inline bool IsAnalyzed() const { return this->Analyzed; }

    private:
        StringPair* FindStringPair(const unsigned int bitLength);

    private:
        std::vector<BitSeq> InputBits;
        bool Analyzed = false;
        int32_t GammaRate = 0;
        int32_t EpsilonRate = 0;
};