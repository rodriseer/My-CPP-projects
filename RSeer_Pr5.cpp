#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Global constants
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes (ok)
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

int main()
{
	//Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid (ok)
	int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
	//variable char if user wants to try again
	char tryAgain = 'y';

	//variables to hold my information
	string PROGRAMMER = "Rodrigo Seer";
	string PROJECT_NUMBER = "5";
	string PROJECT_DUE = " 08/07/2022";

	do
	{
		//using function fillArray to fill collums, refer to example checkpoint in chapter 7 (ok)
		fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
		//call function to show array (ok)
		showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

		//call function to decide if its a magic square or not (ok)
		if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS))
		{
			//display message to user that this is a magic array (ok)
			cout << "This is a Lo Shu magic square!" << endl;
		}
		else
			//display that it is not a magic square (ok)
			cout << "This is not a Lo Shu magic square!" << endl;

		//display message to user if it wants to try again
		cout << "\n\n\n Do you want to try again (y or n)? ";
		cin >> tryAgain;
	}
	//do while loop ends with checking string
	while (tryAgain == 'y');

	if (tryAgain == 'n')
	{
		cout << "Programmer: " << PROGRAMMER << "\n" << "Project Number: " << PROJECT_NUMBER << "\n" << "Due date: " << PROJECT_DUE << "\n";
	}

	//pause systems
	system("pause");
	return 0;

}

// Function definitions go here

//function to fill the array
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	//local variable to hold counter row value
	int rowsValue = 0;

	//integer variables to hold values of loopers
	int colummValue = 0;
	int colummValueTwo = 0;
	int colummValueThree = 0;

	//loop through the array to save firt values
	for (colummValue; colummValue < size; colummValue++)
	{
		//display to user values to enter in the array
		cout << "Enter the number for row " << rowsValue << " and for column " << colummValue << ": ";
		//gets user input for first row and save to rows while looping (ok)
		cin >> arrayRow1[colummValue];
	}
	//counter
	rowsValue++;

	//loop through the array to save second values
	for (colummValueTwo; colummValueTwo < size; colummValueTwo++)
	{
		//display to user values to enter in the array
		cout << "Enter the number for row " << rowsValue << " and for column " << colummValueTwo << ": ";
		//gets user input for second row and save to rows while looping
		cin >> arrayRow2[colummValueTwo];
	}
	//counter
	rowsValue++;

	//loop for third array row
	for (colummValueThree; colummValueThree < size; colummValueThree++)
	{
		//display to user input for third array
		cout << "Enter the number for row " << rowsValue << " and for column " << colummValueThree << ": ";
		//gets user input
		cin >> arrayRow3[colummValueThree];
	}
	//now all values should be in the arrays
}

//function to show array
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	//local variables to loop
	int showRow = 0;

	//looping to display array, the parameter array is what changes during each diferent loop, showing different values of different arrays
	for (int showColumn = 0; showColumn < size; showColumn++)
	{
		//display all values in the first column
		cout << arrayrow1[showColumn] << " ";
	}
	//counter
	cout << endl;
	showRow++;

	//looping to display second array
	for (int showColumn = 0; showColumn < size; showColumn++)
	{
		//display all values in the second column
		cout << arrayrow2[showColumn] << " ";
	}
	//counter
	cout << endl;
	showRow++;

	//looping to display second array
	for (int showColumn = 0; showColumn < size; showColumn++)
	{
		//display all values in the third column
		cout << arrayrow3[showColumn] << " ";
	}
	cout << endl;
	//no need to counter (because its the last one)
}



//easiest function to check first, diagonal check
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	//local boolean variable to return false or true
	bool diagonal = false;

	//local variables to addition of each diagonal values, remind to self to start with zero
	int diagonalOne = arrayrow1[0] + arrayrow2[1] + arrayrow3[2];
	//reverse order
	int diagonalTwo = arrayrow1[2] + arrayrow2[1] + arrayrow3[0];

	//check if sums are equal
	if (diagonalOne == diagonalTwo)
	{
		//change bool local variable to false
		diagonal = true;
	}
	//return bool diagonal to function
	return diagonal;
}

