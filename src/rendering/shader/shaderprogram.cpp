//
// Created by s5311430 on 27/10/2023.
//

#include "shaderprogram.h"

#include <vector>

#include <glm/gtc/type_ptr.hpp>

namespace bombengine
{
	ShaderProgram::ShaderProgram()
		: m_id(0),
		m_attributeCount(0)
	{
		m_id = glCreateProgram();

		BindAttribute("in_Position");
		BindAttribute("in_Texcoord");
		BindAttribute("in_Normal");
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(m_id);
	}

	void ShaderProgram::Link()
	{
		glLinkProgram(m_id);

		GLint success;
		glGetProgramiv(m_id, GL_LINK_STATUS, &success);
		assert(success);

		AssignUniformKeys();
	}

	void ShaderProgram::BindAttribute(const std::string &_attribute)
	{
		glBindAttribLocation(m_id, m_attributeCount++, _attribute.c_str());
	}

	void ShaderProgram::AssignUniformKeys()
	{
		GLint activeUniforms = 0;
		glGetProgramInterfaceiv(m_id, GL_UNIFORM, GL_ACTIVE_RESOURCES, &activeUniforms);

		std::vector<GLchar> nameData;
		std::string uniformName;
		GLenum uniformProperties[] = { GL_NAME_LENGTH };
		GLint uniformValues[] = { 0 };

		for(GLint uniformIndex = 0; uniformIndex < activeUniforms; uniformIndex++)
		{
			glGetProgramResourceiv(m_id, GL_UNIFORM, uniformIndex, 1, uniformProperties, 1, nullptr, uniformValues);

			nameData.resize(uniformValues[0]);
			glGetProgramResourceName(m_id, GL_UNIFORM, uniformIndex, static_cast<GLint>(nameData.size()), nullptr, nameData.data());

			uniformName = std::string(static_cast<char*>(nameData.data()), nameData.size() - 1);
			const size_t key = std::hash<std::string>()(uniformName);
			m_uniformLocations.insert(std::make_pair(key, uniformIndex));
		}
	}

	void ShaderProgram::SetUniform(GLint _uniformLocation, float _value) const
	{
		glProgramUniform1fv(m_id, _uniformLocation, 1, &_value);
	}

	void ShaderProgram::SetUniform(GLint _uniformLocation, const glm::vec2 &_value) const
	{
		glProgramUniform2fv(m_id, _uniformLocation, 1, glm::value_ptr(_value));
	}

	void ShaderProgram::SetUniform(GLint _uniformLocation, const glm::vec3 &_value) const
	{
		glProgramUniform3fv(m_id, _uniformLocation, 1, glm::value_ptr(_value));
	}

	void ShaderProgram::SetUniform(GLint _uniformLocation, const glm::vec4 &_value) const
	{
		glProgramUniform4fv(m_id, _uniformLocation, 1, glm::value_ptr(_value));
	}

	void ShaderProgram::SetUniform(GLint _uniformLocation, const glm::mat4 &_value) const
	{
		glProgramUniformMatrix4fv(m_id, _uniformLocation, 1, GL_FALSE, glm::value_ptr(_value));
	}
} // bombengine