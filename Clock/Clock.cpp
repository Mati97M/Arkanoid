#include "Clock.h"

Clock* Clock::s_Instance{};

void Clock::Update() {
	m_LastTime = m_currTime;
	m_currTime = getTickCount();
	m_DeltaTime = (static_cast<float>(m_currTime - m_LastTime)) / 1000.f;// (TARGET_FPS * 1000.f);
	//if (m_DeltaTime > TARGET_DELTA_TIME)
	//{
	//	m_DeltaTime = TARGET_DELTA_TIME;
	//}
}