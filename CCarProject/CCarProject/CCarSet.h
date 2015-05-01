#pragma once

class CCarSet
{
public:
	CCarSet();
	~CCarSet();

	enum direction
	{
		BACK,
		STAND,
		STRAIGHT
	};

	bool EngineIsTurnedOn() const;
	int GetSpeed() const;
	int GetGear() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	direction GetDirection() const;
	bool SetSpeed(int speed);
private:
	struct range
	{
		int min;
		int max;
	};
	static range m_gearSpeedRange[];
	bool m_engineIsTurnedOn;
	int m_speed;
	direction m_direction;
	int m_gear;
};

