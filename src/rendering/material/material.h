//
// Created by s5311430 on 03/11/2023.
//

#pragma once

#include <vector>

#include "rendering/shader/shader.h"
#include "rendering/shader/shaderprogram.h"
#include "rendering/texture/texture.h"

namespace bombengine
{
	class Material
	{
	private:
		std::unique_ptr<ShaderProgram> m_program;

		std::vector<std::shared_ptr<Texture>> m_textures;
	public:
		Material(Shader& _vertexShader, Shader& _fragmentShader, const std::vector<std::shared_ptr<Texture>>& _textures);
		Material(Shader& _vertexShader, Shader& _fragmentShader, const std::shared_ptr<Texture>& _texture);

		void Bind() const;
		void Unbind() const;
	};
} // bombengine
