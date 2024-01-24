#include "core.h"

#include <GL/glew.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <SDL2/SDL.h>

#include "window/window.h"

#include "resources/type/textfile.h"
#include <iostream>

namespace bombengine
{
    BombCore::BombCore()
        : m_running(true)
    {
        if(const int sdlInitialized = SDL_Init(SDL_INIT_VIDEO); sdlInitialized < 0) { throw std::runtime_error("Failed to initialize SDL."); }
    }

    BombCore::~BombCore()
    {
        SDL_Quit();
    }

    void BombCore::Load()
    {
        m_resources = Resources::Initialize();

		m_windows = Windows::Initialize();
		m_scenes = Scenes::Initialize(shared_from_this());
    }

    void BombCore::GameLoop()
    {
        while(PollEvents() && Update())
        {
            PostUpdate();
        }
    }

    bool BombCore::Update()
    {
        m_time.Update();
        m_input.Update();

        m_scenes->Update();
        return m_running;
    }

    void BombCore::PostUpdate()
    {
        m_scenes->PostUpdate();

        m_windows->Draw();

        m_input.PostUpdate();
    }

    bool BombCore::PollEvents()
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

    std::shared_ptr<BombCore> BombCore::Initialize()
    {
        std::shared_ptr<BombCore> core = std::shared_ptr<BombCore>(new BombCore);
        core->Load();
        return core;
    }
}