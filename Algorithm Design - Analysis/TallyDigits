#include <iostream>

using namespace std;

#define DIGITS 10		// Size of the array

int main()
{
	int n,						// number input by user
		digit,					// digit of number being processed
		i,						// general counter
		digit_count[DIGITS];	// array

	do {
		// Initalize array to all zeroes
		for (i = 0; i < DIGITS; i++) {
			digit_count[i] = 0;
		}

		cout << "Enter a number (any negative number to exit): ";
		cin >> n;

		// Count how many times each digit has been seen
		while (n > 0) {
			digit = n % 10;
			digit_count[digit]++;
			n /= 10;
		}

		// Display header
		cout << "Digit:  ";
		for (i = 0; i < DIGITS; i++) {
			cout << " " << i;
		}
		cout << endl;
		cout << "Count:  ";
		for (i = 0; i < DIGITS; i++) {
			cout << " " << digit_count[i];
		}
		cout << endl;
	} while (n >= 0);
	
}
