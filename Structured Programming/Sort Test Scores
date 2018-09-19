#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void arrSelectSort(double *, int);
void showArrPtr(double *, int);
void showAverage(double, int);

int main()
{
	double *scores,				// To dynamically allocate an array
		total = 0.0;			// Accumulator
	int numScores;				// To hold the number of test scores
								// Get the number of test scores.
	cout << "How many test scores will you enter? ";
	cin >> numScores;

	// Dynamically allocate an array large enough to hold that many
	// test scores
	scores = new double[numScores];
	if (scores == NULL)
		return 0;

	// Get the test score for each test
	for (int count = 0; count < numScores; count++)
	{
		cout << "Enter test score " << (count + 1) << ": ";
		cin >> scores[count];
		while (scores <= 0)
		{
			cout << "Zero or negative numbers not accepted.\n";
			cout << "Enter test score " << (count + 1) << ": ";
			cin >> scores[count];
		}
	}

	// Calculate the total scores
	for (int count = 0; count < numScores; count++)
	{
		total += scores[count];
	}

	// Sort the elements of the array pointers
	arrSelectSort(scores, numScores);

	// Display them in sorted order.
	cout << endl;
	cout << "The test scores in ascending order, and their average, are: \n\n";
	cout << setw(8);
	cout << "Score \n";
	cout << setw(8);
	cout << "----- \n";
	cout << endl;
	showArrPtr(scores, numScores);
	cout << endl;
	showAverage(total, numScores);

	// Free memory.
	delete[] scores;
	system("pause");
	return 0;
}
void arrSelectSort(double *array, int size)
{
	int startScan, minIndex;
	double  minElem;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minElem = array[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index]  < minElem)
			{
				minElem = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minElem;
	}
}

void showArrPtr(double *array, int size)
{
	cout << fixed << setprecision(2);
	for (int count = 0; count< size; count++)
		cout << setw(6) << array[count] << " " << endl;
	cout << endl;
}

void showAverage(double total, int numScores)
{
	double average;

	// Calculate the average
	average = total / numScores;

	// Display the results.
	cout << fixed << setprecision(2);
	cout << "Average Score: " << setw(6) << average << endl << endl;
}
