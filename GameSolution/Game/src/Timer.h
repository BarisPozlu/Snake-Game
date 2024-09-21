#pragma once

#include <SDL.h>

class Timer
{
public:
	Timer();
	void Start();
	void Pause();
	void UnPause();
	Uint32 GetTime() const;
	void Stop();

public:
	inline bool IsPaused() const { return m_paused; }
	inline bool IsStarted() const { return m_started; }

private:
	bool m_started;
	bool m_paused;
	Uint32 m_startTime;
	Uint32 m_storedPauseTime;
};
