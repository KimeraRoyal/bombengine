//
// Created by s5311430 on 27/10/2023.
//

#pragma once

#include <string>

#include <GL/glew.h>

namespace bombengine
{
	class Shader
	{
	private:
		GLuint m_attachedProgramId;

		GLuint m_id;
	public:
		Shader(GLint _type, const std::string& _source);
		~Shader();

		void Attach(GLuint _programId);
		void Detach();

		[[nodiscard]] GLuint GetAttachedProgramID() const { return m_attachedProgramId; }

		[[nodiscard]] GLuint GetID() const { return m_id; }
	};

} // bombengine
