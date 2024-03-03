#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Passenger.h"  // Include the header file for the Passenger class

using namespace std;

class Flight {
private:
	string flightNo;
	string destination;
	int maxSeats = 40;
	int currentPassenger = 0;
	vector <Passenger> passengerVector = vector<Passenger>(41);
	vector <Passenger*> passengerPVector;
public:
	Flight(string flightNo, string destination, vector <Passenger> passengerV);

	Flight(string flightNo, string destination);

	Flight();

	bool ReserveSeat(Passenger& passenger, string number);

	bool CancelReservation(const Passenger& passenger);

	int numberOfPassengers() const;

	void DisplayPassengers();

	bool IsFlyingTo(const string& destination) const;


	string getFlightNo() const;

	string getDestination() const;

	//int getCurrentPassenger() const;

	int getMaxSeats() const;

	vector<Passenger> getPassengerVector() const;

	vector<Passenger*> getPassengerPVector() const;

	void setPassengerVector(Passenger passengerVector, int n);

	//void setPassengerVector(vector<Passenger> passengerVector);
};