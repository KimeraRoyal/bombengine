//
// Created by s5311430 on 08/12/2023.
//

#pragma once

#include <vector>

namespace bombengine
{
    class Bitset
    {
    private:
        const unsigned int c_bitSize = sizeof(unsigned int) * 8 - 1;
        const unsigned int c_byteSize = std::bit_width(c_bitSize + 1) - 1;

        std::vector<unsigned int> m_bitArray;

        [[nodiscard]] unsigned int GetBitArrayIndex(const unsigned int _bit) const { return _bit >> c_byteSize; }
        [[nodiscard]] unsigned int GetByteCount() const { return m_bitArray.size() * sizeof(unsigned int); }

        void SetCapacity(unsigned int _capacity);
    public:
        Bitset& operator=(const Bitset& _other);

        void Set(unsigned int _bit);
        void Clear(unsigned int _bit);

        void SetAll();
        void ClearAll();

        [[nodiscard]] bool GetBitSet(unsigned int _bit) const;
    };
} // bombengine
