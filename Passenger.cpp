#include "Passenger.h"
#include <iostream>
#include <string>

using namespace std;

Passenger::Passenger() {
	/*cout << endl << "New passenger is created!" << endl << endl;
	string name = "", surname = "", gender = "";

	cout << "Enter your name: ";
	cin >> name;
	setPassengerName(name);

	if (passengerName != "") {
		// if name is valid, ask for surname
		cout << "Enter your surname: ";
		cin >> surname;
		setPassengerSurname(surname);
	}

	if (passengerSurname != "") {
		// if surname is valid, ask for
		cout << "Enter your gender: ";
		cin >> gender;
		setPassengerGender(gender);
	}

	if (passengerGender != "") {
		cout << "Passenger is created!" << endl << endl;
	}*/
}

Passenger::Passenger(string name, string surname, string gender)
{
	setPassengerName(name);
	setPassengerSurname(surname);
	setPassengerGender(gender);
}

Passenger::~Passenger() {
	//cout << "Passenger is deleted!" << endl << endl;
}

void Passenger::setPassengerName(string name) {
	for (int i = 0; i < name.length(); i++) {
		if (name[i] >= '0' && name[i] <= '9') {
			cout << "Name cannot contain a number!" << endl;
			return;
		}
	}
	passengerName = name;
}
void Passenger::setPassengerSurname(string surname) {
	for (int i = 0; i < surname.length(); i++) {
		if (surname[i] >= '0' && surname[i] <= '9') {
			cout << "Surname cannot contain a number!" << endl;
			return;
		}
	}
	passengerSurname = surname;
}
void Passenger::setPassengerGender(string gender) {
	for (int i = 0; i < gender.length(); i++) {
		if (gender[i] >= '0' && gender[i] <= '9') {
			cout << "Gender cannot contain a number!" << endl;
			return;
		}
	}
	passengerGender = gender;
}

string Passenger::getPassengerName() const{
	return passengerName;
}
string Passenger::getPassengerSurname() const {
	return passengerSurname;
}
string Passenger::getPassengerGender() const {
	return passengerGender;
}