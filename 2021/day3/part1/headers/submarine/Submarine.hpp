#pragma once

#include <cstdint>
#include <string>
#include <string_view>

class Submarine
{
    public:
        Submarine(const std::string subName)
            : name(subName), Depth(0), Pos(0) {}

        ~Submarine() {}

        uint32_t Dive(const unsigned int amount);
        uint32_t Ascend(const unsigned int amount);
        uint32_t Forward(const unsigned int amount);
        
        inline uint32_t CalcRes() const { return this->Depth * this->Pos; }
        inline uint32_t GetDepth() const { return this->Depth; }
        inline uint32_t GetPos() const { return this->Pos; }
        inline std::string_view GetName() const { return this->name; }

    private:
        std::string name;
        uint32_t Depth;
        uint32_t Pos;
};