#pragma once

class CCarSet
{
public:
	CCarSet();
	~CCarSet();
	bool EngineIsTurnedOn() const;
	bool TurnOnEngine();
	bool m_engineIsTurnedOn;
	int m_speed;
	int m_gear;
};
