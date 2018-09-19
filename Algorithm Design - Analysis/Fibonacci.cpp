#include <iostream>

using namespace std;

#define SIZE 47

int main()
{
	int i,				// Counter
		sum,			// Accumulator
		fibnum[SIZE];	// Array

	// Initialize the array
	fibnum[0] = 0;
	fibnum[1] = 1;

	// Processing and output
	for (i = 0; i < SIZE; i++)
	{
		cout << fibnum[0] << endl;
		sum = fibnum[0] + fibnum[1];
		fibnum[0] = fibnum[1];
		fibnum[1] = sum;
	}
}
