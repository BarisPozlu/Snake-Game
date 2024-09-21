#include "Timer.h"

Timer::Timer() :
	m_started(false), 
	m_paused(false), 
	m_startTime(0), 
	m_storedPauseTime(0)
{

}

void Timer::Start()
{
	m_started = true;
	m_paused = false;
	
	m_startTime = SDL_GetTicks();
	m_storedPauseTime = 0;
}

void Timer::Pause()
{
	if (!m_started || m_paused) return;

	m_paused = true;
	m_storedPauseTime += SDL_GetTicks() - m_startTime;
}

void Timer::UnPause()
{
	if (!m_started || !m_paused) return;

	m_paused = false;
	m_startTime = SDL_GetTicks();
}

Uint32 Timer::GetTime() const
{
	if (!m_started) return 0;

	if (m_paused) return m_storedPauseTime;

	return SDL_GetTicks() - m_startTime + m_storedPauseTime;
}

void Timer::Stop()
{
	m_started = false;
	m_paused = false;
	m_startTime = 0;
	m_storedPauseTime = 0;
}
