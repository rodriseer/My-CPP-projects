
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//general variables
	string countryName;
	int menuChoice;
	const string PROGRAMMER = "RSeer";
	const string PROJECT_NAME = "Common Project 2";
	const string DUE_DATE = "Due date: 07/03/2022";

	//temperature formulas
	int celsiusTemperature;
	const double CELSIUS_VALUE_ONE = 1.8;
	const int CELSIUS_VALUE_TWO = 32;

	//distance formulas
	double kilometerDistance;
	const double KILOMETER_VALUE_ONE = 0.6;

	//weight formulas
	double kilogramsWeight;
	const double POUNDS_VALUE_ONE = 2.2;

	//introduction lines
	cout << "Enter a country name: ";
	getline(cin, countryName);
	cout << "\n";
	cout << "\n" << "Converter Toolkit" << "\n" << "-----------------" << "\n";
	cout << "1. Temperature Converter" << "\n";
	cout << "2. Distance Converter" << "\n";
	cout << "3. Weight Converter" << "\n";
	cout << "4. Quit" << "\n";
	cout << "\n";
	cout << "Please enter your choice (1-4): ";
	cin >> menuChoice;

	//if choice for error checking
	if (menuChoice < 1 || menuChoice >4)
		cout << "\nInvalid option, please choose an option between (1-4)";

	//switch begins
	switch (menuChoice)
	{

		//switch case begins for temperature
		//make sure to crase so case error dont happen "initialization of 'element' is skipped by 'case' label"
	case 1:
	{
		//choice 1 temperature (note: using literals in celsiusConverter, delete 1.8 or 32 if required to constants)
		//temperature in celsius can be negative, no need to add error message, even if its above 100 (boiling temperature)
		cout << "Please enter Temperature in Celsius (such as 24): ";
		cin >> celsiusTemperature;

		//constant formula for temperature converter
		const int CELSIUS_CONVERTER = CELSIUS_VALUE_ONE * celsiusTemperature + CELSIUS_VALUE_TWO;

		//result for temperature converter
		cout << "It is " << CELSIUS_CONVERTER << " in Fahrenheit.";
		break;
	}

	//case 2 begins for distance
	case 2:
	{
		//choice 2 distance (note: negative distance must show as an error)
		cout << "Please enter distance in Kilometers (such as 18.54): ";
		cin >> kilometerDistance;
		if (kilometerDistance < 0)
			cout << "!!!Distance cannot be negative!!!";
		else
		{

		//constant for distance converter
		const double KILOMETER_CONVERTER = kilometerDistance * KILOMETER_VALUE_ONE;
		//results for distance
		cout << fixed << setprecision(2) << "It is " << KILOMETER_CONVERTER << " in Kilometers";
		}
		break;
	}

	//case 3 begins
	case 3:
	{
		cout << "Please enter weight in Kilograms: ";
		cin >> kilogramsWeight;
		if (kilogramsWeight < 0)
		cout << "!!!Weight cannot be negative!!!";
		else
		{

		//constant for weight conversion
		const double KILOGRAMS_CONVERTER = kilogramsWeight * POUNDS_VALUE_ONE;
		//result for weight
		cout << fixed << setprecision(1) << "It is " << KILOGRAMS_CONVERTER << " in Pounds.";
		break;
		}

		//case 4 begins
	case 4:;
		break;
	}
	}

	//show country name sounds fun
	cout <<"\n\n" << countryName << " sounds Fun!" << "\n";
	cout << "\n\n";
	cout << "Thank you for testing my program!!!" << endl;

	//information
	cout << PROGRAMMER << endl;
	cout << PROJECT_NAME << endl;
	cout << DUE_DATE << endl;

}
