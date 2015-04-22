#include "stdafx.h"
#include "CCarSet.h"


CCarSet::range CCarSet::m_gearSpeedRange[] = { { 0, 20 },
												{ 0, 150 },
												{ 0, 30 },
												{ 20, 50 },
												{ 30, 60 },
												{ 40, 90 },
												{ 50, 150 } };

CCarSet::CCarSet()
	:m_engineIsTurnedOn(false)
	, m_speed(0)
	, m_gear(0)
	, m_direction(STAND)
{
}

bool CCarSet::EngineIsTurnedOn()const
{
	return m_engineIsTurnedOn;
}

bool CCarSet::TurnOnEngine()
{
	if (!m_engineIsTurnedOn)
	{
		m_engineIsTurnedOn = true;
		m_speed = 0;
		m_gear = 0;
		m_direction = STAND;
		return m_engineIsTurnedOn;
	}
	return false;
}

bool CCarSet::TurnOffEngine()
{
	if (m_engineIsTurnedOn)
	{
		if (m_direction == STAND && m_gear == 0 && m_speed == 0)
		{
			m_engineIsTurnedOn = false;
			return true;
		}
	}
	return false;
}

int CCarSet::GetGear() const
{
	return m_gear;
}

int CCarSet::GetSpeed() const
{
	return m_speed;
}

bool CCarSet::SetGear(int gear)
{
	if (gear < -1 || gear > 5)
	{
		return false;
	}
	if (!m_engineIsTurnedOn && gear == 0)
	{
		m_gear = gear;
		return true;
	}
	
	return false;
}

bool CCarSet::SetSpeed(int speed)
{
	if (speed < 0 || speed > 150)
	{
		return false;
	}
	if (m_gear == 0 && speed < m_speed)
	{
		return false;
	}
	if (speed >= m_gearSpeedRange[m_gear + 1].max 
		&& speed <= m_gearSpeedRange[m_gear + 1].min)
	{
		if (speed == 0)
		{
			m_direction = STAND;
		}
		if (m_speed == 0 && speed > 0)
		{
			if (m_gear > -1)
			{
				m_direction = FORWARD;
			}
			else
			{
				m_direction = BACKWARD;
			}
		}
		m_speed = speed;
		return true;
	}

	return false;
}