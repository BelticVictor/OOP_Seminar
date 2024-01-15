#include <iostream>
#include <string>

using namespace std;

class date {
	int day = 0;
	int month = 0;
	int year = 0;
public:
	date(int d, int m, int y) : day(d), month(m), year(y) {}
	date() {}
};

class Product {
	string name="";
	string description="";
	int price = 0;
public:
	Product() {}
	Product(string name, string description,int price) :name(name), description(description),price(price) {}

	virtual string listDetails() {
		return "This is a Product";
	}
};

class Electronics:Product {
	string technicalSpecs;
	date garantie;
public:
	Electronics() {}
	Electronics(string name, string description,int price, string technicalSpecs, date garantie) :Product(name, description,price), technicalSpecs(technicalSpecs), garantie(garantie) {}

	string listDetails() {
		return "This is an Electronic Product";
	}
};

class Goods :Product {
	string* ingredients;
	int ingredientsCount;
	date expDate;
public:
	Goods() {}
	Goods(string name, string description, int price, string* ingredients, int ingredientsCount, date expDate) :Product(name, description,price), ingredientsCount(ingredientsCount), expDate(expDate) {
		ingredients = new string[ingredientsCount];
		for (int i = 0; i < ingredientsCount; i++) {
			this->ingredients[i] = ingredients[i];
		}
	}

	string listDetails() {
		return "This is a Good";
	}
};

class Vehicle :Product {
	string brand;
public:
	Vehicle() {}
	Vehicle(string name, string description, int price, string brand) :Product(name, description, price), brand(brand) {}

	string listDetails() {
		return "This is a Vehicle";
	}
};

class Car :Vehicle {
	int seats=0;
public:
	Car() {}
	Car(string name, string description, int price, string brand, int seats) :Vehicle(name, description, price,brand), seats(seats) {}
	string listDetails() {
		return "This is a Car";
	}
};

class Bus :Vehicle {
	int seats = 0;
public:
	Bus() {}
	Bus(string name, string description, int price, string brand, int seats) :Vehicle(name, description, price, brand), seats(seats) {}
	string listDetails() {
		return "This is a Bus";
	}
};

class Truck :Vehicle {
	int carryweight = 0;
public:
	Truck() {}
	Truck(string name, string description, int price, string brand, int carryweight) :Vehicle(name, description, price, brand), carryweight(carryweight) {}
	string listDetails() {
		return "This is a Truck";
	}
};

void main() {

}