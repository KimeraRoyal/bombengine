//
// Created by s5311430 on 06/10/2023.
//

#ifndef BOMBENGINE_WINDOW_H
#define BOMBENGINE_WINDOW_H

#include <memory>

#include "context.h"

namespace bombengine
{
    class Window
    {
    private:
        SDL_Window* m_window;

        std::shared_ptr<Context> m_context;

    public:
        Window(std::shared_ptr<Context>& _context, const Uint32 _flags);
        ~Window();
    };

} // bombengine

#endif //BOMBENGINE_WINDOW_H
