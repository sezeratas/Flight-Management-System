#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Flight.h"  // Include the header file for the Flight class

using namespace std;

class FlightManager {
private:
	vector <Flight> flightsVector;
public:
	vector <Flight> getFlightsVector() const;

	void setFlightsVector(vector <Flight>& flight);


	void AddFlight(const Flight& flight);

	void RemoveFlight(const string& flightNumber);

	void ListAllFlights();

	Flight* getFlightByNumber(const string& flightNo);

	Flight getFlightByDestination(const string& destination);
};