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
		cout << setw(3) << *(dArray + i);
		if ((i+1) % MAXNUMSPERLINE == 0)
		{
			cout << endl;
		}
		else
		{
			cout << " ";
		}
	}

	// Final endl
	cout << endl;

	// Memory Managment
	//for (int i = 0; i < arrSize;i++)
	//{
	//	delete (dArray + i); // Delete individual elements
	//}
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