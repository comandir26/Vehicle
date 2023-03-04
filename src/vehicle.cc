#include <vehicle/vehicle.h>
#include <cmath> 
#include <stdexcept>

using namespace vehicle;

Vehicle Vehicle::create_air(string model, int tariff, EngineforAir typeofengine) {
	return Vehicle(Type::air, model, tariff, typeofengine);
}

Vehicle Vehicle::create_railway(string model, int tariff) {
	return Vehicle(Type::railway, model, tariff);
}

Vehicle Vehicle::create_water(string model, int tariff, double coefficient) {
	return Vehicle(Type::water, model, tariff, coefficient);
}

Vehicle::Vehicle(Type type, string model, int tariff) : type(type), model(model), tariff(tariff), typeofengine(EngineforAir::reactive), coefficient(1) {}

Vehicle::Vehicle(Type type, string model, int tariff, EngineforAir typeofengine) :type(type), model(model), tariff(tariff), typeofengine(typeofengine), coefficient(1) {}

Vehicle::Vehicle(Type type, string model, int tariff, double coefficient) : type(type), model(model), tariff(tariff),typeofengine(EngineforAir::reactive), coefficient(coefficient) {}

Type Vehicle::get_type() const {
	return type;
}

string Vehicle::get_model() const {
	return model;
}

int Vehicle::get_tariff() const {
	return tariff;
}

EngineforAir Vehicle::get_engine() const {
	if (type == Type::air) return typeofengine;
	else throw runtime_error("[Vehicle::get_engine] Invalid vehicle type");
}

double Vehicle::get_coefficient() const {
	if(type == Type::water) 
		return coefficient;
	else 
		throw runtime_error("[Vehicle::get_coefficient] Invalid vehicle type");
	
}

double Vehicle::priceCalculate(double weight, double distance) const {
	switch (type) {
		case Type::railway:
			return tariff * weight * distance;
		case Type::water:
			return tariff * weight * distance * pow(coefficient, distance / 5000);	
		case Type::air:
			if (typeofengine == EngineforAir::turboprop) {
				if (distance < 1000) {
					return tariff * weight * distance * 0.5;
				}
				else {
					return tariff * weight * distance * 1.5;
				}
			}
			else {
				if (distance < 1000) {
					return tariff * weight * distance * 1.5;
				}
				else {
					return tariff * weight * distance * 0.5;
				}
			}
		default:
			throw runtime_error("[Vehicle::priceCalculate] Invalid vehicle type");
	}
}