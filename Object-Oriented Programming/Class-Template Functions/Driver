#include "Complex.h"
#include "Date.h"

using namespace std;

// Template Function isEqualTo
template <class Type>
bool isEqualTo(Type left, Type right)
{
	return (left == right);
} // End function isEqualTo

int main()
{
	// Test if two integers are equal or not
	cout << "*** Integers Tests ***" << endl;

	int leftInts[4] = { 1, 2, -1, -1 }; // lhs integers 
	int rightInts[4] = { 1, 4, 1, -1 }; // rhs integers
	for (int a = 0; a < 4; a++)
	{
		cout << "Integers: " << leftInts[a] << " and " << rightInts[a] << " are "
			<< (isEqualTo(leftInts[a], rightInts[a]) ? "equal" : "\"NOT\" equal") << '\n';
	}

	// Test if two characters are equal or not
	cout << "\n\n*** Chars Tests ***" << endl;
	char leftChars[4] = { 'a','a','c','c' }; // lhs chars
	char rightChars[4] = { 'a', 'c', 'a', 'c' }; // rhs chars
	for (int a = 0; a < 4; a++)
	{
		cout << "Characters: " << leftChars[a] << " and " << rightChars[a] << " are "
			<< (isEqualTo(leftChars[a], rightChars[a]) ? "equal" : "\"NOT\" equal") << '\n';
	}

	// Test if two double values are equal or not
	cout << "\n\n*** Double Tests ***" << endl;
	double leftDoubles[4] = { 2.2, 2.2, -2.2, -2.2 }; // lhs doubles
	double rightDoubles[4] = { 2.2, 2.3, 2.2, -2.2 }; // rhs doubles
	for (int a = 0; a < 4; a++)
	{
		cout << "Double numbers: " << leftDoubles[a] << " and " << rightDoubles[a] << " are "
			<< (isEqualTo(leftDoubles[a], rightDoubles[a]) ? "equal" : "\"NOT\" equal") << '\n';
	}

	// Test if two Complex objects are equal or not
	cout << "\n\n*** Complex Tests ***" << endl;
	Complex a(10, 5);
	Complex a1(10, 5);
	cout << "Class objects: " << a << " and " << a1 << " are "
		<< (isEqualTo(a, a1) ? "equal" : "\"NOT\" equal");
	Complex b(10, 5);
	Complex b1(10, 54);
	cout << "\nClass objects: " << b << " and " << b1 << " are "
		<< (isEqualTo(b, b1) ? "equal" : "\"NOT\" equal");
	Complex c(10, -5);
	Complex c1(10, 5);
	cout << "\nClass objects: " << c << " and " << c1 << " are "
		<< (isEqualTo(c, c1) ? "equal" : "\"NOT\" equal");
	Complex d(-10, -5);
	Complex d1(-10, -5);
	cout << "\nClass objects: " << d << " and " << d1 << " are "
		<< (isEqualTo(d, d1) ? "equal" : "\"NOT\" equal");

	// Test if two strings are equal or not
	cout << "\n\n*** String Tests ***" << endl;
	string leftStrings[4] = { "abcdefg", "abcdefg", "-abcdefg", "-abcdefg" }; // lhs strings 
	string rightStrings[4] = { "abcdefg", "abcdefh", "abcdefg", "-abcdefg" }; // rhs strings 
	for (int a = 0; a < 4; a++)
	{
		cout << "String objects: " << leftStrings[a] << " and " << rightStrings[a] << " are "
			<< (isEqualTo(leftStrings[a], rightStrings[a]) ? "equal" : "\"NOT\" equal") << '\n';
	}

	// Test if two dates are equal or not
	cout << "\n\n*** Date Tests ***";
	Date dayA(2, 31, 2017);
	Date dayB(2, 31, 2017);
	cout << "\nDate objects: " << dayA << " and " << dayB << " are "
		<< (isEqualTo(dayA, dayB) ? "equal" : "\"NOT\" equal");
	Date dayC(-2, 13, 2017);
	Date dayD(2, 14, 2017);
	cout << "\nDate objects: " << dayC << " and " << dayD << " are "
		<< (isEqualTo(dayC, dayD) ? "equal" : "\"NOT\" equal");
	Date dayE(-2, 13, 2017);
	Date dayF(2, 13, 2017);
	cout << "\nDate objects: " << dayE << " and " << dayF << " are "
		<< (isEqualTo(dayE, dayF) ? "equal" : "\"NOT\" equal");
	Date dayG(-2, 13, 2017);
	Date dayH(2, 31, 2017);
	cout << "\nDate objects: " << dayG << " and " << dayH << " are "
		<< (isEqualTo(dayG, dayH) ? "equal" : "\"NOT\" equal") << '\n';

	cout << endl << endl;
	system("PAUSE");
	return 0;
}
