#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Function Prototypes

// int linear_search(int lotteryTickets[], int ARRAY_SIZE, int userValue);

bool binary_search(int[], int, int);

int main()
{
	const int ARRAY_SIZE = 10;      // Size limit of the array
	int lotteryTickets[ARRAY_SIZE] = { 13579, 26791, 26792, 33445, 55555, 
		                               62483, 77777, 79422, 85647, 93121 };		// Initialized array
	int userValue,                  // 5 digit number entered by the user
		result;                     // Determines if users' number won

	// Title of the program
	cout << "Lottery Winner Modification" << endl << endl;
	
	// Users input data
	cout << "Please enter this week's 5-digit winning lottery number: ";
	cin >> userValue;

	// Validate users' input using While
	while (userValue < 10000 || userValue > 100000)
	{
		cout << "\n <!> Invalid Entry - Ticket number must be at least 5-digits long." << endl;
		cout << " Please re-enter this week's 5-digit winning lottery number: ";
		cin >> userValue;
	}

/*
	//--------------Linear Search------------------

	// Function call
	result = linear_search(lotteryTickets, ARRAY_SIZE, userValue);

	// Display result using if, else function
	if (result >= 0)
	    cout << "\nYou have a winning ticket!" << endl << endl;
	else
		cout << "\nUnfortunately, you did not win this week." << endl << endl;
*/

	//--------------Binary Search------------------

	// Sort array in ascending order
	sort(lotteryTickets, lotteryTickets + ARRAY_SIZE);

	// Display result using if, else function with function call
	if (binary_search(lotteryTickets, ARRAY_SIZE, userValue))
		cout << "\nYou have a winning ticket!" << endl << endl;
	else
		cout << "\nUnfortunately, you did not win this week." << endl << endl;

	system("pause");

	return 0;
}

// Function Definitions

/*********************************************************************
   Definition of function: Linear search based on stored array
   Description: This function will perform a linear search based on
                stored values and return value indicating whether or
				not a specific value is found.
*********************************************************************/
/*
int linear_search(int lotteryTickets[], int ARRAY_SIZE, int userValue)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (userValue == lotteryTickets[i])
			return i;
	}
	return -1;
}
*/

/*********************************************************************
   Definition of function: Binary search based on sorted array
   Description: This function will perform a binary search based on
                stored values and return a boolean value (0 or 1) of
				whether or not a specific value is found.
*********************************************************************/
bool binary_search(int lotteryTickets[], int ARRAY_SIZE, int userValue)
{
	bool found = false;

	int first = 0;
	int middle;
	int last = ARRAY_SIZE - 1;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;

		if (lotteryTickets[middle] == userValue)
			found = true;
		else if (lotteryTickets[middle] > userValue)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return found;
}