//second easiest row order to check, rows additions
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	//local bool value that varies true or false
	bool rows = false;

	//integer local variable to hold sums of rows. Note to self: logical thinking here is to check every row with each value of row [0], [1] etc...
	int rowOne = arrayrow1[0] + arrayrow1[1] + arrayrow1[2];
	int rowTwo = arrayrow2[0] + arrayrow2[1] + arrayrow2[2];
	int rowThree = arrayrow3[0] + arrayrow3[1] + arrayrow3[2];

	//check sums if all are equal
	if ((rowOne == rowTwo) || (rowOne == rowThree) || (rowTwo == rowThree))
	{
		//if all not equal the returns false
		rows = true;
	}

	//return variable to function
	return rows;
}

//function to check colums addition and to return bool value true or false, same logic as rows
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	//local variable to change bool return values
	bool colums = false;

	//integer variables to hold sums of colums. Note to self: the logical thinking here is that every addition will be same array value [0] + [0] + [0] etc...
	int columnOne = arrayrow1[0] + arrayrow2[0] + arrayrow3[0];
	int columnTwo = arrayrow1[1] + arrayrow2[1] + arrayrow3[1];
	int columnThree = arrayrow1[2] + arrayrow2[2] + arrayrow3[2];

	//checking if all are equal, same process as rows
	if ((columnOne == columnTwo) || (columnOne == columnThree) || (columnTwo == columnThree))
	{
		//if all not equal
		colums = true;
	}
	//return to function
	return colums;
}

//function to check if values were unique or not
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	//local integer to hold informations of arrays and bool variable to hold true or false
	int loopOne = 0;
	int loopTwo = 0;
	int loopThree = 0;
	bool unique = true;
	
	//mistakes counter
	int mistake = 1;

	//reference to chapter 2 using sizeof to determine the size of type variables in different rows
	while (loopOne < (sizeof(arrayRow1) / sizeof(arrayRow1[0])) && loopTwo < (sizeof(arrayRow2) / sizeof(arrayRow2[0])) && loopThree < (sizeof(arrayRow3) / sizeof(arrayRow3[0])))
	{
		//check for any equal values
		if ((arrayRow1[loopOne] == arrayRow2[loopTwo]) && (arrayRow2[loopTwo] == arrayRow3[loopThree]))
		{
			//if theres one error, save on counter
			if (loopOne > mistake)
			{
				//return false bool
				unique = false;
			}
			//counters
			loopOne++;
			loopTwo++;
			loopThree++;
		}
		else if (arrayRow1[loopOne] < arrayRow2[loopTwo])
			loopOne++;
		else if (arrayRow2[loopTwo] < arrayRow3[loopThree])
			loopTwo++;
		else
			loopThree++;
	}
	//return to function
	return unique;
}

//check range function. Note to self: refer to book how to check its range, do it after finishing all additions booleans
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
	//variable bool to check true or false
	bool ranger = true;

	//loop, use integers min and max to check range falses
	for (int rangerLooper = 0; rangerLooper < COLS; rangerLooper++)
	{
		if (arrayRow1[rangerLooper] < min || arrayRow1[rangerLooper] > max)
		{
			ranger = false;
		}
		else if (arrayRow2[rangerLooper] < min || arrayRow2[rangerLooper] > max)
		{
			ranger = false;
		}
		else if (arrayRow3[rangerLooper] < min || arrayRow3[rangerLooper] > max)
		{
			ranger = false;
		}
	}

	//return bool value to function
	return ranger;
}

//function array to check if its magic square
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	//local variable set to standard false
	bool standard = false;
	//local boolean variables to save if all other functions returned true or false
	bool equalRows = checkRowSum(arrayRow1, arrayRow2, arrayRow3, size);
	bool equalDiagonals = checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);
	bool equalColumns = checkColSum(arrayRow1, arrayRow2, arrayRow3, size);
	bool repeatedValues = checkUnique(arrayRow1, arrayRow2, arrayRow3, size);
	bool rangeValues = checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX);

	//statement to check if all are true
	if (equalRows && equalDiagonals && equalColumns && repeatedValues && rangeValues)
	{
		//change stardard value bool to true
		standard = true;
	}
	//return standard value to parameter
	return standard;
}
