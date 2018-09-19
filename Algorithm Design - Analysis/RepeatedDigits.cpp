#include <iostream>

using namespace std;

#define DIGITS 10	// number of Base 10 digits

int main()
{
	int number,					// number input by the user
		digit,					// digit of number being processed
		isEmpty,				// used to check if no repeated digits
		to_print[DIGITS],		// displays the repeated digits
		digit_tally[DIGITS],	// tracks digits seen
		i;						// counter

	do {

		// Initalize to zero
		isEmpty = 0;

		// Initialize the tally to all zeroes, indicating that
		// no repeated digits have been found
		for (i = 0; i < DIGITS; i++) {
			digit_tally[i] = 0;
		}

		// Initialze the array to zero
		for (i = 0; i < DIGITS; i++) {
			to_print[i] = 0;
		}

		// Input
		cout << "Enter a number (any negative number to exit): ";
		cin >> number;

		// Check for repeated digits
		while (number > 0) {
			digit = number % 10;
			if (digit_tally[digit]) {
				to_print[digit]++;
			}
			digit_tally[digit] = 1;
			number /= 10;
		}

		// Display results
		for (i = 0; i < DIGITS; i++) {
			isEmpty += to_print[i];
		}

		if (isEmpty == 0) {
			cout << "No repeated digits" << endl;
		}
		else {
			cout << "Repeated digits:";
			for (i = 0; i < DIGITS; i++) {
				if (to_print[i] > 0) {
					cout << " " << i;
				}
			}
		}
		cout << endl;
	} while (number >= 0);
}
