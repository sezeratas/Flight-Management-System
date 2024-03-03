#include <iostream>
#include <string>
#include <algorithm>
#include "Flight.h"

using namespace std;

Flight::Flight(string flightNo, string destination, vector <Passenger> passengerV) {
	this -> flightNo = flightNo;
	this -> destination = destination;
	this -> passengerVector = passengerV;
	//this ->getPassengerPVector().reserve(maxSeats);
}

Flight::Flight(string flightNo, string destination) {
	this->flightNo = flightNo;
	this->destination = destination;
	//passengerVector = vector<Passenger>(40);
}

Flight::Flight() {
	this->flightNo = "";
	this->destination = "";
	//this->getPassengerPVector().reserve(maxSeats);
}

bool Flight::ReserveSeat(Passenger& passenger, string number) {
	int numberInt = 0;
	if (this->currentPassenger < this->maxSeats) {
		for (int i = 0; i < this->currentPassenger; i++) {
			if (this->passengerVector[i].getPassengerName() == passenger.getPassengerName()) {
				cout << "You have already reserved a seat!" << endl;
				return 0;
			}
		}
		if(number[1] == 'A'){
			numberInt = ((number[0]-'0') - 1) * 4;
		}
		else if (number[1] == 'B') {
			numberInt = ((number[0] - '0') - 1) * 4 + 1;
		}
		else if (number[1] == 'C') {
			numberInt = ((number[0] - '0') - 1) * 4 + 2;
		}
		else if (number[1] == 'D') {
			numberInt = ((number[0] - '0') - 1) * 4 + 3;
		}

		passengerVector.insert(passengerVector.begin()+numberInt, passenger);

		currentPassenger++;

		cout << "Reservation is successful!" << endl;
		return 1;
	}
	else{
		cout << "The flight is full!" << endl;
		return 0;
	}
}

bool Flight::CancelReservation(const Passenger& passenger) {
	for (int i = 0; i < passengerVector.size(); i++) {
		if (passengerVector[i].getPassengerName() == passenger.getPassengerName()) {
			currentPassenger--;
			delete &passengerVector[i];
			passengerVector.erase(passengerVector.begin() + i);
			cout << "Cancellation is successful!" << endl;
			return 1;
		}
		else {
			cout << "Passenger does not found!" << endl;
			return 0;
		}
	}
}

int Flight::numberOfPassengers() const{
	return currentPassenger;
}

void Flight::DisplayPassengers(){

	/*sort with seat number
	for (int i = 0; i < sizeof(passengerList)/sizeof(string); i++) {
		cout << i + 1 << "'th seat: " << passengerList[i] << endl;
	}*/

	vector <string> copyPassengerV;

	for (int i = 0; i < passengerVector.size(); i++) {
		copyPassengerV.push_back(passengerVector[i].getPassengerSurname());
	}

	sort(copyPassengerV.begin(), copyPassengerV.end());

	for (int i = 0; i < copyPassengerV.size(); i++) {
		cout << i + 1 << copyPassengerV[i] << endl;
	}
}

bool Flight::IsFlyingTo(const string& destination) const{
	if (this->destination == destination) {
		return 1;
	}
	else {
		return 0;
	}
}

string Flight::getFlightNo() const {
	return flightNo;
}

string Flight::getDestination() const {
	return destination;
}

//int Flight::getCurrentPassenger() const {
//	return currentPassenger;
//}

int Flight::getMaxSeats() const {
	return maxSeats;
}

vector<Passenger> Flight::getPassengerVector() const {
	return passengerVector;
}

vector<Passenger*> Flight::getPassengerPVector() const{
	return passengerPVector;
}

void Flight::setPassengerVector(Passenger passengerV, int n) {
	this->passengerVector[n] = passengerV;
}

/*void Flight::setPassengerVector(vector<Passenger> passengerV) {
	this->passengerVector = passengerV;
}*/