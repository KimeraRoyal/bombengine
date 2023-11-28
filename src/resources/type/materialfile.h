//
// Created by s5311430 on 28/11/2023.
//

#pragma once

#include <vector>
#include <resources/resource.h>

#include "imagefile.h"
#include "textfile.h"

namespace bombengine
{
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
        { }
    public:
        bool Load() override;

		[[nodiscard]] std::shared_ptr<TextFile> GetVertexShader() const { return m_vertexShader; }
		[[nodiscard]] std::shared_ptr<TextFile> GetFragmentShader() const { return m_fragmentShader; }

		[[nodiscard]] std::vector<std::shared_ptr<ImageFile>> GetTexture() const { return m_textures; }
    };
} // bombengine
