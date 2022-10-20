#include "Clock.h"

Clock* Clock::s_Instance{};

void Clock::Update() {
	m_LastTime = m_currTime;
	m_currTime = getTickCount();
	m_DeltaTime = (static_cast<float>(m_currTime - m_LastTime)) / 1000.f;// (TARGET_FPS * 1000.f);
	immuneMonitor = m_currTime;
	//if (m_DeltaTime > TARGET_DELTA_TIME)
	//{
	//	m_DeltaTime = TARGET_DELTA_TIME;
	//}
}

bool Clock::ImmuneTime() {
	if (m_ImmuneTime)
	{
		if (immuneMonitor >= nextUpdateImmune)
		{
			std::cout << "not immune for 10 secs" << std::endl;
			m_ImmuneTime = false;
			//immuneMonitor = getTickCount();
			immuneMonitor = m_currTime;
			nextUpdateImmune = immuneMonitor + 10 * 1000;
			return false;
		}
		return true;
		//if (threeSecsPassed())
		//{
		//	std::cout << "not immune for 10 secs" << std::endl;
		//	m_ImmuneTime = false;
		//	immuneMonitor = getTickCount();
		//	return false;
		//}


	}

	if (immuneMonitor >= nextUpdateImmune)
	{
		std::cout << "Immune Time for 3 secs" << std::endl;
		immuneMonitor = m_currTime;
		//immuneMonitor = getTickCount();
		m_ImmuneTime = true;
		nextUpdateImmune = immuneMonitor + 3 * 1000;
		return true;
	}
	return false;
	//if (!m_ImmuneTime && tenSecsPassed())
	//{
	//	//immuneMonitor = getTickCount();
	//	//std::cout << "Immune Time for 3 secs" << std::endl;
	//	//m_ImmuneTime = true;
	//	//return true;
	//}

}

bool Clock::tenSecsPassed() {
	auto currT = getTickCount();
	return ( static_cast<unsigned>((currT - immuneMonitor)/1000)) % 10  == 0; 
}
bool Clock::threeSecsPassed() {
	auto currT = getTickCount();
	return (static_cast<unsigned>(currT - immuneMonitor)/1000) % 3 == 0;
}