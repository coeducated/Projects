#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
	static string monthName[13]; // Name of months
	static const int monthsPerYear = 12; // Number of months in a year
	explicit Date(int = 1, int = 1, int = 1); // Constructor
	friend ostream &operator<<(ostream &, const Date &); // To overload the print operator.
	const bool operator==(const Date &rhs) const; // To overload == operator.
private:
	int month, day, year;
	int checkDay(int testDay) const; // Utility Function to validate the day, month, and year.
};
