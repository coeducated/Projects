// Date.cpp
// Date class member-function definitions.
#include <iostream> // allows program to output data to the screen
#include "Date.h" // include Date class definition
#include "Time.h" // include Time class definition
using namespace std;

Date::Date(int mn, int dy, int yr, Time time)
	: time(time)
{
	if (mn > 0 && mn <= monthsPerYear) // validate the month
		month = mn;
	else
	{
		month = 1; // invalid month set to 1
		cout << "Invalid month (" << mn << ") set to 1.\n";
	} // end else

	year = yr; // could validate yr
	day = checkDay(dy); // validate the day
	cout << "Date object constructor for data "; // output Date object to show when its constructor is called
	print();
	cout << endl;
} // end Date constructor

void Date::print() const
{
	cout << month << '/' << day << '/' << year;
	cout << "\t";
	time.printStandard();
	cout << "\t";
	time.printUniversal();
} // end function print

Date::~Date()
{
	cout << "Date object destructor is called" << endl;
	print();
	cout << endl;
} // end ~Date destructor


void Date::increaseADay()
{
	checkDay(++day);
}

void Date::tick()

{
	int tempSecond = time.getSecond();
	if (tempSecond < 59)
	{
		tempSecond++;
		time.setSecond(tempSecond);
	}
	else if (tempSecond >= 59)
	{
		time.setSecond(0);
		int tempMin = time.getMinute();
		if (tempMin < 59)
		{
			tempMin++;
			time.setMinute(tempMin);
		}
		else if (tempMin >= 59)
		{
			time.setMinute(0);
			int tempHour = time.getHour();
			if (tempHour < 23)
			{
				tempHour++;
				time.setHour(tempHour);
			}
			else if (tempHour >= 23)
			{
				time.setHour(0);
				increaseADay();
			}
		}
	}
}

unsigned int Date::checkDay(int testDay) const
{
	static const int daysPerMonth[monthsPerYear + 1] =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;

	// February 29 check for leap year 
	if (month == 2 && testDay == 29 && (year % 400 == 0 ||
		(year % 4 == 0 && year % 100 != 0)))
		return testDay;

	cout << "Day (" << testDay << ") set to 1.\n";
	return 1; // leave object in consistent state if bad value
} // end function checkDay
