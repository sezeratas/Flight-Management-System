#pragma once
#include <iostream>

using namespace std;

class Passenger {
private:
	string passengerName;
	string passengerSurname;
	string passengerGender;
public:
	Passenger();

	Passenger(string name, string surname, string gender);

	~Passenger();

	void setPassengerName(string name);

	void setPassengerSurname(string surname);

	void setPassengerGender(string gender);

	string getPassengerName() const;

	string getPassengerSurname() const;

	string getPassengerGender() const;
};
