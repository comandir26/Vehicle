#include <vehicle/vehicle.h>
#include <stdexcept>
using namespace vehicle;

VehicleList::VehicleList() : _size(0) {}

VehicleList::VehicleList(int _size) : _size(_size), vehicles(new Vehicle[_size]) {}

VehicleList::~VehicleList() {
	delete[] vehicles;
	vehicles = nullptr;
}

int VehicleList::size() const {
	return _size;
}

Vehicle VehicleList::operator[](const int index) const {
	if (index < 0 || index >= _size) {
		throw out_of_range("[VehicleList::operator[]] Index is out of range");
	}
	return vehicles[index];
}

void VehicleList::add(const Vehicle v) {
	int _newsize = _size + 1;
	VehicleList newvehicles(_newsize);

	for (int i = 0; i < _size; i++)
	{
		newvehicles[i] = vehicles[i];
	}
	delete[] vehicles;

	newvehicles[_newsize - 1] = v;
    
	*this = newvehicles;
}

void VehicleList::insert(int index, const Vehicle v) {
	if (index < 0 || index >= _size) {
		throw out_of_range("[VehicleList::insert] Index is out of size");
	}
	for (int i = _size; i != index; i--)
	{
		vehicles[i] = vehicles[i - 1];
	}
	vehicles[index] = v;
	_size++;
}

void VehicleList::remove(int index) {
	if (index < 0 || index >= _size) {
		throw out_of_range("[VehicleList::insert] Index is out of size");
	}
	for (int i = index; i < _size-1; i++) {
		vehicles[i] = vehicles[i + 1];
	}
	_size--;
}

int vehicle::indexofminPrice(const VehicleList& vehicles, double weight, double distance) {
	int index = -1;
	double minprice = 0.0;
	for (int i = 0; i < vehicles.size(); i++) {
		double curprice = vehicles[i].priceCalculate(weight, distance);
		if (index == -1 || curprice<minprice) {
			index = i;
			minprice = curprice;
		}
	}
	return index;
}