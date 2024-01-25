//
// Created by s5311430 on 28/11/2023.
//

#pragma once

#include "resources/resource.h"

#include <vector>

#include "imagefile.h"
#include "textfile.h"

namespace bombengine
{
    class Resources;
    class Material;

    class MaterialFile final : public Resource
    {
    private:
        std::shared_ptr<TextFile> m_vertexShader;
        std::shared_ptr<TextFile> m_fragmentShader;

        std::vector<std::shared_ptr<ImageFile>> m_textures;
    protected:
        friend class Resources;

        explicit MaterialFile(const std::shared_ptr<Resources>& _resources, const std::filesystem::path& _path)
            : Resource(_resources, _path)
        {
        }
    public:
        bool Load() override;

		[[nodiscard]] std::shared_ptr<TextFile> GetVertexShader() const { return m_vertexShader; }
		[[nodiscard]] std::shared_ptr<TextFile> GetFragmentShader() const { return m_fragmentShader; }

		[[nodiscard]] std::vector<std::shared_ptr<ImageFile>> GetTextures() const { return m_textures; }

        static std::shared_ptr<Material> LoadFromFile(const std::shared_ptr<Resources>& _resources, const std::filesystem::path& _path);
    };
} // bombengine
