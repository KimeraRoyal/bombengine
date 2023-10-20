//
// Created by s5311430 on 20/10/2023.
//

#include "buffer.h"

#include <stdexcept>

namespace bombengine
{
	template<typename T>
	Buffer<T>::Buffer()
		: m_id(0),
		  m_dataTypeSize(0),
		  m_dirty(false)
	{
		glCreateBuffers(1, &m_id);
		if (!m_id) { throw std::runtime_error("Could not generate Buffer Object."); }
	}

	template<typename T>
	Buffer<T>::~Buffer()
	{
		glDeleteBuffers(1, &m_id);
	}

	template<typename T>
	bool Buffer<T>::CompareDataType(const unsigned int _dataTypeSize)
	{
		if(m_dataTypeSize && m_dataTypeSize != _dataTypeSize)
		{
			throw std::runtime_error("Buffer data type mismatch.");
			return false;
		}
		m_dataTypeSize = _dataTypeSize;
		return true;
	}

	template<typename T>
	void Buffer<T>::AddValue(T _value)
	{
		if(!CompareDataType(1)) { return; }
		m_data.push_back(_value);
		m_dirty = true;
	}

	template<typename T>
	void Buffer<T>::AddValue(const T *_value, unsigned int _dataTypeSize)
	{
		CompareDataType(_dataTypeSize);
		for(auto i = 0; i < _dataTypeSize; i++)
		{
			m_data.push_back(_value[i]);
		}
		m_dirty = true;
	}

	template<typename T>
	void Buffer<T>::AddInterleavedSection(unsigned int _size, unsigned int _offset)
	{
		m_interleavedDataSections.emplace_back(_size, _offset);
	}

	template<typename T>
	GLuint Buffer<T>::GetID()
	{
		if(m_dirty)
		{
			glNamedBufferData(m_id, static_cast<GLsizeiptr>(sizeof(T) * m_data.size()), m_data.data(), GL_STATIC_DRAW);
			m_dirty = false;
		}
		return m_id;
	}

	template<typename T>
	unsigned int Buffer<T>::GetInterleavedSectionCount() const
	{
		return !m_interleavedDataSections.empty() ? m_interleavedDataSections.size() : 1;
	}

	template<typename T>
	unsigned int Buffer<T>::GetInterleavedSectionSize(unsigned int _index)
	{
		return !m_interleavedDataSections.empty() ? m_interleavedDataSections[_index].m_size : GetDataCount();
	}

	template<typename T>
	unsigned int Buffer<T>::GetInterleavedSectionOffset(unsigned int _index)
	{
		return !m_interleavedDataSections.empty() ? m_interleavedDataSections[_index].m_offset : 0;
	}

	template class Buffer<unsigned int>;	// Element Buffer Objects
	template class Buffer<float>;			// Vertex Buffer Objects
} // bombengine