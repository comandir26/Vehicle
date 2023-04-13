#include <gtest/gtest.h>
#include <vehicle/vehicle.h>
using namespace vehicle;
using namespace std;

TEST(IndexOfMinPrice, SizeNull) {
	VehicleList vehicles;
	int index = index_minprice(vehicles, 100, 100);
	ASSERT_EQ(index, -1);
}

TEST(IndexOfMinPrice, WandD1) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));//минимальная цена
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));
	vehicles.add(Vehicle::create_railway("Ласточка", 30));
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.94));
	const auto index = index_minprice(vehicles, 500, 350);//500 кг и 350 км
	ASSERT_EQ(index, 0);
}

TEST(IndexOfMinPrice, WandD2) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));//минимальная цена
	vehicles.add(Vehicle::create_railway("Ласточка", 30));
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.9));
	const auto index = index_minprice(vehicles, 10, 1320);//10 кг и 350 км
	ASSERT_EQ(index, 1);
}

TEST(Remove, DeleteElement) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));//[0]
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));//[1]
	vehicles.add(Vehicle::create_railway("Ласточка", 30));//[2]
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.94));//[3]
	vehicles.add(Vehicle::create_air("Су-57", 25, EngineforAir::reactive));//[4]
	const auto typebefore = vehicles[2]->get_type();
	const auto sizebefore = vehicles.get_size();//5
	vehicles.remove(2);
	const auto typeafter = vehicles[2]->get_type();
	const auto sizeafter = vehicles.get_size();
	ASSERT_EQ(typebefore, Type::railway);
	ASSERT_EQ(sizebefore, 5);
	ASSERT_EQ(typeafter, Type::water);
	ASSERT_EQ(sizeafter, 4);
}

TEST(Remove, OutOfSize) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));//[0]
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));//[1]
	vehicles.add(Vehicle::create_railway("Ласточка", 30));//[2]
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.94));//[3]
	vehicles.add(Vehicle::create_air("Су-57", 25, EngineforAir::reactive));//[4]
	ASSERT_THROW(vehicles.remove(5), out_of_range);
}

TEST(Insert, middle) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));//[0]
	vehicles.add(Vehicle::create_railway("Ласточка", 30));;//[1]
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.94));//[2]
	const auto typebefore = vehicles[1]->get_type();
	const auto veh = Vehicle::create_air("Су-57", 25, EngineforAir::reactive);
	vehicles.insert(1, veh);
	const auto typeafter = vehicles[1]->get_type();
	const auto typeof2 = vehicles[2]->get_type();
	const auto size = vehicles.get_size();
	const auto capacity = vehicles.get_capacity();
	ASSERT_EQ(typebefore, Type::railway);
	ASSERT_EQ(typeafter, Type::air);
	ASSERT_EQ(typeof2, Type::railway);
	ASSERT_EQ(size, 4);
	ASSERT_EQ(capacity, 6);
}

TEST(Insert, beginning) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("Су-57", 25, EngineforAir::reactive));
	vehicles.add(Vehicle::create_railway("Ласточка", 30));
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.94));
	const auto typebefore = vehicles[0]->get_type();
	const auto veh = Vehicle::create_railway("Ласточка", 30);
	vehicles.insert(0, veh);
	const auto typeafter = vehicles[0]->get_type();
	const auto typeofend = vehicles[5]->get_type();
	const auto size = vehicles.get_size();
	const auto capacity = vehicles.get_capacity();
	ASSERT_EQ(typebefore, Type::air);
	ASSERT_EQ(typeafter, Type::railway);	
	ASSERT_EQ(typeofend, Type::water);
	ASSERT_EQ(size, 6);
	ASSERT_EQ(capacity, 6);
}

TEST(Insert, end) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("Ту-95", 20, EngineforAir::turboprop));//[0]
	vehicles.add(Vehicle::create_air("Ан-225", 20, EngineforAir::reactive));//[1]
	vehicles.add(Vehicle::create_air("Су-57", 25, EngineforAir::reactive));//[2]
	vehicles.add(Vehicle::create_railway("Ласточка", 30));//[3]
	vehicles.add(Vehicle::create_water("Eclipse", 40, 0.94));//[4]
	vehicles.add(Vehicle::create_railway("Ласточка", 30));//[5]->[6]
	const auto typebefore = vehicles[5]->get_type();
	const auto veh = Vehicle::create_air("Су-57", 25, EngineforAir::reactive);//[5]
	vehicles.insert(5, veh);
	const auto typeafter = vehicles[5]->get_type();
	const auto typeofend = vehicles[6]->get_type();
	const auto size = vehicles.get_size();
	const auto capacity = vehicles.get_capacity();
	ASSERT_EQ(typebefore, Type::railway);
	ASSERT_EQ(typeafter, Type::air);
	ASSERT_EQ(typeofend, Type::railway);
	ASSERT_EQ(size, 7);
	ASSERT_EQ(capacity, 9);
}

TEST(Add, JustAdd) {
	VehicleList vehicles;
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	vehicles.add(Vehicle::create_air("МИГ-29", 100, EngineforAir::reactive));
	const auto size = vehicles.get_size();
	const auto capacity = vehicles.get_capacity();
	ASSERT_EQ(size, 4);
	ASSERT_EQ(capacity, 6);
}



	



