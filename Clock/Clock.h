#pragma once
#include <iostream>
#include "../Framework.h"
class Clock
{
	float m_DeltaTime;
	//const float TARGET_DELTA_TIME;
	//const int TARGET_FPS;
	unsigned m_LastTime;
	unsigned m_currTime;	//in milisecs since initialization the library
	static Clock* s_Instance;
	bool m_ImmuneTime{true};
	unsigned immuneMonitor{};
	unsigned nextUpdateImmune{};

	Clock() : m_currTime{ getTickCount() }, m_LastTime{ m_currTime }, m_DeltaTime{}, nextUpdateImmune{ m_currTime + 3 * 1000 }/*, TARGET_DELTA_TIME{ 1.5f }, TARGET_FPS{ 60 }*/{immuneMonitor = m_currTime; }
	~Clock() {}
public:
	static Clock* s_GetClock() { return s_Instance = s_Instance ? s_Instance : new Clock(); }
	static void destroyClock() {
		if (s_Instance)
			delete s_Instance;
	}
	float getTimeInSecs() { return m_currTime / 1000.f; }
	void Update();
	float getDeltaTime() { /*std::cout << m_DeltaTime << std::endl;*/  return m_DeltaTime; }
	bool tenSecsPassed();
	bool threeSecsPassed();
	bool ImmuneTime();
	void resetImmuneFlag() { m_ImmuneTime = true; immuneMonitor = getTickCount(); }
	void setImmuneMonitor() { immuneMonitor = getTickCount(); }
};
