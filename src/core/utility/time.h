//
// Created by s5311430 on 08/12/2023.
//

#pragma once

#include <vector>

#include <SDL2/SDL_stdinc.h>

namespace bombengine
{
    class Time
    {
    private:
        static unsigned short s_defaultFpsAverageDuration;

        Uint64 m_lastPerformanceCounter;

        double m_deltaTime;
        double m_totalTime;

        unsigned long m_totalFrames;
        unsigned int m_fps;

        double m_fpsTimer;
        unsigned int m_framesInSecond;

        double m_averageFps;
        std::vector<unsigned int> m_fpsOverTime;
        int m_fpsSampleCount;
        unsigned short m_fpsSampleIndex;

        void CalculateTime();
        void CalculateFps();
        void CalculateAverageFps();
    public:
        Time();

        void Update();

        [[nodiscard]] double GetDeltaTime() const { return m_deltaTime; }
        [[nodiscard]] float GetDeltaTimeF() const { return static_cast<float>(m_deltaTime); }

        [[nodiscard]] double GetTotalTime() const { return m_totalTime; }
        [[nodiscard]] float GetTotalTimeF() const { return static_cast<float>(m_totalTime); }
        [[nodiscard]] unsigned long GetTotalTimeI() const { return static_cast<unsigned long>(m_totalTime); }

        [[nodiscard]] unsigned long GetTotalFrames() const { return m_totalFrames; }
        [[nodiscard]] unsigned int GetFps() const { return m_fps; }

        [[nodiscard]] double GetAverageFps() const { return m_averageFps; }
        [[nodiscard]] float GetAverageFpsF() const { return static_cast<float>(m_averageFps); }
        [[nodiscard]] unsigned int GetAverageFpsI() const { return static_cast<unsigned int>(m_averageFps); }
    };
} // bombengine
