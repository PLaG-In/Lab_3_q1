// CCarTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "stdafx.h"
#include "../CCarProject/CCar.h"

struct CarSetFixture
{
	CCar car;
};

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
	BOOST_CHECK(!car.TurnOnEngine());
	BOOST_CHECK(car.EngineIsTurnedOn());
}

BOOST_AUTO_TEST_CASE(CantBeTurnedOffInTheseSituations)
{
	car.TurnOnEngine();
	car.SetGear(1);
	BOOST_CHECK(!car.TurnOffEngine());

	car.SetSpeed(16);
	BOOST_CHECK(!car.TurnOffEngine());

	car.SetSpeed(0);
	car.SetGear(-1);
	car.SetSpeed(5);
	BOOST_CHECK(!car.TurnOffEngine());

	car.SetSpeed(0);
	car.SetGear(0);
	car.TurnOffEngine();
	BOOST_CHECK(!car.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(CanMoveBackwards)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
	BOOST_CHECK(!car.SetSpeed(20));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 20);

	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK_EQUAL(car.GetGear(), -1);
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK_EQUAL(car.GetSpeed(),20);
	BOOST_CHECK(car.GetDirection() == CCar::BACK);
}

BOOST_AUTO_TEST_CASE(CanMoveStraight)
{
	BOOST_CHECK(!car.SetGear(1));

	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK_EQUAL(car.GetGear(), 1);
	BOOST_CHECK(car.SetSpeed(30));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 30);
	BOOST_CHECK(car.GetDirection() == CCar::STRAIGHT);

	BOOST_CHECK(car.SetGear(4));
	BOOST_CHECK_EQUAL(car.GetGear(), 4);
	BOOST_CHECK(car.SetSpeed(90));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 90);
	BOOST_CHECK(car.GetDirection() == CCar::STRAIGHT);
}

BOOST_AUTO_TEST_CASE(CanChangingGearAndSpeed)
{
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK_EQUAL(car.GetGear(), -1);
	BOOST_CHECK(car.SetSpeed(10));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 10);
	BOOST_CHECK(car.SetSpeed(21));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);

	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
	BOOST_CHECK(car.SetSpeed(10));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 10);

	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK_EQUAL(car.GetGear(), 1);
	BOOST_CHECK(car.SetSpeed(21));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 20);

	BOOST_CHECK(car.SetGear(2));
	BOOST_CHECK_EQUAL(car.GetGear(), 2);
	BOOST_CHECK(car.SetSpeed(51));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK(car.SetSpeed(40));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 40);

	BOOST_CHECK(car.SetGear(3));
	BOOST_CHECK_EQUAL(car.GetGear(), 3);
	BOOST_CHECK(car.SetSpeed(61));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK(car.SetSpeed(50));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 50);

	BOOST_CHECK(car.SetGear(4));
	BOOST_CHECK_EQUAL(car.GetGear(), 4);
	BOOST_CHECK(car.SetSpeed(91));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK(car.SetSpeed(70));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 70);

	BOOST_CHECK(car.SetGear(5));
	BOOST_CHECK_EQUAL(car.GetGear(), 5);
	BOOST_CHECK(car.SetSpeed(151));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK(car.SetSpeed(100));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 100);

	BOOST_CHECK(car.SetGear(6));
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
	BOOST_CHECK(car.SetGear(-2));
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
}

BOOST_AUTO_TEST_CASE(NeutralGearSetsWhenEngineTurnedOff)
{
	car.TurnOffEngine();
	BOOST_CHECK(car.SetGear(0));
}
BOOST_AUTO_TEST_SUITE_END()
