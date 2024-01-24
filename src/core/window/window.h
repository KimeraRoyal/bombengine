//
// Created by s5311430 on 06/10/2023.
//

#pragma once

#include "screen.h"
#include "windowproperties.h"

namespace bombengine
{
    class Window
    {
    private:
        SDL_Window* m_window;
        std::shared_ptr<Context> m_context;

        std::shared_ptr<Screen> m_screen;

        std::string m_name;

        glm::ivec2 m_position;
        glm::ivec2 m_size;

        Uint32 m_flags;
    public:
        Window(std::shared_ptr<Context>& _context, const WindowProperties& _windowProperties);
        ~Window();

        void Draw() const;

        void MakeCurrent() const;

        [[nodiscard]] std::shared_ptr<Screen> GetScreen() const { return m_screen; }
        void SetScreen(const std::shared_ptr<Screen>& _screen) { m_screen = _screen; }

        [[nodiscard]] std::string GetName() const { return m_name; }

        [[nodiscard]] glm::ivec2 GetPosition() const { return m_position; }
        [[nodiscard]] glm::ivec2 GetSize() const { return m_size; }

        [[nodiscard]] Uint32 GetFlags() const { return m_flags; }
    };

} // bombengine
