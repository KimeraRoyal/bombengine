//
// Created by s5311430 on 06/10/2023.
//

#include "context.h"

#include <stdexcept>

#include <GL/glew.h>

namespace bombengine
{
    Context::Context(SDL_Window* _window)
        : m_context(nullptr)
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 5);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        m_context = SDL_GL_CreateContext(_window);
        if(!m_context) { throw std::runtime_error("Could not create GL Context."); }
        
        auto glewInitialized = glewInit();
        if(glewInitialized != GLEW_OK) { throw std::runtime_error("Could not initialize glew."); }
    }

    Context::~Context()
    {
        SDL_GL_DeleteContext(m_context);
    }
} // bombengine