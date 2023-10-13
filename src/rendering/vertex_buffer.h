//
// Created by Kimera Royal on 23/06/2023.
//

#pragma once

#include <vector>

#include "GL/glew.h"

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

namespace cpp_engine
{
	class VertexBuffer
	{
	private:
		GLuint m_id;

		std::vector<float> m_data;

		unsigned int m_dataTypeSize;
		std::vector<unsigned int> m_interleavedDataSizes;
		std::vector<unsigned int> m_interleavedDataOffsets;

		bool m_dirty;

		void CompareDataType(unsigned int _dataTypeSize);
	public:
		VertexBuffer();
		~VertexBuffer();

		void AddValue(float _value);
		void AddValue(glm::vec2 _value);
		void AddValue(glm::vec3 _value);
		void AddValue(glm::vec4 _value);
		void AddValue(const float* _value, unsigned int _dataTypeSize);

		void AddInterleavedElement(unsigned int _size, unsigned int _offset);

		[[nodiscard]] GLuint GetID();

		[[nodiscard]] inline unsigned int GetDataCount() const { return m_data.size(); }
		[[nodiscard]] inline unsigned int GetDataTypeSize() const { return m_dataTypeSize; }
		[[nodiscard]] inline unsigned int GetDataSize() const { return GetDataCount() * GetDataTypeSize(); }

		unsigned int GetInterleavedElementCount();
		unsigned int GetInterleavedElementSize(unsigned int _index);
		unsigned int GetInterleavedElementOffset(unsigned int _index);
	};
}
