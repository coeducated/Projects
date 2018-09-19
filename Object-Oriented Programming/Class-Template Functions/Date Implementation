#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"

using namespace std;

// Give each month a name
string Date::monthName[13] = { "Invalid", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

// Print overloaded "<<" operator to display a Complex Date in the form of (a, b).
ostream &operator<<(ostream &output, const Date &date)
{
	cout << date.monthName[date.month] << " " << date.day << " " << date.year;
	return output;
} // End overloaded operator.

// Constructor validates month.
Date::Date(int mn, int dy, int yr)
{
	if (mn > 0 && mn <= monthsPerYear) // Validate the month.
		month = mn;
	else
		month = 1; // Sets the month back to 0.
	year = yr; 
	day = checkDay(dy); // Validate the day.
} // End date constructor.

// Utility function checkDay to confirm value for "day"
int Date::checkDay(int testDay) const
{
	static const int daysPerMonth[(monthsPerYear + 1)]= // Number of days in each month
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// Determine whether testDay is valid
	if ((testDay > 0) && (testDay <= daysPerMonth[month]))
	{
		return testDay;
	}
	else
	{
		return 1;
	}

	// Check for a leap year
	if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 400 == 0 && year % 100 != 0)))
	{
		return testDay;
	}
	return 1; // if the day is too large for month, set back to 1.
} // end function checkDay

// Takes a complex date number into an object
const bool Date::operator==(const Date &rhs) const
{
	if ((day == rhs.day) && (month == rhs.month) && (year == rhs.year))
	{
		return true;
	}
	return false;
} // end overloaded "==" operator
