#pragma once

class CCarSet
{
public:
	CCarSet();
	~CCarSet();
	bool EngineIsTurnedOn() const;
	bool TurnOnEngine();	/*Включение двигателя,	если он выключен*/	bool TurnOffEngine();	int GetSpeed() const;	int GetGear() const;	bool SetGear(int gear);	bool SetSpeed(int speed);private:
	bool m_engineIsTurnedOn;
	int m_speed;
	int m_gear;
};

