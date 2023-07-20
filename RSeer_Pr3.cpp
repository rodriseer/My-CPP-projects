/*
 * Class: CMSC140 CRN XXXX
 * Instructor:
 * Project 3
 * Computer/Platform/Compiler: Windows, Visual Studios
 * Description: write a program that calculates the occupancy rate
   and the total hotel income for one night and displays this
   information as well as some other information described below.
 * Due Date: 07/17/2022
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Full Name here: Rodrigo Seer
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

	//variable to hold layout standards
	int linesOne = 0;
	const string HOTEL_NAME = "BlueMont Hotel";

	//variable to hold hotel location
	string hotelLocation;

	//variable to hold number of floors on this hotel location
	int floorNumberLocation;

	//variable for loop "each room each floor starts"
	int roomFloors;

	//variable to hold number of rooms on respective floors
	int roomNumberFloors;

	//variable to hold number of each room type
	int singleRoom = 0;
	int doubleRoom = 0;
	int kingRoom = 0;
	int suiteRoom = 0;

	//constant variables to hold values of room types and minimum values
	const int ONE = 1;
	const int FIVE= 5;
	const int THIRTY = 30;
	const int SIXTY = 60;
	const int SINGLE_VALUE = 60;
	const int DOUBLE_VALUE = 75;
	const int KING_VALUE = 100;
	const int SUITE_VALUE = 150;

	//variable accumulator
	double singleTotal = 0;
	double doubleTotal = 0;
	double kingTotal = 0;
	double suiteTotal = 0;

	//room number floor total  calculator, calculates total number of rooms across all floors
	double roomNumberFloorsTotal = 0;
	const int CEM = 100;

	//least number of rooms
	double leastNumber = 100;
	double leastFloor = 0;

	//variables to hold name, data, etc
	const string PROGRAMMER = "Rodrigo Seer";
	const string DUE = "07/17/2022";


	//standard BlueMont Hotel first layout
	for (linesOne = 0; linesOne <= 100; linesOne++)
	cout << "=";
	cout << "\n";
	cout << setw(40) << right;
	cout << "\t" << HOTEL_NAME << "\n";
	for (linesOne = 0; linesOne <= 100; linesOne++)
	cout << "=";
	cout << "\n\n";

	//Location and floors questions
	cout << "Enter the location for this hotel chain: ";
	getline(cin, hotelLocation);

	cout << "Enter total number of floors on this hotel: ";
	cin >> floorNumberLocation;
	//error checking
	while (floorNumberLocation < ONE || floorNumberLocation > FIVE)
	{
		cout << "Number of floors needs to be between 1 and 5, please, try again!" << "\n\n";
		cout << "Enter total number of floors on this hotel: ";
		cin >> floorNumberLocation;
	}
	//standard spacing
	cout << "\n\n";


	//loop for each room on each floor starts
	for (roomFloors = 1; roomFloors <= floorNumberLocation; roomFloors++)
	{
		cout << "Enter total number of rooms in the " << roomFloors << "th floor: ";
		cin >> roomNumberFloors;

		//error checking
		while (roomNumberFloors < ONE || roomNumberFloors > THIRTY)
		{
			cout << "Number of rooms should be between 1 and 30! Try again!" << "\n";
			cout << "Enter total number of rooms in the " << roomFloors << "th floor: ";
			cin >> roomNumberFloors;
		}
		//this part is to save the least numbers of rooms and the floor respectively while looping
		if (leastNumber >= roomNumberFloors)
		{
			leastNumber = roomNumberFloors;
			leastFloor = roomFloors;
		}
		roomNumberFloorsTotal += roomNumberFloors;

		//input starts
		cout << "How many SINGLE rooms are occupied in the " << roomFloors << "th floor: ";
		cin >> singleRoom;
		
		cout << "How many DOUBLE rooms are occupied in the " << roomFloors << "th floor: ";
		cin >> doubleRoom;
		
		cout << "How many KING rooms are occupied in the " << roomFloors << "th floor: ";
		cin >> kingRoom;
		
		cout << "How many SUITE rooms are occupied in the " << roomFloors << "th floor: ";
		cin >> suiteRoom;
		
		cout << "\n\n";

		//error checking
		while (singleRoom + doubleRoom + kingRoom + suiteRoom > roomNumberFloors)
		{
			cout << "Total number of occupied rooms must not exceed total number of rooms on this floor or be a negative value!! Please, try again!" << "\n";
			cout << "How many SINGLE rooms are occupied in the " << roomFloors << "th floor: ";
			cin >> singleRoom;

			cout << "How many DOUBLE rooms are occupied in the " << roomFloors << "th floor: ";
			cin >> doubleRoom;

			cout << "How many KING rooms are occupied in the " << roomFloors << "th floor: ";
			cin >> kingRoom;

			cout << "How many SUITE rooms are occupied in the " << roomFloors << "th floor: ";
			cin >> suiteRoom;
			cout << "\n\n";
			
		}
		singleTotal += singleRoom;
		doubleTotal += doubleRoom;
		kingTotal += kingRoom;
		suiteTotal += suiteRoom;
	}

	//second layout standard
	for (linesOne = 0; linesOne <= 100; linesOne++)
	cout << "=";
	cout << "\n";
	cout << setw(25) << right;
	cout << "\t" << HOTEL_NAME << " located in " << hotelLocation << "\n";
	for (linesOne = 0; linesOne <= 100; linesOne++)
	cout << "=";
	cout << "\n\n";

	//layout for room type rates
	cout << "\t\t\t\tToday Room Rates (US$/night)" << "\n\n";
	cout << "\t\tSingle Room" << "\t" << "Double Room" << "\t" << "King Room" << "\t" << "Suite Room" << "\n";
	cout << "\t\t" << SINGLE_VALUE << "\t\t" << DOUBLE_VALUE << "\t\t" << KING_VALUE << "\t\t" << SUITE_VALUE << "\n";
	for (linesOne = 0; linesOne <= 100; linesOne++)
	cout << "=";
	cout << "\n";

	//income calculator, occupancy calculator and percentage
	cout << fixed << setprecision (2) << "Hotel Income: \t\t\t$" << static_cast <double> (singleTotal * SINGLE_VALUE) + (doubleTotal * DOUBLE_VALUE) + (kingTotal * KING_VALUE) + (suiteTotal * SUITE_VALUE) <<"\n";
	cout << fixed << setprecision (0) << "Total # of rooms: \t\t" << roomNumberFloorsTotal << "\n";
	cout << fixed << setprecision (0) << "Total # of occupied rooms: \t" << singleTotal + doubleTotal + kingTotal + suiteTotal << "\n";
	cout << fixed << setprecision (0) << "Total # of unoccupied rooms: \t" << roomNumberFloorsTotal - singleTotal - doubleTotal - kingTotal - suiteTotal << "\n";
	cout << fixed << setprecision (2) << "Occupancy rate: \t\t" << (singleTotal+doubleTotal+kingTotal+suiteTotal)/roomNumberFloorsTotal*CEM << "%" << "\n\n";
	cout << fixed << setprecision (0) << "The floor " << leastFloor << "th " << " with " << leastNumber << " rooms, has the least number of rooms!" << "\n";

	//occupancy rate error checking
	if ((singleTotal + doubleTotal + kingTotal + suiteTotal) / roomNumberFloorsTotal * CEM < SIXTY)
	{
		cout << "Need to improve occupancy rate!" << "\n";
	}

	cout << "\n";
	cout << "Thank you for testing my program!" << "\n";
	cout << "PROGRAMMER " << PROGRAMMER << "\n";
	cout << "CMSC 140 PROJECT 3" << "\n";
	cout << DUE << "\n";

	return 0;
} 