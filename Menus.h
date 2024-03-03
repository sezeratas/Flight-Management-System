#pragma once
#include <iostream>
#include <string>


using namespace std;

void TopLevelMenu() {  // Flight Management Menu
	cout << "\n#--------------------------------------------#" << endl;
	cout << "|  1. Add a flight                           |" << endl;
	cout << "#--------------------------------------------#" << endl;
	cout << "|  2. Remove a flight                        |" << endl;
	cout << "#--------------------------------------------#" << endl;
	cout << "|  3. List all flights                       |" << endl;
	cout << "#--------------------------------------------#" << endl;
	cout << "|  4. Select a Flight and Manage passengers  |" << endl;
	cout << "#--------------------------------------------#" << endl;
	cout << "|  5. Exit                                   |" << endl;
	cout << "#--------------------------------------------#\n" << endl;
}

void SecondLevelMenu() {  // Passenger Management (For a selected flight)
	cout << "\n#-----------------------------------------------#" << endl;
	cout << "|  1. Reserve a Seat (By displaying seating plan) |" << endl;
	cout << "#-------------------------------------------------#" << endl;
	cout << "|  2. Cancel Reservation                          |" << endl;
	cout << "#-------------------------------------------------#" << endl;
	cout << "|  3. View Passenger List                         |" << endl;
	cout << "#-------------------------------------------------#" << endl;
	cout << "|  4. Back to Flight Management Menu              |" << endl;
	cout << "#-------------------------------------------------#\n" << endl;
}

void ReservedSeatMenu(Flight* flight) {

	//Passenger* newPassenger = new Passenger("Sezer", "Atas", "Male");
	//flight->setPassengerVector(*newPassenger, 5);
	//for(int i=0; i<flight->getMaxSeats(); i++) {
	//	flight->getPassengerVector();
	//}

	int counter = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			counter++;
			if (flight->getPassengerVector()[counter].getPassengerName() == "") {
				cout << "| " << i + 1 << char(65 + j) << " O ";
			}
			else {
				cout << "| " << i + 1 << char(65 + j) << " X ";
			}
		}
		cout << "|" << endl;
	}
	/*cout << "\n#-----------Front-----------#" << endl;
	cout << "| 1A O | 1B O | |1C O | 1D O |" << endl;
	cout << "| 2A X | 2B O | |2C O | 2D O |" << endl;
	cout << "| 3A O | 3B X | |3C O | 3D O |" << endl;
	cout << "| 4A O | 4B O | |4C O | 4D O |" << endl;
	cout << "| 5A O | 5B O | |5C O | 5D O |" << endl;
	cout << "| 6A O | 6B O | |6C O | 6D O |" << endl;
	cout << "| 7A O | 7B O | |7C O | 7D O |" << endl;
	cout << "| 8A O | 8B O | |8C O | 8D O |" << endl;
	cout << "| 9A O | 9B O | |9C O | 9D O |" << endl;
	cout << "| 10A O | 10B O | |10C O | 10D O |" << endl;*/
}

/*void FlightMenu() {
	cout << "#-------------------------#" << endl;
	cout << "|       Flight Menu       |" << endl;
	cout << "#-------------------------#" << endl;
	cout << "|  1. Reserve a Ticket    |" << endl;
	cout << "#-------------------------#" << endl;
	cout << "|  2. Cancel Reservation  |" << endl;
	cout << "#-------------------------#" << endl;
	cout << "|  3. Check Reservation   |" << endl;
	cout << "#-------------------------#" << endl;
	cout << "|  4. Display Passengers  |" << endl;
	cout << "#-------------------------#" << endl;
	cout << "|  5. Exit                |" << endl;
	cout << "#-------------------------#" << endl;
}*/