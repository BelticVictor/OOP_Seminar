#include <iostream>
#include <string>

using namespace std;

class date {
	int day=0;
	int month=0;
	int year=0;
public:
	date(int d, int m, int y) : day(d), month(m), year(y) {}
	date() {}
};

class Person {
protected:
	string name = "";
	date birthday;
	string pin = "";
	string* addresses = nullptr;
	int addressesCount = 0;
public:
	Person(string name, string pin, date birthday, string* addresses, int adressesCount) {
		this->name = name;
		this->pin = pin;
		this->birthday = birthday;
		this->addressesCount = adressesCount;
		this->addresses = new string[adressesCount];
		for (int i = 0; i < adressesCount; i++) {
			this->addresses[i] = addresses[i];
		}
	}
	Person() {}
	Person(const Person& p) {
		this->name = p.name;
		this->pin = p.pin;
		this->birthday = p.birthday;
		this->addressesCount = p.addressesCount;
		this->addresses = new string[p.addressesCount];
		for (int i = 0; i < p.addressesCount; i++) {
			this->addresses[i] = p.addresses[i];
		}
	}

	Person& operator=(const Person& p) {
		if (this == &p)
			return*this;
		this->name = p.name;
		this->pin = p.pin;
		this->birthday = p.birthday;
		this->addressesCount = p.addressesCount;
		delete[] this->addresses;
		this->addresses = new string[p.addressesCount];
		for (int i = 0; i < p.addressesCount; i++) {
			this->addresses[i] = p.addresses[i];
		}
		return *this;
	}

	~Person() {
		delete[] this->addresses;
	}
};

class Student:Person {
	int regNo = 0;
	double* grades = nullptr;
	int gradesCount = 0;
public:
	Student(string name, string pin, date birthday, string* addresses, int addressesCount, int regNo, double* grades, int gradesCount):Person(name,pin,birthday,addresses,addressesCount) {
		this->regNo = regNo;
		this->gradesCount = gradesCount;
		this->grades = new double[gradesCount];
		for (int i = 0; i < gradesCount; i++) {
			this->grades[i] = grades[i];
		}
		this->name = name;
	}

	Student(const Student& s) {
		this->name = s.name;
		this->pin = s.pin;
		this->addressesCount = s.addressesCount;
		this->addresses = new string[s.addressesCount];
		for (int i = 0; i < s.addressesCount; i++) {
			this->addresses[i] = s.addresses[i];
		}

		this->regNo = s.regNo;
		this->gradesCount = s.gradesCount;
		this->grades = new double[s.gradesCount];
		for (int i = 0; i < s.gradesCount; i++) {
			this->grades[i] = s.grades[i];
		}
	}

	Student& operator=(const Student& s) {
		if (this == &s)
			return*this;
		this->name = s.name;
		this->pin = s.pin;
		this->birthday = s.birthday;
		this->addressesCount = s.addressesCount;
		delete[] this->addresses;
		this->addresses = new string[s.addressesCount];
		for (int i = 0; i < s.addressesCount; i++) {
			this->addresses[i] = s.addresses[i];
		}

		this->regNo = s.regNo;
		this->gradesCount = s.gradesCount;
		delete[] this->grades;
		this->grades = new double[s.gradesCount];
		for (int i = 0; i < s.gradesCount; i++) {
			this->grades[i] = s.grades[i];
		}

		return *this;
	}

	~Student() {
		delete[] this->grades;
	}
};

class Employees:Person {
	date birthday;
	string nume;
	int pin;
	string* adresses;
	int salariu;
	string position;
};

class University {
	Student students;
	int studcount;
	Employees* empl;
	int emplcount;
};

int main() {
	date d(2, 3, 1990);
	string* adresses = new string[3];
	adresses[0] = "bucuresti";
	adresses[1] = "Moara Vlasiei";
	adresses[2] = "Arad";
	Person p("Cristoasele Ninja", "1835y9283y59823", d, adresses, 3);

	double* grades = new double[5];
	grades[0] = 9;
	grades[1] = 5;
	grades[2] = 7;
	grades[3] = 3;
	grades[4] = 6;

	string* addresses2 = new string[2];
	addresses2[0] = "Timisoara";
	addresses2[1] = "Bughea de Sus";

	date d2(5, 9, 2077);
	Student s1("Fraierica Geamantan", "25235235", d2, addresses2, 2, 123, grades, 5);
	return 0;
}