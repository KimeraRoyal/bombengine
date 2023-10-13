//
// Created by s5311430 on 06/10/2023.
//

#pragma once

#ifndef BOMBENGINE_CONTEXT_H
#define BOMBENGINE_CONTEXT_H

#include <SDL2/SDL_video.h>

namespace bombengine
{
    class Context
    {
    private:
        SDL_GLContext m_context;

    public:
        explicit Context(SDL_Window* _window);
        ~Context();
    };

} // bombengine

#endif //BOMBENGINE_CONTEXT_H
