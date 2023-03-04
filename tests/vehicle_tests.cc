#include <gtest/gtest.h>
#include <vehicle/vehicle.h>
using namespace vehicle;

TEST(Getters, air) {
	const auto plane = Vehicle::create_air("��-57", 25, EngineforAir::reactive);
	const auto type = plane.get_type();
	const auto model = plane.get_model();
	const auto tariff = plane.get_tariff();
	const auto engine = plane.get_engine();
	ASSERT_EQ(type, Type::air);
	ASSERT_EQ(model, "��-57");
	ASSERT_EQ(tariff, 25);
	ASSERT_EQ(engine, EngineforAir::reactive);
	ASSERT_THROW(plane.get_coefficient(), runtime_error);
}

TEST(PriceCalculate, air) {
	const auto plane = Vehicle::create_air("��-57", 25, EngineforAir::reactive);
	double price = plane.priceCalculate(100, 250.37);//���� 100 �� �� 250.37 ��
	ASSERT_DOUBLE_EQ(price, 938887.5);
}

TEST(PriceCalculate, water) {
	const auto ship = Vehicle::create_water("Eclipse", 35, 0.9);
	double price = ship.priceCalculate(100, 500);//���� 100 �� �� 500 ��
	ASSERT_NEAR(price, 1731658.7018, 0.1);
}

TEST(PriceCalculate, railway) {
	const auto train = Vehicle::create_railway("��������", 15);
	double price = train.priceCalculate(35, 540);//���� 35 �� �� 540 ��
	ASSERT_DOUBLE_EQ(price, 283500);
}

