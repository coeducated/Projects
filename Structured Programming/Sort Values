#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

// Function Prototypes
void display_array(int[], int);
void bubble_sort(int[], int);
void selection_sort(int[], int);

const int SIZE = 8;

int main()
{
	int values[SIZE] = { 106, 101, 104, 100, 107, 102, 105, 103 };
	
	// Title of the program
	cout << "Sorting Order Application" << endl << endl;
	
	cout << "Begin both bubble & selection sort..." << endl << endl; 
	
	// --- Sorting using bubble sort ---
	// Funtion call to display (before and after) and perform bubble sort
	cout << "Here are the values before bubble sort is performed." << endl;
	display_array(values, SIZE);
	cout << endl;

	bubble_sort(values, SIZE);
	
	cout << "\nHere are the values after bubble sort." << endl;
	display_array(values, SIZE);
	cout << endl << endl << endl;
	
	// --- Sorting using selection sort ---
	// Funtion call to display (before and after) and perform selection sort
	cout << "Here are the values before selection sort is performed." << endl;
	display_array(values, SIZE);
	cout << endl;

	selection_sort(values, SIZE);

	cout << "\nHere are the values after the selection sort." << endl;
	display_array(values, SIZE);
	cout << endl;

	system("pause");

	return 0;
}

// Function Difinition

/*********************************************************************
   Definition of function: Display array values
   Description: This function will display values stored in an array
                using a for loop.
*********************************************************************/
void display_array(int values[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << values[i] << "   ";
	}
	cout << endl;
	return;
}

/*********************************************************************
   Definition of function: Bubble sort array
   Description: This function will perform a bubble sort based on the
                values stored in an array and display the process
                after each sort.
*********************************************************************/
void bubble_sort(int values[], int SIZE)
{
    int temp;
    bool swap;
    int last = SIZE - 1;
    
    do
    {
        swap = false;
        for (int i = 0; i < last; i++)
        {
            if (values[i] > values[i + 1])
            {
                temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                swap = true;
            }
        }
        cout << "Bubble sort in progress..." << endl;
		display_array(values, SIZE);
		
		last--;
	} while(swap != false);
	return;
}

/*********************************************************************
   Definition of function: Selection sort array
   Description: This function will perform a selection sort based on
                the values stored in an array and display the process
                after each sort.
*********************************************************************/
void selection_sort(int values[], int SIZE)
{
	int i, minimum_i, miniValue;

	for (i = 0; i < (SIZE - 1); i++)
	{
		minimum_i = i;
		miniValue = values[i];

		for (int j = i + 1; j < SIZE; j++)
		{
			if (values[j] < miniValue)
			{
				miniValue = values[j];
				minimum_i = j;
			}
		}

		values[minimum_i] = values[i];
		values[i] = miniValue;

		cout << "Selection sort in progress..." << endl;
		display_array(values, SIZE);
	}
	return;
}
