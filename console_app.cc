
#include<vehicle/vehicle.h>
#include<iostream>
#include<clocale>
#include<conio.h>

using namespace vehicle;
using namespace std;

void input_vehicle(VehicleList& vehicles) {
	string type;
	cout << "Введите тип транспорта(railway, water, air): ";
	cin >> type;
	if (type == "railway") {
		string model;
		int tariff;
		cout << "Введите модель железнодорожного транспорта: ";
		cin >> model;
		cout << "Введите тариф: ";
		cin >> tariff;
		vehicles.add(Vehicle::create_railway(model, tariff));
	}
	if (type == "water") {
		string model;
		int tariff;
		double coefficient;
		cout << "Введите модель водного транспорта: ";
		cin >> model;
		cout << "Введите тариф: ";
		cin >> tariff;
		cout << "Введите значение поощряющего коэффициаента(0.9<=coef<=1): ";
		cin >> coefficient;
		vehicles.add(Vehicle::create_water(model, tariff, coefficient));
	}
	if (type == "air") {
		string model;
		int tariff;
		string strengine;
		cout << "Введите модель воздушного транспорта: ";
		cin >> model;
		cout << "Введите тариф: ";
		cin >> tariff;
		cout << "Введите тип двигателя(turboprop, reactive): ";
		cin >> strengine;
		if(strengine=="turboprop") vehicles.add(Vehicle::create_air(model, tariff, EngineforAir::turboprop));
		else vehicles.add(Vehicle::create_air(model, tariff, EngineforAir::reactive));
	}
	return;
}

void input_vehicleindex (VehicleList& vehicles) {
	int index;
	if (vehicles.get_size() == 0) {
		cout << "Список пуст" << endl;
		system("pause");
		return;
	}
	do
	{
		system("cls");
		cout << "Введите корректный индекс для вставки элемента: ";
		cin >> index;
	} while (index < 0 || index >= vehicles.get_size());
	string type;
	cout << "Введите тип транспорта(railway, water, air): ";
	cin >> type;
	if (type == "railway") {
		string model;
		int tariff;
		cout << "Введите модель железнодорожного транспорта: ";
		cin >> model;
		cout << "Введите тариф: ";
		cin >> tariff;
		vehicles.insert(index, Vehicle::create_railway(model, tariff));
	}
	if (type == "water") {
		string model;
		int tariff;
		double coefficient;
		cout << "Введите модель водного транспорта: ";
		cin >> model;
		cout << "Введите тариф: ";
		cin >> tariff;
		cout << "Введите значение поощряющего коэффициаента(0.9<=coef<=1): ";
		cin >> coefficient;
		vehicles.insert(index, Vehicle::create_water(model, tariff, coefficient));
	}
	if (type == "air") {
		string model;
		int tariff;
		string strengine;
		cout << "Введите модель воздушного транспорта: ";
		cin >> model;
		cout << "Введите тариф: ";
		cin >> tariff;
		cout << "Введите тип двигателя(turboprop, reactive): ";
		cin >> strengine;
		if (strengine == "turboprop") vehicles.insert(index, Vehicle::create_air(model, tariff, EngineforAir::turboprop));
		else vehicles.insert(index, Vehicle::create_air(model, tariff, EngineforAir::reactive));
	}
	return;
}

void delete_index(VehicleList& vehicles){
	if (vehicles.get_size() == 0) {
		cout << "Список пуст" << endl;
		system("pause");
		return;
	}
	int index;
	do
	{
		system("cls");
		cout << "Введите корректный индекс для удаления объекта: ";
		cin >> index;
	} while (index < 0 || index >= vehicles.get_size());
	vehicles.remove(index);
	return;
}

void find_minprice(VehicleList& vehicles) {
	if (vehicles.get_size() == 0) {
		cout << "Список пуст" << endl;
		system("pause");
		return;
	}
	double weight, distance;
	cout << "Введите массу груза: ";
	cin >> weight;
	cout << "Введите дистанцию транспортировки: ";
	cin >> distance;
	int index = index_minprice(vehicles, weight, distance);
	cout << endl;
	cout << "Минимальная цена транспортировки у объекта с индексом: " << index << endl;
	if (index == -1) return;
	cout << endl;
	cout << *vehicles[index] << endl;
	system("pause");
}

void show_menu(int choise) {
	system("cls");
	cout << ((choise == 1) ? ">" : " ") << "1. Вывести список на экран" << endl;
	cout << ((choise == 2) ? ">" : " ") << "2. Вставить элемент в конец списка" << endl;
	cout << ((choise == 3) ? ">" : " ") << "3. Вставить элемент в список по указанному индексу" << endl;
	cout << ((choise == 4) ? ">" : " ") << "4. Удалить элемент из списка по указанному индексу" << endl;
	cout << ((choise == 5) ? ">" : " ") << "5. Поиск объекта в списке с минимальной ценой траспортировки" << endl;
	cout << ((choise == 6) ? ">" : " ") << "6. Выход" << endl;
	return;
}

int get_key() {
	int key = _getch();
	if (key == 0 || key == 224) key = _getch();
	return key;
}

int do_menu(int choise, int key) {
	if (choise == 1 && key == 72) {
		return choise;
	}
	if (choise == 6 && key == 80) {
		return choise;
	}
	switch (key)
	{
	case 80:
		choise++;
		break;
	case 72:
		choise--;
		break;
	case 13:
		break;
	default:
		break;
	}
	return choise;
}

int main() {
	setlocale(LC_ALL, "Russian");
	VehicleList vehicles;
	int choise = 1;
	int key;
	do
	{
		do
		{
			show_menu(choise);
			key = get_key();
			choise = do_menu(choise, key);
		} while (key != 13);

		switch (choise)
		{
		case 1:
			system("cls");
			for (int i = 0; i < vehicles.get_size(); i++)
			{
				cout << "Index: " << i << endl;
				cout << *vehicles[i] << endl;
			}
			if (vehicles.get_size() == 0) cout << "Список пуст"<< endl;
			system("pause");
			break;
		case 2:
			system("cls");
			input_vehicle(vehicles);
			break;
		case 3:
			system("cls");
			input_vehicleindex(vehicles);
			break;
		case 4:
			system("cls");
			delete_index(vehicles);
			break;
		case 5:
			system("cls");
			find_minprice(vehicles);
			break;
		case 6:
			return 0;
		default:
			break;
		}
	} while (true);
}