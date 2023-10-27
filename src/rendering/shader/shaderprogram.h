//
// Created by s5311430 on 27/10/2023.
//

#pragma once

#include <unordered_map>
#include <memory>
#include <string>

#include <GL/glew.h>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

namespace bombengine
{
	class ShaderProgram
	{
	private:
		GLuint m_id;
		GLuint m_attributeCount;

		std::unordered_map<size_t, GLint> m_uniformLocations;

		void AssignUniformKeys();
	public:
		ShaderProgram();
		~ShaderProgram();

		void Link();

		void BindAttribute(const std::string& _attribute);

		void SetUniform(GLint _uniformLocation, float _value) const;
		void SetUniform(GLint _uniformLocation, const glm::vec2& _value) const;
		void SetUniform(GLint _uniformLocation, const glm::vec3& _value) const;
		void SetUniform(GLint _uniformLocation, const glm::vec4& _value) const;
		void SetUniform(GLint _uniformLocation, const glm::mat4& _value) const;

		template <typename T>
		void SetHashedUniform(size_t _key, T _value) const
		{
			if (m_uniformLocations.find(_key) == m_uniformLocations.end()) { return; }
			SetUniform(m_uniformLocations.at(_key), _value);
		}

		template <typename T>
		void SetNamedUniform(const std::string& _name, T _value) const
		{
			SetUniform(glGetUniformLocation(m_id, _name.c_str()), _value);
		}

		[[nodiscard]] GLuint GetID() const { return m_id; }
	};
} // bombengine