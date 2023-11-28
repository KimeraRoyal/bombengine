//
// Created by s5311430 on 21/11/2023.
//

#include "demoscene.h"

#include <iostream>

#include <core/core.h>

#include <resources/type/imagefile.h>
#include <resources/type/textfile.h>

namespace bombdemo
{
    bool DemoScene::Load()
    {
        const std::shared_ptr<bombengine::TextFile> vertexShaderFile = GetResources()->GetResource<bombengine::TextFile>("res/simple.vert");
        const std::shared_ptr<bombengine::TextFile> fragmentShaderFile = GetResources()->GetResource<bombengine::TextFile>("res/simple.frag");

        //TODO: Should Shader constructors take a bombengine enum, to encapsulate OpenGL behaviour?
        bombengine::Shader vertexShader(bombengine::ShaderType::Vertex, vertexShaderFile->GetData());
        bombengine::Shader fragmentShader(bombengine::ShaderType::Fragment, fragmentShaderFile->GetData());

        const std::shared_ptr<bombengine::ImageFile> textureFile = GetResources()->GetResource<bombengine::ImageFile>("res/cat.png");
        std::vector<std::shared_ptr<bombengine::Texture>> textures;
        textures.push_back(std::make_shared<bombengine::Texture>(textureFile->GetData(), "cat", textureFile->GetSize()));

        m_material = std::make_shared<bombengine::Material>(vertexShader, fragmentShader, textures);

        return true;
    }
} // bombdemo