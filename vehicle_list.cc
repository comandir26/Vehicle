#include <vehicle/vehicle.h>
#include <stdexcept>
#include <algorithm>
using namespace std;
using namespace vehicle;

VehicleList::VehicleList() : vehicles(nullptr), capacity(0), size(0) {}

VehicleList::VehicleList(const VehicleList& rhs) : vehicles(new const Vehicle*[rhs.size]), capacity(rhs.capacity), size(rhs.size) {
	for (size_t i = 0; i < size; i++)
	{
		vehicles[i] = new const Vehicle(*rhs.vehicles[i]);
	}	
}

void VehicleList::swap(VehicleList& rhs) noexcept {
	std::swap(vehicles, rhs.vehicles);
	std::swap(capacity, rhs.capacity);
	std::swap(size, rhs.size);
}

VehicleList& VehicleList::operator=(VehicleList rhs) {
	swap(rhs);
	return *this;
}

VehicleList::~VehicleList(){
	for (size_t i = 0; i < size; i++)
	{
		delete vehicles[i];
	}
	delete[] vehicles;
}

int VehicleList::get_size() const {
	return size;
}

int VehicleList::get_capacity() const {
	return capacity;
}

const Vehicle* VehicleList::operator[](const int index) const {
	if (index < 0 || index >= size) {
		throw out_of_range("[VehicleList::operator[]] Index is out of range");
	}
	return vehicles[index];
}

void VehicleList::add(const Vehicle& v) {
	auto dynv = new const Vehicle(v);
	if (size + 1 > capacity) {
		capacity += GROWTH;
		auto copy = new const Vehicle* [capacity];
		if (copy == nullptr) {
			cout << "Недостаточно памяти.";
			return;
		}
		for (size_t i = 0; i < size; i++)
		{
			copy[i] = new const Vehicle(*vehicles[i]);
		}
		for (size_t i = 0; i < size; i++)
		{
			delete vehicles[i];
		}
		delete[] vehicles;
		copy[size] = dynv;
		vehicles = copy;
		size++;
	}
	else {
		vehicles[size] = dynv;
		size++;
	}

}

void VehicleList::insert(int index, const Vehicle& v) {
	if (index < 0 || index >= size) {
		throw out_of_range("[VehicleList::insert] Index is out of size");
	}
	auto dynv = new const Vehicle(v);
	if (size == capacity) {
		capacity += GROWTH;
		const auto copy = new const Vehicle* [capacity];
		for (size_t i = 0; i < size; i++)
		{
			copy[i] = new const Vehicle(*vehicles[i]);
		}
		for (size_t i = 0; i < size; i++)
		{
			delete vehicles[i];
		}
		delete[] vehicles;
		vehicles = copy;
	}
	for (size_t i = size; i != index; i--)
	{
		vehicles[i] = vehicles[i - 1];
	}
	vehicles[index] = dynv;
	size++;
}

void VehicleList::remove(int index) {
	if (index < 0 || index >= size) {
		throw out_of_range("[VehicleList::insert] Index is out of size");
	}
	delete vehicles[index];
	for (int i = index; i < size-1; i++) {
		vehicles[i] = vehicles[i + 1];
	}
	size--;
}

int vehicle::index_minprice(const VehicleList& vehicles, double weight, double distance) {
	int index = -1;
	double minprice = 0.0;
	for (int i = 0; i < vehicles.get_size(); i++) {
		double curprice = vehicles[i]->price_calculate(weight, distance);
		if (index == -1 || curprice<minprice) {
			index = i;
			minprice = curprice;
		}
	}
	return index;
}