//
// Created by Kimera Royal on 25/01/2024.
//

#include "screenstack.h"

#include <string>

#include "rendering/texture/graphic.h"
#include "rendering/texture/framebuffer.h"

#include "screen.h"

namespace bombengine
{
    ScreenStack::ScreenStack(glm::ivec2 _renderTextureSize)
        : m_renderTexture(std::make_unique<FrameBuffer>(_renderTextureSize, std::vector<std::string> { "in_Texture" })),
        m_swapRenderTexture(std::make_unique<FrameBuffer>(_renderTextureSize, std::vector<std::string> { "in_Texture" })),
        m_target0ffset(0), m_targetDirty(false)
    {
        m_renderTexture->AddColorBuffer(GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, GL_LINEAR, GL_CLAMP_TO_EDGE);
        m_swapRenderTexture->AddColorBuffer(GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, GL_LINEAR, GL_CLAMP_TO_EDGE);
    }

    void ScreenStack::Draw()
    {
        if(m_screens.empty() || !m_target) { return; }

        AssignTargets();
        glViewport(m_target0ffset.x, m_target0ffset.y, m_screens[0]->GetSize().x, m_screens[0]->GetSize().y);

        for(int i = 0; i < m_screens.size(); i++)
        {
            std::swap(m_renderTexture, m_swapRenderTexture);

            const bool lastScreen = i >= m_screens.size() - 1;

            if(!lastScreen) { Bind(); }
            m_screens[i]->Draw();
            if(!lastScreen)
            {
                Unbind();
                glViewport(0, 0, m_screens[i + 1]->GetSize().x, m_screens[i + 1]->GetSize().y);
            }
        }
    }

    void ScreenStack::Bind() const
    {
        m_renderTexture->BindFramebuffer();
    }

    void ScreenStack::Unbind() const
    {
        m_renderTexture->UnbindFramebuffer();
    }

    void ScreenStack::AssignTargets()
    {
        if(!m_targetDirty) { return; }

        if(!m_screens.empty()) { m_screens[0]->SetTarget(m_target); }
        for(int i = 1; i < m_screens.size(); i++)
        {
            m_screens[i]->SetTarget(m_swapRenderTexture);
        }

        m_targetDirty = false;
    }

    void ScreenStack::AddScreen(const std::shared_ptr<Screen>& _screen)
    {
		m_screens.push_back(_screen);
        m_targetDirty = true;
    }

    void ScreenStack::RemoveScreen(const unsigned _index)
    {
		m_screens.erase(m_screens.begin() + _index);
        m_targetDirty = true;
    }

    void ScreenStack::RemoveScreen(const std::shared_ptr<Screen>& _screen)
    {
        std::erase(m_screens, _screen);
        m_targetDirty = true;
    }

    void ScreenStack::RemoveAllScreens()
    {
        m_screens.clear();
        m_targetDirty = true;
    }

    void ScreenStack::SetTarget(const std::shared_ptr<Graphic>& _target, const glm::ivec2 _targetOffset)
    {
        m_target = _target;
        m_target0ffset = _targetOffset;

        m_targetDirty = true;
    }
} // bombengine