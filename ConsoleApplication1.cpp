#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Passenger;

class Flight {
private:
	string flightNo;
	int maxPassenger = 25;
	int currentPassenger = 0;
	string passengerList[25];

public:
	vector <Passenger*> passengerVector;
	int getCurrentPassenger() const {
		return currentPassenger;
	}
	string* getPassengerList(){
		return &(passengerList[0]);
	}
	void FlightMenu() {
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
	}

	bool ReserveSeat(string passangerName) {
		if (currentPassenger < maxPassenger) {
			for (int i = 0; i < currentPassenger; i++) {
				if (passengerList[i] == passangerName) {
					cout << "You have already reserved a seat!" << endl;
					return 0;
				}
			}
			for (int i = 0; i < maxPassenger; i++) {
				if (passengerList[i] == "") {
					passengerList[i] = passangerName;
					currentPassenger++;
					cout << "Reservation is successful!" << endl;
					return 1;
				}
			}
		}
		else {
			cout << "The flight is full!" << endl;
			return 0;
		}
	}

	bool CancelReservation(string* passangerName) {
		for (int i = 0; i < sizeof(passengerList)/sizeof(string); i++) {
			if (passengerList[i] == *passangerName) {
				passengerList[i] = "";
				currentPassenger--;
				cout << "Cancellation is successful!" << endl;
				delete passengerVector[i];
				passengerVector.erase(passengerVector.begin() + i);
				return 1;
			}
			else {
				cout << "Passenger does not found!" << endl;
				return 0;
			}
		}
	}

	int numberOfPassenger() const {
		return currentPassenger;
	}

	void DisplayPassenger() {
		for (int i = 0; i < sizeof(passengerList)/sizeof(string); i++) {
			cout << i + 1 << "'th seat: " << passengerList[i] << endl;
		}
	}
};

class Passenger {
private:
	string passengerName;
	string passengerSurname;
	string passengerGender;
public:
	Passenger() {
		cout << endl << "New passenger is created!" << endl << endl;
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
		}
	}

	~Passenger() {
		cout << "Passenger is deleted!" << endl << endl;
	}

	void setPassengerName(string name) {
		for (int i = 0; i < name.length(); i++) {
			if (name[i] >= '0' && name[i] <= '9') {
				cout << "Name cannot contain a number!" << endl;
				return;
			}
		}
		passengerName = name;
	}
	void setPassengerSurname(string surname) {
		for (int i = 0; i < surname.length(); i++) {
			if (surname[i] >= '0' && surname[i] <= '9') {
				cout << "Surname cannot contain a number!" << endl;
				return;
			}
		}
		passengerSurname = surname;
	}
	void setPassengerGender(string gender) {
		for (int i = 0; i < gender.length(); i++) {
			if (gender[i] >= '0' && gender[i] <= '9') {
				cout << "Gender cannot contain a number!" << endl;
				return;
			}
		}
		passengerGender = gender;
	}

	string getPassengerName() {
		return passengerName;
	}
	string getPassengerSurname() {
		return passengerSurname;
	}
	string getPassengerGender() {
		return passengerGender;
	}
};

int main()
{
	Flight AnkaraIstanbulflight;

	int choice = 0;

	while (choice != 5) {
		AnkaraIstanbulflight.FlightMenu();
		cout << "Enter your choice: ";
		if (cin >> choice) {
			switch (choice)
			{
			case 1:
			{
				Passenger* passenger = new Passenger();
				for (int i = 0; i < AnkaraIstanbulflight.getCurrentPassenger(); i++) {
					if (passenger->getPassengerName() == AnkaraIstanbulflight.getPassengerList()[i]) {
						cout << "You have already reserved a seat!" << endl;
						passenger->setPassengerName("");
					}
				}
				if (sizeof(AnkaraIstanbulflight.getCurrentPassenger()) / sizeof(string) == 26) {
					cout << "The flight is full!" << endl;
					passenger->setPassengerName("");
				}
				else if (passenger->getPassengerName() == "" || passenger->getPassengerSurname() == "" || passenger->getPassengerGender() == "") {
					cout << endl << "Invalid reservation!" << endl;
					delete passenger;
				}
				else {
					AnkaraIstanbulflight.ReserveSeat(passenger->getPassengerName());
					AnkaraIstanbulflight.passengerVector.push_back(passenger);
				}
				break;
			}
			case 2:
			{
				string name;
				cout << "Enter your name: ";
				cin >> name;
				AnkaraIstanbulflight.CancelReservation(&name);
				break;
			}
			case 3:
			{
				cout << "Current number of passenger is: " << AnkaraIstanbulflight.numberOfPassenger() << endl;
				break;
			}
			case 4:
			{
				AnkaraIstanbulflight.DisplayPassenger();
				break;
			}
			case 5:
			{
				for (int i = 0; i < AnkaraIstanbulflight.passengerVector.size(); i++) {
					delete AnkaraIstanbulflight.passengerVector[i];
				}
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

	return 0;
}

