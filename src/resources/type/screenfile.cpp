//
// Created by Kimera Royal on 25/01/2024.
//

#include "screenfile.h"

#include <rapidjson/document.h>

#include "core/window/screen/screen.h"
#include "rendering/shader/shader.h"
#include "rendering/material/material.h"

#include "resources/resources.h"

namespace bombengine
{
    bool ScreenFile::Load()
    {
        const std::shared_ptr<TextFile> screenTextFile = GetResources()->GetResource<TextFile>(GetPath());
        rapidjson::Document document;
        document.Parse(screenTextFile->GetData().c_str());

        // Ensure the file being loaded has all relevant fields.
        if(
            !(document.HasMember("vertex") && document["vertex"].IsString()) ||
            !(document.HasMember("fragment") && document["fragment"].IsString()))
        {
            return false;
        }

        m_vertexShader = GetResources()->GetResource<TextFile>(document["vertex"].GetString());
        m_fragmentShader = GetResources()->GetResource<TextFile>(document["fragment"].GetString());

        return true;
    }

    std::shared_ptr<Screen> ScreenFile::LoadFromFile(const std::shared_ptr<Resources>& _resources, const std::filesystem::path& _path, const glm::ivec2 _size)
    {
        const std::shared_ptr<bombengine::ScreenFile> materialFile = _resources->GetResource<bombengine::ScreenFile>(_path);

        Shader vertexShader(bombengine::ShaderType::Vertex, materialFile->GetVertexShader()->GetData());
        Shader fragmentShader(bombengine::ShaderType::Fragment, materialFile->GetFragmentShader()->GetData());

        return std::make_shared<bombengine::Screen>(vertexShader, fragmentShader, _size);
    }
} // bombengine