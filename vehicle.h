#pragma once
#include <string>
#include <iostream>

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

		std::string model;

		int tariff;

		EngineforAir typeofengine;//только для воздушного

		double coefficient;//только для водного 

	public:		
		
		Vehicle();

		Vehicle(Type type, std::string model, int tariff);

		Vehicle(Type type, std::string model, int tariff, EngineforAir typeofengine);

		Vehicle(Type type, std::string model, int tariff, double coefficient);
	
		static Vehicle create_railway(std::string model, int tariff);

		static Vehicle create_air(std::string model, int tariff, EngineforAir typeofengine);

		static Vehicle create_water(std::string model, int tariff, double coefficient);

		Type get_type() const;

		std::string get_model() const;

		int get_tariff() const;

		EngineforAir get_engine() const;

		double get_coefficient() const;
		
		double price_calculate(double weight, double distance) const;
	};

	 std::ostream& operator<<(std::ostream& stream, const Vehicle& v);

	 class VehicleList {
	 public:
		 static const int GROWTH = 3;
	 private:
		 const Vehicle**  vehicles;

		 int capacity;

		 int size;
	 public:

		VehicleList();

		VehicleList(const VehicleList& rhs);

		void swap(VehicleList& rhs) noexcept;

		VehicleList& operator=(VehicleList rhs);

		const Vehicle* operator[](int index) const;

		int get_size() const;

		int get_capacity() const;

		void add(const Vehicle& v);

		void insert(int index, const Vehicle& v);

		void remove(int index);

		~VehicleList();
	};

	 int index_minprice(const VehicleList& vehicles, double weight, double distance);
}