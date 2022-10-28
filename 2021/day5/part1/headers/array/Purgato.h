#pragma once

namespace Purgato
{
    /// @brief Base Purgato class.
    template<typename T> class Array
    {
        private:
            Array();
            ~Array();

        public:
            /// @brief Retrieves the length of the array.
            /// @return Length as unsigned int.
            inline unsigned int getLength() const { return this->length; };

        protected:
            T* data;
            /// @brief The length of the array
            const unsigned int length;
    };

    /// @brief 2-Dimensional array lying continuously in memory.
    template<typename T> class Array2D : protected Array<T>
    {
        public:
            Array2D(const unsigned int rows, const unsigned int cols);
            Array2D(const unsigned int rows, const unsigned int cols, const bool zeroInit);
            ~Array2D();

            /// @brief Retrieves copy of the actual value.
            /// @param row The row to retrieve from.
            /// @param col The column to retrieve from.
            /// @return Copy of value.
            inline T get(const unsigned int row, const unsigned int col) const { return this->data[row * this->rows + col]; }

            /// @brief Retrieves a pointer to the value in the array.
            /// @param row The row to retrieve from.
            /// @param col The column to retrieve from.
            /// @return Pointer to value.
            inline T* getP(const unsigned int row, const unsigned int col) const { return &this->data[row * this->rows + col]; }

            /// @brief Sets the value on the given position.
            /// @param row The row to access.
            /// @param col The column to access.
            /// @param value The value to be copied into the array.
            inline void set(const unsigned int row, const unsigned int col, const T &value) { this->data[row * this->rows + col] = value; }

        private:
            const unsigned int rows;
            const unsigned int cols;
    };

};
