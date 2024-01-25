//
// Created by Kimera Royal on 25/01/2024.
//

#pragma once

#include <glm/vec2.hpp>

#include "resources/resource.h"

#include "textfile.h"

namespace bombengine
{
    class Resources;
    class Screen;

    class ScreenFile : public Resource
    {
    private:
        std::shared_ptr<TextFile> m_vertexShader;
        std::shared_ptr<TextFile> m_fragmentShader;
    protected:
        friend class Resources;

        explicit ScreenFile(const std::shared_ptr<Resources>& _resources, const std::filesystem::path& _path)
            : Resource(_resources, _path)
        {
        }
    public:
        bool Load() override;

        [[nodiscard]] std::shared_ptr<TextFile> GetVertexShader() const { return m_vertexShader; }
        [[nodiscard]] std::shared_ptr<TextFile> GetFragmentShader() const { return m_fragmentShader; }

        static std::shared_ptr<Screen> LoadFromFile(const std::shared_ptr<Resources>& _resources, const std::filesystem::path& _path, glm::ivec2 _size);
    };
} // bombengine
