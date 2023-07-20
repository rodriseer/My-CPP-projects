
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//this is a global variable to declare that it is supposed to write instead of read in the file
ofstream outFile;

//prototypes
int numberOfEmployees();
int totalDaysAbsent(int numberOfEmployees, int& employeeAbsentTotal);
double averageAbsent(int numberOfEmployees, int& totalDaysAbsent);

int main ()
{

	//file creation 
	outFile.open("employeeAbsences.txt");

	//local variables
	const string PROGRAMMER = "Rodrigo Seer";
	int employeesQuantity;
	int totalAbsent = 0;
	double averageEmployeeAbsent;

	//file layout first
	outFile << "EMPLOYEE ABSENCE REPORT" <<endl;
	outFile << "Employee ID" << "\t\t Days Absent" << endl;

	//function callings
	employeesQuantity = numberOfEmployees();
	totalDaysAbsent(employeesQuantity, totalAbsent);
	averageEmployeeAbsent = averageAbsent(employeesQuantity, totalAbsent);

	//file layout second
	outFile << "\nThe " << employeesQuantity << " employees were absent a total of " << totalAbsent << " days." << endl;
	outFile << fixed << setprecision (1) << "The average number of days absent is " << averageEmployeeAbsent << " days." << endl;
	outFile << "\nProgrammer: " << PROGRAMMER;
	cout << "Programmer: " << PROGRAMMER;

	//closing file
	outFile.close();
	return 0;

}

int numberOfEmployees()
{
	//local variable
	int totalEmployees = 0;
	int employeeMinimun = 1;

	//asks how many employees are in the company, return to total employees variables
	do
	{
		cout << "How many employees are in the company? ";
		cin >> totalEmployees;

		if (totalEmployees < employeeMinimun)
		{
			cout << "Number of employees cannot be negative or zero!" << endl;
		}
	}
	while (totalEmployees < employeeMinimun);
	totalEmployees;

	//return value to function, no parameters
	return totalEmployees;
}

int totalDaysAbsent(int numberOfEmployees, int& employeeAbsentTotal)
{
	//local variables
	int employees;
	int zero = 0;
	int employeeIdentification = 0;
	int employeeAbsent = 0;
	int totalEmployeeAbsent = 0;


	for (employees = zero; employees < numberOfEmployees; employees++)
	{
		cout << "\nPlease enter an employee ID: ";
		cin >> employeeIdentification;
		do
		{
			cout << "Please enter the number of days this employee was absent: ";
			cin >> employeeAbsent;

			if (employeeAbsent < zero)
			{
				cout << "Number of absences cannot be negative!" <<endl;
			}
		}
		while (employeeAbsent < zero);

		//write to txt file
		outFile << setw(5) << employeeIdentification << setw(20) << employeeAbsent << endl;

		//counter
		totalEmployeeAbsent += employeeAbsent;
	} 
	
	//setting parameter
	employeeAbsentTotal = totalEmployeeAbsent;

	//return parameter
	return employeeAbsentTotal;
}


double averageAbsent(int numberOfEmployees, int& totalDaysAbsent)
{
	//set precision of decimals to 1
	cout << fixed << setprecision(1);

	//return result in double, division of integers total days absent and number of employees
	return (double) totalDaysAbsent / numberOfEmployees;
}
