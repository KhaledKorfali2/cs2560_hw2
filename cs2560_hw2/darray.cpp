//
// Name:	Korfali, Khaled
// Homework:2
// Due: 	03-22-2023
// Course:	cs-2560-01-sp23
//
// Description:
//		This code allocates a dynamic array based off a user specified
//		size, and then populates that array with random numbers between
//		1 and 100 inclusive. The contents of this dynamic array are then
//		displayed to the user.
//

#include<iostream>
#include<random>
#include<ctime>
#include<iomanip>

using namespace std;


// Function Prototypes
int* allocateDynamicArray(int arrSize);

// Constant Values
const int MAXNUMSPERLINE = 8;

int main()
{
	// Will store user defined array size
	int arrSize;

	// Seed random number generator with current time
	srand(time(0));

	// Output Header and prompt
	cout << "Dynamic Array by K. Korfali" << endl << endl;
	cout << "Enter size? ";

	// Get user input for array size
	cin >> arrSize;

	// Display a new line
	cout << endl;

	// Define and allocate for dynamic array using user defined array size
	int* dArray = allocateDynamicArray(arrSize);

	// Fills dynamic array with random numbers from 1 to 100 inclusive
	for (int i = 0; i < arrSize; i++)
	{
		*(dArray + i) = rand() % 100 + 1;
	}

	// Display dynamic array values
	for (int i = 0; i < arrSize; i++)
	{
		cout << setw(3) << *(dArray + i); // format to be 3 wide
		// Do not output anything after last element is displayed
		if ((i + 1) != arrSize)
		{
			// Adds new line after the 8th element
			if ((i + 1) % MAXNUMSPERLINE == 0)
			{
				cout << endl;
			}
			// Add spaces between elements
			else
			{
				cout << " ";
			}
		}
	}

	// Final endl
	cout << endl;

	// Memory Managment
	delete[] dArray; // Delete array

	// Return 0 indicating successfull execution
	return 0;
}

// Function to allocate memory for dynamic array
int* allocateDynamicArray(int arrSize)
{
	int* dArray = new int [arrSize];

	return dArray;
}