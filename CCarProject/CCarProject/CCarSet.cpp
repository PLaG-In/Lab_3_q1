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

CCarSet::direction CCarSet::GetDirection() const
{
	return m_direction;
}

bool CCarSet::SetGear(int gear)
{
	if (gear < -1 || gear > 5)
	{
		return false;
	}

	if (!m_engineIsTurnedOn)
	{
		if (gear == 0)
		{
			m_gear = 0;
			return true;
		}
		return false;
	}

	if (gear == m_gear)
	{
		return true;
	}

	if (gear == 1 && m_direction == BACK)
	{
		return false;
	}

	if ((gear == -1 && m_gear == 0 && m_speed == 0) 
		|| (gear == -1 && m_gear == 1 && m_speed == 0))
	{
		m_gear = -1;
		return true;
	}
	else if (gear == -1)
	{
		return false;
	}

	if (m_speed >= m_gearSpeedRange[gear + 1].min
		&& m_speed <= m_gearSpeedRange[gear + 1].max)
	{
		m_gear = gear;
		return true;
	}

	return false;
}



bool CCarSet::SetSpeed(int speed)
{
	if (!m_engineIsTurnedOn)
	{
		return false;
	}

	if (speed < 0 || speed > 150)
	{
		return false;
	}

	if (m_gear == 0 && speed > m_speed)
	{
		return false;
	}

	if (speed >= m_gearSpeedRange[m_gear + 1].min 
		&& speed <= m_gearSpeedRange[m_gear + 1].max)
	{
		if (speed == 0)
		{
			m_direction = STAND;
		}
		if (m_speed == 0 && speed > 0)
		{
			if (m_gear > -1)
			{
				m_direction = STRAIGHT;
			}
			else
			{
				m_direction = BACK;
			}
		}
		m_speed = speed;
		return true;
	}

	return false;
}

CCarSet::~CCarSet()
{
}