#include "core.h"

#include <SDL2/SDL.h>

#include <rendering/material/material.h>

#include "window/window.h"

namespace bombengine
{
    Core::Core()
        : m_running(true)
    {
        int sdlInitialized = SDL_Init(SDL_INIT_VIDEO);
        if(sdlInitialized < 0) { throw std::runtime_error("Failed to initialize SDL."); }
    }

    Core::~Core()
    {
        SDL_Quit();
    }

    void Core::Run()
    {
        while(PollEvents() && Update())
        {
            Draw();
        }
    }

    bool Core::Update()
    {
        return m_running;
    }

    void Core::Draw()
    {

    }

    bool Core::PollEvents()
    {
        SDL_Event event;
        while(m_running && SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                m_running = false;
                break;
            }
        }
        return m_running;
    }

    std::shared_ptr<Core> Core::Initialize()
    {
        return std::shared_ptr<Core>(new Core);
    }
}