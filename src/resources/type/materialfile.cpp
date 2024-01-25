//
// Created by s5311430 on 28/11/2023.
//

#include "materialfile.h"

#include <rapidjson/document.h>

#include "rendering/shader/shader.h"
#include "rendering/texture/texture.h"
#include "rendering/material/material.h"

#include "resources/resources.h"

namespace bombengine
{
    bool MaterialFile::Load()
    {
        const std::shared_ptr<TextFile> materialTextFile = GetResources()->GetResource<TextFile>(GetPath());
        rapidjson::Document document;
        document.Parse(materialTextFile->GetData().c_str());

        // Ensure the file being loaded has all relevant fields.
        if(
            !(document.HasMember("vertex") && document["vertex"].IsString()) ||
            !(document.HasMember("fragment") && document["fragment"].IsString()) ||
            !(document.HasMember("textures") && document["textures"].IsArray()))
        {
            return false;
        }

        m_vertexShader = GetResources()->GetResource<TextFile>(document["vertex"].GetString());
        m_fragmentShader = GetResources()->GetResource<TextFile>(document["fragment"].GetString());

        const rapidjson::Value& textures = document["textures"];
        for(rapidjson::SizeType i = 0; i < textures.Size(); i++)
        {
            m_textures.push_back(GetResources()->GetResource<ImageFile>(textures[i].GetString()));
        }

        return true;
    }

    std::shared_ptr<Material> MaterialFile::LoadFromFile(const std::shared_ptr<Resources>& _resources, const std::filesystem::path& _path)
    {
        const std::shared_ptr<bombengine::MaterialFile> materialFile = _resources->GetResource<bombengine::MaterialFile>(_path);

        Shader vertexShader(bombengine::ShaderType::Vertex, materialFile->GetVertexShader()->GetData());
        Shader fragmentShader(bombengine::ShaderType::Fragment, materialFile->GetFragmentShader()->GetData());

        std::vector<std::shared_ptr<bombengine::Texture>> textures;
        for(const std::shared_ptr<ImageFile>& textureFile : materialFile->GetTextures())
        {
            textures.push_back(std::make_shared<bombengine::Texture>(textureFile->GetData(), textureFile->GetSize()));
        }

        return std::make_shared<bombengine::Material>(vertexShader, fragmentShader, textures);
    }
} // bombengine