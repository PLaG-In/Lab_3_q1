#include "stdafx.h"
#include "CCarSet.h"


CCarSet::CCarSet()
	:m_engineIsTurnedOn(false)
	, m_speed(0)
	, m_gear(0)
{

}


CCarSet::~CCarSet()
{
}

bool CCarSet::EngineIsTurnedOn()const
{
	return m_engineIsTurnedOn;
}

bool CCarSet::TurnOnEngine()
{
	m_engineIsTurnedOn = true;
	m_speed = 0;
	m_gear = 0;
	return m_engineIsTurnedOn;
}

bool CCarSet::TurnOffEngine()
{
	m_speed = 0;
	m_gear = 0;
	m_engineIsTurnedOn = false;
	return true;
}

int CCarSet::GetGear() const
{
	if (m_engineIsTurnedOn)
	{
		return m_gear;
	}
	return 0;
}

int CCarSet::GetSpeed() const
{
	if (m_engineIsTurnedOn)
	{
		return m_speed;
	}
	return 0;
}

bool CCarSet::SetGear(int gear)
{
	if (gear >= -1 && gear <= 5)
	{
		m_gear = gear;
		return true;
	}
	return false;
}

bool CCarSet::SetSpeed(int speed)
{
	if (speed >= 0 && speed <= 150)
	{
		m_speed = speed;
		return true;
	}
	return false;
}