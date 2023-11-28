//
// Created by s5311430 on 28/11/2023.
//

#include "materialfile.h"

#include <rapidjson/document.h>

#include <resources/resources.h>

namespace bombengine
{
    bool MaterialFile::Load()
    {
        const std::shared_ptr<TextFile> materialTextFile = GetResources()->GetResource<TextFile>(GetPath());
        rapidjson::Document document;
        document.Parse(materialTextFile->GetData().c_str());

        std::string vertexShaderPath = "res/simple.vert";
        std::string fragmentShaderPath = "res/simple.frag";

        m_vertexShader = GetResources()->GetResource<TextFile>(vertexShaderPath);
        m_fragmentShader = GetResources()->GetResource<TextFile>(fragmentShaderPath);
        return true;
    }
} // bombengine