//
// Created by s5311430 on 08/12/2023.
//

#include "bitset.h"

namespace bombengine
{
    Bitset& Bitset::operator=(const Bitset& _other)
    {
        if(this != &_other)
        {
            m_bitArray = _other.m_bitArray;
        }
        return *this;
    }

    void Bitset::Set(const unsigned int _bit)
    {
        const unsigned int bitArrayIndex = GetBitArrayIndex(_bit);
        if(bitArrayIndex >= m_bitArray.size()) { SetCapacity(bitArrayIndex + 1); }
        m_bitArray[bitArrayIndex] |= 0x1 << (_bit & c_bitSize);
    }

    void Bitset::Clear(const unsigned int _bit)
    {
        const unsigned int bitArrayIndex = GetBitArrayIndex(_bit);
        if(bitArrayIndex >= m_bitArray.size()) { return; }
        m_bitArray[bitArrayIndex] &= ~(0x1 << (_bit & c_bitSize));
    }

    void Bitset::SetAll()
    {
        m_bitArray = std::vector<unsigned int>(m_bitArray.size(), 0x0 - 0x1);
    }

    void Bitset::ClearAll()
    {
        m_bitArray = std::vector<unsigned int>(m_bitArray.size(), 0x0);
    }

    bool Bitset::GetBitSet(const unsigned int _bit) const
    {
        const unsigned int bitArrayIndex = GetBitArrayIndex(_bit);
        if(bitArrayIndex >= m_bitArray.size()) { return false; }
        return m_bitArray[bitArrayIndex] & (0x1 << (_bit & c_bitSize));
    }

    void Bitset::SetCapacity(const unsigned int _capacity)
    {
        if(m_bitArray.capacity() == _capacity) { return; }
        m_bitArray.resize(_capacity, 0x0);
    }
} // bombengine