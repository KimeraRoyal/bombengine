//
// Created by s5311430 on 03/11/2023.
//

#include "material.h"

namespace bombengine
{
	Material::Material(Shader& _vertexShader, Shader& _fragmentShader, const std::vector<std::shared_ptr<Texture>>& _textures)
		: m_program(std::make_unique<ShaderProgram>()),
		m_textures(_textures)
	{
		_vertexShader.Attach(m_program->GetID());
		_fragmentShader.Attach(m_program->GetID());
		m_program->Link();
	}

	Material::Material(Shader& _vertexShader, Shader& _fragmentShader, const std::shared_ptr<Texture>& _texture)
		: Material(_vertexShader, _fragmentShader, std::vector<std::shared_ptr<Texture>>(1, _texture))
	{ }

	void Material::Bind() const
	{
		glUseProgram(m_program->GetID());
		for(auto i = 0; i < m_textures.size(); i++)
		{
			m_textures[i]->Bind(m_program->GetID(), i);
		}
	}

	void Material::Unbind() const
	{
		for(auto i = 0; i < m_textures.size(); i++)
		{
			m_textures[i]->Unbind(i);
		}
		glUseProgram(0);
	}
} // bombengine