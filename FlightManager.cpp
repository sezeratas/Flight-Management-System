#include "FlightManager.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <Flight> FlightManager::getFlightsVector() const {
	return flightsVector;
}

void FlightManager::setFlightsVector(vector <Flight>& flight) {
	flightsVector = flight;
}

void FlightManager::AddFlight(const Flight& flight) {
	flightsVector.push_back(flight);
}
void FlightManager::RemoveFlight(const string& flightNumber) {
	for (int i = 0; i < flightsVector.size(); i++) {
		if (flightsVector[i].getFlightNo() == flightNumber) {
			//delete flightsVector[i];
			flightsVector.erase(flightsVector.begin() + i);
		}
	}
}
void FlightManager::ListAllFlights() {
	for (int i = 0; i < flightsVector.size(); i++) {
		cout << i + 1 << ". Flight number: " << flightsVector[i].getFlightNo() << endl;
		cout << "Destination: " << flightsVector[i].getDestination() << endl;
		cout << "Current number of passenger: " << flightsVector[i].numberOfPassengers() << endl << endl;
	}
}
Flight* FlightManager::getFlightByNumber(const string& flightNo) {
	for (int i = 0; i < flightsVector.size(); i++) {
		if (flightsVector[i].getFlightNo() == flightNo) {
			return &flightsVector[i];
		}
	}
}
Flight FlightManager::getFlightByDestination(const string& destination) {
	for (int i = 0; i < flightsVector.size(); i++) {
		if (flightsVector[i].getFlightNo() == destination) {
			return flightsVector[i];
		}
	}
}
