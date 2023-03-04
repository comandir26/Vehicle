#pragma once
#include <string>
using namespace std;

namespace vehicle {
	enum class Type {
		railway,
		water,
		air
	};
	enum class EngineforAir {
		turboprop,
		reactive
	};
	class Vehicle {
	private:
		Type type;

		string model;

		int tariff;

		EngineforAir typeofengine;//только для воздушного

		double coefficient;//только для водного 

		Vehicle(Type type, string model, int tariff);

		Vehicle(Type type, string model, int tariff, EngineforAir typeofengine);

		Vehicle(Type type, string model, int tariff, double coefficient);

	public:
		static Vehicle create_railway(string model, int tariff);

		static Vehicle create_air(string model, int tariff, EngineforAir typeofengine);

		static Vehicle create_water(string model, int tariff, double coefficient);

		//т.к в vehicle_list стат массив
		Vehicle();

		//геттеры 

		Type get_type() const;

		string get_model() const;

		int get_tariff() const;

		EngineforAir get_engine() const;

		double get_coefficient() const;

		double priceCalculate(double weight, double distance) const;
	};

	 class VehicleList {

	private:

		Vehicle* vehicles = nullptr;

		int _size;

	public:

		VehicleList();

		VehicleList(int _size);

		int size() const;

		Vehicle operator[](int index) const;

		void add(const Vehicle v);

		void insert(int index, const Vehicle v);

		void remove(int index);

		~VehicleList();
	};

	 int indexofminPrice(const VehicleList& vehicles, double weight, double distance);
}