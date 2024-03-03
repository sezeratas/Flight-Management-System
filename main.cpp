#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

#include "FlightManager.h"
#include "Menus.h"

using namespace std;

int main()
{

	FlightManager FlightManager;

	/*Passenger* passenger1 = new Passenger("Sezer", "Atas", "Male");
	Passenger* passenger2 = new Passenger("AAAAA", "AAAAA", "AAAAA");
	Passenger* passenger3 = new Passenger("BBBBB", "BBBBB", "BBBBB");

	Flight flight1("TK111", "Ankara");

	flight1.ReserveSeat(*passenger1);
	flight1.ReserveSeat(*passenger2);
	flight1.ReserveSeat(*passenger3);

	FlightManager.AddFlight(flight1);*/

	int mainChoice = 0;

	while (mainChoice != 5) {
		TopLevelMenu();
		cout << "Enter your choice: ";
		if (cin >> mainChoice) {
			switch (mainChoice)
			{
			case 1:
			{
				string flightNo, destination;
				cout << "\nEnter the flight number: ";
				cin >> flightNo;
				cout << "Enter the flight destination: ";
				cin >> destination;

				Flight* newFlight = new Flight(flightNo, destination);

				FlightManager.AddFlight(*newFlight);

				break;
			}
			case 2:
			{
				string flightNumber;
				cout << "\nEnter the flight number: ";
				cin >> flightNumber;
				FlightManager.RemoveFlight(flightNumber);
				break;
			}
			case 3:
			{
				FlightManager.ListAllFlights();
				break;
			}
			case 4:
			{
				int secondchc = 0;
				string flightNumber;

				FlightManager.ListAllFlights();
				cout << "\nEnter the flight number: ";
				cin >> flightNumber;

				Flight* selectedFlight = FlightManager.getFlightByNumber(flightNumber);

				while (secondchc != 4) {
					SecondLevelMenu();
					cout << "Enter your choice: ";
					if (cin >> secondchc) {
						switch (secondchc){

						case 1:
						{
							string name, surname, gender, seatNo;

							ReservedSeatMenu(selectedFlight);

							cout << "Reservation" << endl;
							cout << "Enter the seat number:" << endl;
							cin >> seatNo;

							cout << "Enter your name: ";
							cin >> name;
							cout << "Enter your surname: ";
							cin >> surname;
							cout << "Enter your gender: ";
							cin >> gender;

							Passenger* newPassenger = new Passenger(name, surname, gender);

							if (selectedFlight->ReserveSeat(*newPassenger, seatNo)) {
								cout << "Reservation is successful!" << endl;
							}
							else {
								cout << "Invalid reservation!" << endl;
								delete newPassenger;
							}
							break;
						}
						case 2:
						{
							string name, surname, gender;

							cout << "Verification" << endl;
							cout << "Enter your name: ";
							cin >> name;
							cout << "Enter your surname: ";
							cin >> surname;
							cout << "Enter your gender: ";
							cin >> gender;

							Passenger* canceledPassenger = new Passenger(name, surname, gender);

							if (selectedFlight->CancelReservation(*canceledPassenger)) {
								cout << "Cancellation is successful!" << endl;
							}
							else {
								cout << "Passenger does not found!" << endl;
							}

							delete canceledPassenger;

							break;
						}
						case 3:
						{
							selectedFlight->DisplayPassengers();
							break;
						}
						case 4:
						{
							cout << "Goodbye!" << endl;
							break;
						}
						default:
							break;
						}
					}
					else {
						cout << "Invalid input! Number only!" << endl;
						cin.clear();
						cin.ignore(100, '\n');
					}
				}
				break;
			}

			case 5:
			{
				cout << "Goodbye!" << endl;
				break;
			}
			default:
				cout << "Invalid input! (Wrong Number)" << endl;
				break;
			}
		}
		else {
			cout << "Invalid input! Number only!" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}

	return 0;
}

