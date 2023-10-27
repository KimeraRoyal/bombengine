//
// Created by s5311430 on 27/10/2023.
//

#include "shader.h"

#include <stdexcept>
#include <vector>

namespace bombengine
{
	Shader::Shader(GLint _type, const std::string& _source)
		: m_attachedProgramId(0),
		m_id(0)
	{
		const GLchar* glSource = _source.c_str();

		m_id = glCreateShader(_type);
		if(!m_id) { throw std::runtime_error("Could not generate Shader."); }

		glShaderSource(m_id, 1, &glSource, nullptr);
		glCompileShader(m_id);

		GLint success;
		glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			GLint maxLength = 0;
			glGetShaderiv(m_id, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(m_id, maxLength, &maxLength, &errorLog[0]);

			throw std::runtime_error(errorLog.data());
		}
	}

	Shader::~Shader()
	{
		Detach();
		glDeleteShader(m_id);
	}

	void Shader::Attach(GLuint _programId)
	{
		Detach();

		glAttachShader(_programId, m_id);
		m_attachedProgramId = _programId;
	}

	void Shader::Detach()
	{
		if(!m_attachedProgramId) { return; }

		glDetachShader(m_attachedProgramId, m_id);
		m_attachedProgramId = 0;
	}
} // bombengine