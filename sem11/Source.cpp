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

	virtual string listDetails() {
		return "I'm Person";
	}
};

class Student :public Person {
	int regNo = 0;
	double* grades = nullptr;
	int gradesCount = 0;
public:

	Student(string name, string pin, date birthday, string* addresses, int addressesCount, int regNo, double* grades, int gradesCount) :Person(name, pin, birthday, addresses, addressesCount) {
		this->regNo = regNo;
		this->gradesCount = gradesCount;
		this->grades = new double[gradesCount];
		for (int i = 0; i < gradesCount; i++) {
			this->grades[i] = grades[i];
		}
		this->name = name;
	}

	Student() {}

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
		this->listDetails();
		return *this;
	}
	string listDetails() {
		return "I'm Student";
	}

	~Student() {
		delete[] this->grades;
	}
};

class Professor :public Person {
	string title="";
public:
	Professor():Person() {}
	Professor(string name, string pin, date birthday, string* addresses, int adressesCount, string title) :Person(name, pin, birthday, addresses, addressesCount), title(title) {}
	
	string listDetails() {
		return "I'm Professor";
	}
};

class AdminPers :public Person {
	string area = "";
public:
	AdminPers() :Person() {}
	AdminPers(string name, string pin, date birthday, string* addresses, int adressesCount, string area) :Person(name, pin, birthday, addresses, addressesCount), area(area) {}

	string listDetails() {
		return "I'm AdminPers";
	}
};

class University {
	string name = "";
	string address = "";
	Student* students=nullptr;
	int studentCount = 0;
	Person** all = nullptr;
	int allCount = 0;
public:
	University() {}

	University(string name, string address, Student* student, int studentsCount) {
		this->name = name;
		this->address = address;
		this->studentCount = studentCount;
		this->students = new Student[studentsCount];
		for (int i = 0; i < studentsCount; i++) {
			this->students[i] = students[i];
		}
	}

	University(const University& copy) {
		this->name = copy.name;
		this->address = copy.address;
		this->studentCount = copy.studentCount;
		this->students = new Student[copy.studentCount];
		for (int i = 0; i < copy.studentCount; i++) {
			this->students[i] = copy.students[i];
		}
	}

	void setAll(Person** all, int allCount) {
		this->allCount = allCount;
		this->all = all;
	}

	void listAllDetails() {
		for (int i = 0; i < allCount; i++) {
			cout << this->all[i]->listDetails() << endl;
		}
	}

};

class Employee:Person {
	float salary;
public:
	Employee(string name, string pin, date birthday, string* addresses, int adressesCount, float salary) :Person(name, pin, birthday, addresses, adressesCount), salary(salary) {}

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
	Student s2("Hugh Mungus", "24553", d2, addresses2, 2, 124, grades, 5);
	Student s3("Joe", "62362346", d2, addresses2, 2, 125, grades, 5);

	Student students[3];

	students[0] = s1;
	students[1] = s2;
	students[2] = s3;


	Person* person = new Person("Pop And", "2352352352264", d2, adresses, 3);
	Person* stud = new Student("Pipirica", "2352352352264", d2, adresses, 2, 124, grades, 5);
	Person* admnPers = new AdminPers("Moderator", "2352352352264", d2, adresses, 3,"Lab");
	Person* prof = new Professor("Prof X", "2352352352264", d2, adresses, 3,"assistant");

	Person** all = new Person * [4];
	all[0] = person;
	all[1] = stud;
	all[2] = admnPers;
	all[3] = prof;
	University u1("ASE", "Bucuresti", students, 3);

	u1.setAll(all, 4);
	u1.listAllDetails();
	return 0;
}