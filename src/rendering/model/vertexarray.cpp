//
// Created by s5311430 on 20/10/2023.
//

#include "vertexarray.h"

#include <stdexcept>

namespace bombengine
{
	VertexArray::VertexArray(GLenum _drawMode)
		: m_id(0),
		m_drawMode(_drawMode),
		m_dirty(false)
	{
		glCreateVertexArrays(1, &m_id);
		if(!m_id) { throw std::runtime_error("Could not generate Vertex Array Object."); }
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_id);
	}

	void VertexArray::Draw()
	{
		glBindVertexArray(GetID());

		if(m_elementBufferObject)
		{
			glDrawElements(m_drawMode, static_cast<GLsizei>(GetIndexCount()), GL_UNSIGNED_INT, nullptr);
		}
		else
		{
			glDrawArrays(m_drawMode, 0, static_cast<GLsizei>(GetVertexCount()));
		}

		glBindVertexArray(0);
	}

	GLuint VertexArray::GetID()
	{
		if(m_dirty)
		{
			unsigned int attributeIndex = 0;
			for(auto& vertexBufferObject : m_vertexBufferObjects)
			{
				for(auto interleavedSection = 0; interleavedSection < vertexBufferObject->GetInterleavedSectionCount(); interleavedSection++)
				{
					glEnableVertexArrayAttrib(m_id, attributeIndex);
					glVertexArrayAttribFormat(m_id, attributeIndex, static_cast<GLint>(vertexBufferObject->GetInterleavedSectionSize(interleavedSection)), GL_FLOAT, GL_FALSE, vertexBufferObject->GetInterleavedSectionOffset(interleavedSection));
					glVertexArrayVertexBuffer(m_id, attributeIndex, vertexBufferObject->GetID(), 0, static_cast<GLsizei>(vertexBufferObject->GetDataTypeSize() * sizeof(float)));
					attributeIndex++;
				}
			}
			if(m_elementBufferObject) { glVertexArrayElementBuffer(m_id, m_elementBufferObject->GetID()); }

			m_dirty = false;
		}

		return m_id;
	}

	unsigned int VertexArray::GetVertexCount() const
	{
		if(m_vertexBufferObjects.empty()) { return 0; }
		return m_vertexBufferObjects[0]->GetDataCount();
	}

	unsigned int VertexArray::GetIndexCount() const
	{
		if(!m_elementBufferObject) { return 0; }
		return m_elementBufferObject->GetDataCount();
	}
} // bombengine