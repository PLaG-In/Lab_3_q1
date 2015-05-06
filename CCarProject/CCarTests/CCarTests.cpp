// CCarTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "stdafx.h"
#include "../CCarProject/CCar.h"

struct CarSetFixture
{
	CCar car;
};

/*
Автомобиль
- изначально выключен двигатель
- может быть включен двигатель
- может быть выключен двигатель
- в выключенном состоянии должен быть на нейтральной передаче и на 0 скорости
- при первом включении двигатель включается на первом канале
- позволяет установить скорость от 0 до 150, когда двигатель включен
*/
BOOST_FIXTURE_TEST_SUITE(CarSet, CarSetFixture)

BOOST_AUTO_TEST_CASE(TurnedOffByDefault)
{
	BOOST_CHECK(!car.EngineIsTurnedOn());
}

BOOST_AUTO_TEST_CASE(CanBeTurnedOn)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.EngineIsTurnedOn());
}

BOOST_AUTO_TEST_CASE(CanBeTurnedOff)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.TurnOffEngine());
	BOOST_CHECK(!car.EngineIsTurnedOn());
}

BOOST_AUTO_TEST_CASE(GearSpeedAndDirectionByDefault)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK_EQUAL(car.GetDirection(), CCar::STAND);
}

BOOST_AUTO_TEST_CASE(CantBeTurnedOnTwice)
{
	car.TurnOnEngine();
	BOOST_CHECK(car.TurnOnEngine());
}

BOOST_AUTO_TEST_CASE(CantBeTurnedOffTwice)
{
	car.TurnOnEngine();
	car.TurnOffEngine();
	BOOST_CHECK(car.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(CanMoveBackwards)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(!car.SetSpeed(20));

	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK(!car.SetSpeed(21));
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK(car.GetDirection() == CCar::BACK);
}

BOOST_AUTO_TEST_CASE(CanMoveStraight)
{
	BOOST_CHECK(!car.SetGear(1));

	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(30));
	BOOST_CHECK(car.GetDirection() == CCar::STRAIGHT);

	BOOST_CHECK(car.SetGear(4));
	BOOST_CHECK(car.SetSpeed(90));
	BOOST_CHECK(car.GetDirection() == CCar::STRAIGHT);
}

BOOST_AUTO_TEST_CASE(NeutralGearSetsWhenEngineTurnedOff)
{
	car.TurnOffEngine();
	BOOST_CHECK(car.SetGear(0));
}
BOOST_AUTO_TEST_SUITE_END()
