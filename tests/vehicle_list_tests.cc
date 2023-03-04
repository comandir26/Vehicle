#include <gtest/gtest.h>
#include <vehicle/vehicle.h>
using namespace vehicle;
/*
TEST(VehicleListTests, CapacityCheck) {
	VehicleList vehicles;
	Vehicle veh = Vehicle::create_air("Ту-95", 500, EngineforAir::turboprop);
	for (int i = 0; i < VehicleList::CAPACITY; i++) {
		vehicles.add(veh);
	}
	ASSERT_THROW(vehicles.add(veh), runtime_error);
}

TEST(IndexOfMinPrice, SizeNull) {
	VehicleList vehicles;
	//не будем добавлять элементы в массив, поэтому size=0
	int index = indexofminPrice(vehicles, 0, 0);
	ASSERT_EQ(index, -1);
}

TEST(IndexOfMinPrice, WandD1) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));//минимальная цена
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));
	vehicles.add(Vehicle::create_railway("Ласточка", 30));
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.94));
	const auto index = indexofminPrice(vehicles, 500, 350);//500 кг и 350 км
	ASSERT_EQ(index, 0);
}

TEST(IndexOfMinPrice, WandD2) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));//минимальная цена
	vehicles.add(Vehicle::create_railway("Ласточка", 30));
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.9));
	const auto index = indexofminPrice(vehicles, 10, 1320);//10 кг и 350 км
	ASSERT_EQ(index, 1);
}

TEST(Remove, DeleteElement) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));//минимальная цена
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));
	vehicles.add(Vehicle::create_railway("Ласточка", 30));
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.94));
	vehicles.add(Vehicle::create_air("Су-57", 25, EngineforAir::reactive));
	const auto typebefore = vehicles[2].get_type();
	const auto sizebefore = vehicles.Size();
	ASSERT_EQ(typebefore, Type::railway);
	ASSERT_EQ(sizebefore, 5);
	vehicles.remove(2);
	const auto typeafter = vehicles[2].get_type();
	const auto sizeafter = vehicles.Size();
	ASSERT_EQ(typeafter, Type::water);
	ASSERT_EQ(sizeafter, 4);
}

TEST(Remove, OutOfSize) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));//минимальная цена
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));
	vehicles.add(Vehicle::create_railway("Ласточка", 30));
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.94));
	vehicles.add(Vehicle::create_air("Су-57", 25, EngineforAir::reactive));
	ASSERT_THROW(vehicles.remove(5), out_of_range);
}

TEST(Insert, middle) {
	VehicleList vehicles;

	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));//минимальная цена
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.94));
	vehicles.add(Vehicle::create_air("Су-57", 25, EngineforAir::reactive));
	vehicles.add(Vehicle::create_railway("Ласточка", 30));

	const auto typebefore = vehicles[2].get_type();

	ASSERT_EQ(typebefore, Type::water);

	const auto veh = Vehicle::create_air("Су-57", 25, EngineforAir::reactive);

	vehicles.insert(2, veh);

	const auto typeafter = vehicles[2].get_type();
	
	ASSERT_EQ(typeafter, Type::air);

	const auto typeof3 = vehicles[3].get_type();

	ASSERT_EQ(typeof3, Type::water);
}

TEST(Insert, beginning) {
	VehicleList vehicles;

	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));//минимальная цена
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("Су-57", 25, EngineforAir::reactive));
	vehicles.add(Vehicle::create_railway("Ласточка", 30));
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.94));

	const auto typebefore = vehicles[0].get_type();

	ASSERT_EQ(typebefore, Type::air);

	const auto veh = Vehicle::create_railway("Ласточка", 30);

	vehicles.insert(0, veh);

	const auto typeafter = vehicles[0].get_type();
	
	ASSERT_EQ(typeafter, Type::railway);
	
	const auto typeofend = vehicles[5].get_type();
	
	ASSERT_EQ(typeofend, Type::water);
}*/
TEST(Add, JustAdd) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	const auto _size = vehicles.size();
	ASSERT_EQ(_size, 5);
}
TEST(Destruct, 1) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
}

