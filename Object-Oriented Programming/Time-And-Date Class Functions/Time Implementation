// Time.cpp
// Member-function definitions for class Time.
#include <iostream> // allows program to output data to the screen
#include <iomanip>
#include <stdexcept>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

Time::Time(int hour, int minute, int second)
{
	cout << "Time object constructor is called ";
	setTime(hour, minute, second); // validate and set time
	printStandard();
	printUniversal();
	cout << endl;
} // end Time constructor


void Time::setTime(int h, int m, int s)
{
	setHour(h); // set private field hour
	setMinute(m); // set private field minute
	setSecond(s); // set private field second
} // end function setTime

void Time::setHour(int h)
{
	if (h >= 0 && h < 24)
		hour = h;
	else
		throw invalid_argument("hour must be 0-23");
} // end function setHour

void Time::setMinute(int m)
{
	if (m >= 0 && m < 60)
		minute = m;
	else
		throw invalid_argument("minute must be 0-59");
} // end function setMinute

void Time::setSecond(int s)
{
	if (s >= 0 && s < 60)
		second = s;
	else
		throw invalid_argument("second must be 0-59");
} // end function setSecond

unsigned int Time::getHour() const
{
	return hour;
} // end function getHour

unsigned int Time::getMinute() const
{
	return minute;
} // end function getMinute

unsigned int Time::getSecond() const
{
	return second;
} // end function getSecond

Time::~Time()
{
	// destructing message
	cout << "Time object destructor is called ";
	// call printStandard and printUniversal functions
	printStandard();
	printUniversal();
	cout << endl;
} // end Time destructor

void Time::printUniversal() const
{
	cout << setfill('0') << setw(2) << getHour() << ":"
		<< setw(2) << getMinute() << ":" << setw(2) << getSecond();
} // end function printUniversal

void Time::printStandard() const
{
	cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
		<< ":" << setfill('0') << setw(2) << getMinute()
		<< ":" << setw(2) << getSecond() << (hour < 12 ? " AM     " : " PM     ");
} // end function printStandard
