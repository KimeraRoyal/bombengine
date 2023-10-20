//
// Created by s5311430 on 20/10/2023.
//

#pragma once

#include <vector>

#include <GL/glew.h>

namespace bombengine
{
	struct InterleavedBufferDataSection
	{
		unsigned int m_size;
		unsigned int m_offset;
	};

	template <typename T>
	class Buffer
	{
	private:
		GLuint m_id;

		std::vector<T> m_data;

		unsigned int m_dataTypeSize;
		std::vector<InterleavedBufferDataSection> m_interleavedDataSections;

		bool m_dirty;

		bool CompareDataType(unsigned int _dataTypeSize);
	public:
		Buffer();
		~Buffer();

		void AddValue(T _value);
		void AddValue(const T* _value, unsigned int _dataTypeSize);

		void AddInterleavedSection(unsigned int _size, unsigned int _offset);

		GLuint GetID();

		[[nodiscard]] unsigned int GetDataCount() const { return m_data.size(); }
		[[nodiscard]] unsigned int GetDataTypeSize() const { return m_dataTypeSize; }
		[[nodiscard]] unsigned int GetDataSize() const { return GetDataCount() * GetDataTypeSize(); }

		[[nodiscard]] unsigned int GetInterleavedSectionCount() const;
		[[nodiscard]] unsigned int GetInterleavedSectionSize(unsigned int _index);
		[[nodiscard]] unsigned int GetInterleavedSectionOffset(unsigned int _index);
	};
} // bombengine
