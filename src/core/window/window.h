//
// Created by s5311430 on 06/10/2023.
//

#pragma once

#include <vector>

#include "rendersource.h"
#include "windowproperties.h"
#include "screen/screenstack.h"

namespace bombengine
{
    class Window
    {
    private:
        SDL_Window* m_window;
        std::shared_ptr<Context> m_context;

        std::shared_ptr<ScreenStack> m_screenStack;

        std::string m_name;

        glm::ivec2 m_position;
        glm::ivec2 m_size;

        Uint32 m_flags;

		std::vector<RenderSource*> m_renderSources;
    public:
        Window(std::shared_ptr<Context>& _context, const WindowProperties& _windowProperties);
        ~Window();

        void Draw() const;

        void MakeCurrent() const;

        void AddRenderSource(RenderSource* _renderSource);
        void RemoveRenderSource(unsigned int _index);
        void RemoveRenderSource(RenderSource* _renderSource);
        void RemoveAllRenderSources();

        [[nodiscard]] std::shared_ptr<ScreenStack> GetScreenStack() const { return m_screenStack; }

        [[nodiscard]] std::string GetName() const { return m_name; }

        [[nodiscard]] glm::ivec2 GetPosition() const { return m_position; }
        [[nodiscard]] glm::ivec2 GetSize() const { return m_size; }

        [[nodiscard]] Uint32 GetFlags() const { return m_flags; }
    };

} // bombengine
