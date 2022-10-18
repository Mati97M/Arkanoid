#pragma once
#include "Framework.h"
#include <iostream>

class Clock
{
	float m_DeltaTime;
	//const float TARGET_DELTA_TIME;
	//const int TARGET_FPS;
	unsigned m_LastTime;
	unsigned m_currTime;	//in milisecs since initialization the library
	static Clock* s_Instance;

	Clock() : m_currTime{ getTickCount() }, m_LastTime{ m_currTime }, m_DeltaTime{}/*, TARGET_DELTA_TIME{ 1.5f }, TARGET_FPS{ 60 }*/{}
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

};
