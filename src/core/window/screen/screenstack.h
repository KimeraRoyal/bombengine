//
// Created by Kimera Royal on 25/01/2024.
//

#pragma once

#include <memory>
#include <vector>

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

namespace bombengine
{
    class Screen;
    class FrameBuffer;
    class Graphic;

    class ScreenStack
    {
    private:
        std::vector<std::shared_ptr<Screen>> m_screens;

        std::shared_ptr<FrameBuffer> m_renderTexture;
        std::shared_ptr<FrameBuffer> m_swapRenderTexture;

        std::shared_ptr<Graphic> m_target;
        glm::ivec2 m_target0ffset;
        bool m_targetDirty;

        void AssignTargets();
    public:
        explicit ScreenStack(glm::ivec2 _renderTextureSize);

        void Draw();

        void Bind() const;
        void Unbind() const;

        void AddScreen(const std::shared_ptr<Screen>& _screen);
        void RemoveScreen(unsigned int _index);
        void RemoveScreen(const std::shared_ptr<Screen>& _screen);
        void RemoveAllScreens();

        [[nodiscard]] std::shared_ptr<Graphic> GetTarget() const { return m_target; }
        [[nodiscard]] glm::ivec2 GetTarget0ffset() const { return m_target0ffset; }
        void SetTarget(const std::shared_ptr<Graphic>& _target, glm::ivec2 _targetOffset);
    };
} // bombengine
