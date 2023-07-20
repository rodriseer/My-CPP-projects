/*
 * Class: CMSC140 40052
 * Instructor: Ara Kachiantz
 * Project 1
 * Description: Follow script to program new robot.
 * Due Date: 06/11/2022
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Rodrigo Seer
 * Pseudocode or Algorithm for the program:
 
INITIALIZE robot name, visitor name, age, whole number 1, whole number 2
INITIALIZE programmer name, project number, due date
DISPLAY “Hello, welcome to Montgomery College!   My name is” Nao”, May I have your name?”
GET visitor name
DISPLAY “Nice to have you with us today” visitor name
DISPLAY “Let me impress you with a small game.”
DISPLAY “Give me the age of an important person or a pet to you.”
DISPLAY “Please give me only a number:”
GET age number
DISPLAY “You have entered” age
DISPLAY “If this is for a person, the age can be expressed as:”
DISPLAY age “years”
CALCULATE multiply age number by months, days, hours, minutes and seconds
CALCULATE multiply age by dog age equivalent and goldfish age equivalent
DISPLAY “or”  months
DISPLAY “ or” days
DISPLAY “or” hours
DISPLAY “or” minutes
DISPLAY “or” seconds
DISPLAY “If this is for a dog, it is” dog age “ years old in human age.”
DISPLAY “"If this is for a gold fish, it is” gold fish age " years old in human age.”
DISPLAY “Let's play another game” visitor name  “Give me a whole number.”
GET whole number 1
DISPLAY “Very well. Give me another whole number.”
GET whole number 2
CALCULATE whole number 1 sum whole number 2
CALCULATE whole number 1 division whole number 2
DISPLAY “using the operator '+' in C++, the result of” sum of whole number 1 and whole number 2
DISPLAY “using the operator ‘/’ in C++, the result of” division of whole number 1 and whole number 2
DISPLAY “however, the result of” whole number 1 with decimals “/’ whole number 2 with decimals is about”
COMPUTE transform integer into decimal result
DISPLAY “thank you for testing my program!!!”
DISPLAY “programmer” programmer name
DISPLAY “CMSC140” project number
DISPLAY “Due date” due date

  1.
  2.
  3.
*/

#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

int main()
{
	//variables for storage
	string visitorName;
	string robotName = "Nao";
	int age, wholeNumber1, wholeNumber2;

	//string for info about me
	const string PROGRAMMER_NAME = "Rodrigo Seer";
	const string ASSIGNMENT_NUMBER = "Common Project 1";
	const string DUE_DATE = "06/11/2022";

	//Nao introducing
	cout << "Hello, welcome to Montgomery College! " << "My name is " << robotName << ". May I have your name?" << "\n";
	getline(cin, visitorName);
	cout << "Nice to have you with us today, " << visitorName << "!" << "\n";

	//Nao asks for a age number
	cout << "Let me impress you with a small game." << endl;
	cout << "Give me the age of an important person or a pet to you." << "\n";
	cout << "Please give me only a number:" << "\n";
	cin >> age;

	//Nao showing age chosen
	cout << "\nYou have entered " << age << "." << "\n";
	cout << "If this is for a person, the age can be expressed as:" << "\n";
	cout << age << " years" << "\n";

	//math variables for time
	const MONTHS = age * 12;
	const DAYS = MONTHS * 30;
	const HOURS = DAYS * 24;
	const MINUTES = HOURS * 60;
	const SECONDS = MINUTES * 60;

	//math variables for animals
	const ONE_DOG_YEAR = 7 * age;
	const GOLD_FISH_YEAR = 5 * age;

	//time related answers, remind to set precision for min and sec
	cout << "or " << MONTHS << " months" << "\n";
	cout << "or about " << DAYS << " days" << "\n";
	cout << "or about " << HOURS << " hours" << "\n";
	cout << fixed << setprecision(0) << "or about " << MINUTES << " minutes " << "\n";
	cout << fixed << setprecision(0) << "or about " << SECONDS << " seconds. " << "\n";

	//animal age related answers
	cout << "If this is for a dog, it is " << ONE_DOG_YEAR << " years old in human age." << "\n";
	cout << "If this is for a gold fish, it is " << GOLD_FISH_YEAR << " years old in human age." << "\n\n";

	//Nao does another game
	cout << "Let's play another game " << visitorName << ". " << "Give me a whole number." << "\n";
	cin >> wholeNumber1;
	cout << "Very well. Give me another whole number." << "\n";
	cin >> wholeNumber2;

	//math variables for whole sum numbers
	double sum = wholeNumber1 + wholeNumber2;
	double division = wholeNumber1 / wholeNumber2;

	//answers from Nao regarding whole number calculations, remind to set precision for double
	cout << "\nUsing the operator '+' in C++, the result of " << wholeNumber1 << " + " << wholeNumber2 << " is " << sum << "\n";
	cout << "Using the operator '/' in C++, the result of " << wholeNumber1 << " / " << wholeNumber2 << " is " << division << "\n";
	cout << fixed << setprecision(1) << "however, the result of " << wholeNumber1 << ".0" << " / " << wholeNumber2 << ".0" << " is about " << static_cast <double> (wholeNumber1) / wholeNumber2;

	//info about me
	cout << "\n\nThank you for testing my program!!!" << "\n";
	cout << "PROGRAMMER: " << PROGRAMMER_NAME << "\n";
	cout << "CMSC140 " << ASSIGNMENT_NUMBER << "\n";
	cout << "Due Date: " << DUE_DATE<< "\n";

	return 0;
}