#include <vehicle/vehicle.h>
#include <cmath> 
#include <stdexcept>
#include <iostream>

using namespace std;
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

Vehicle::Vehicle() :type(Type::air), model("Ñó-57"), tariff(1000), typeofengine(EngineforAir::reactive), coefficient(1) {}

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

double Vehicle::price_calculate(double weight, double distance) const{
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

ostream& vehicle::operator<<(ostream& stream, const Vehicle& v) {
	string type;
	switch (v.get_type()) {
	case Type::railway:
		type = "railway";
		break;
	case Type::water:
		type = "water";
		break;
	case Type::air:
		type = "air";
		break;
	default:
		break;
	}
	stream << "Type: " << type << endl;
	stream << "Model: " << v.get_model() << endl;
	stream << "Tariff: " << v.get_tariff() << endl;
	if (v.get_type() == Type::air) {
		string strengine;
		switch (v.get_engine()) {
		case EngineforAir::turboprop:
			strengine = "turboprop";
			break;
		case EngineforAir::reactive:
			strengine = "reactive";
			break;
		default:
			break;
		}
		stream << "Type of engine: " << strengine << endl;
	}
	if (v.get_type() == Type::water) {
		stream << "Coefficient: " << v.get_coefficient() << endl;
	}
	return stream;
}