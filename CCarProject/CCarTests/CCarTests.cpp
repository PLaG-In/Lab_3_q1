// CCarTests.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include "stdafx.h"
#include "../CCarProject/CCarSet.h"

struct TVSetFixture
{
	CCarSet car;
};

/*
����������
- ���������� �������� ���������
- ����� ���� ������� ���������
- ����� ���� �������� ���������
- � ����������� ��������� ������ ���� �� ����������� �������� � �� 0 ��������
- ��� ������ ��������� ��������� ���������� �� ������ ������
- ��������� ���������� �������� �� 0 �� 150, ����� ��������� �������
*/
BOOST_FIXTURE_TEST_SUITE(TVSet, TVSetFixture)

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
	car.TurnOnEngine();
	BOOST_CHECK(car.TurnOffEngine());
	BOOST_CHECK(!car.EngineIsTurnedOn());
}

BOOST_AUTO_TEST_CASE(IsAtChannel0WhenTurnedOff)
{
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	car.TurnOnEngine();
	car.TurnOffEngine();
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
}

BOOST_AUTO_TEST_CASE(InitiallyIsTurnedOnAtChannel1)
{
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.GetSpeed(), 1);
}

BOOST_AUTO_TEST_CASE(CanSelectChannelFrom1To99WhenIsOn)
{
	car.TurnOnEngine();

	BOOST_CHECK(!car.SetSpeed(0));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 1);

	BOOST_CHECK(car.SetSpeed(99));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 99);

	BOOST_CHECK(!car.SetSpeed(100));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 99);

	BOOST_CHECK(car.SetSpeed(1));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 1);
}

BOOST_AUTO_TEST_SUITE_END()
