//
// Created by s5311430 on 08/12/2023.
//

#include "time.h"

#include <SDL2/SDL_timer.h>

namespace bombengine
{
    unsigned short Time::s_defaultFpsAverageDuration = 5;

	Time::Time()
		: m_lastPerformanceCounter(0),
		  m_deltaTime(0.0), m_totalTime(0.0),
		  m_totalFrames(0), m_fps(0),
		  m_fpsTimer(0.0), m_framesInSecond(0),
		  m_averageFps(0.0),
		  m_fpsSampleCount(s_defaultFpsAverageDuration), m_fpsSampleIndex(0)
	{

	}

	void Time::Update()
	{
		m_totalFrames++;
		CalculateTime();
		CalculateFps();
	}

	void Time::CalculateTime()
	{
		const Uint64 performanceCounter = SDL_GetPerformanceCounter();

		if(m_lastPerformanceCounter)
		{
			m_deltaTime = static_cast<double>((performanceCounter - m_lastPerformanceCounter) * 1000) /
				static_cast<double>(SDL_GetPerformanceFrequency()) * 0.001;
		}
		m_totalTime += m_deltaTime;
		m_lastPerformanceCounter = performanceCounter;
	}

	void Time::CalculateFps()
	{
		m_fpsTimer += m_deltaTime;
		m_framesInSecond++;
		if(m_fpsTimer < 1.0f) { return; }

		m_fps = m_framesInSecond;
		CalculateAverageFps();

		m_framesInSecond = 0;
		m_fpsTimer -= 1.0f;
	}

	void Time::CalculateAverageFps()
	{
		if(m_fpsOverTime.size() > m_fpsSampleCount) { m_fpsOverTime.resize(m_fpsSampleCount); }

		m_fpsSampleIndex = m_fpsSampleIndex % m_fpsSampleCount;

		if(m_fpsOverTime.size() < m_fpsSampleIndex + 1)
		{
			m_fpsOverTime.push_back(m_fps);
		}
		else
		{
			m_fpsOverTime[m_fpsSampleIndex] = m_fps;
		}

		m_averageFps = 0.0;
		for(const auto& fps : m_fpsOverTime)
		{
			m_averageFps += static_cast<double>(fps);
		}
		m_averageFps /= static_cast<double>(m_fpsSampleCount);

		m_fpsSampleIndex++;
	}
} // bombengine