#pragma once
#include <iostream>

using namespace std;

class Complex
{
public:
	Complex(double = 0.0, double = 0.0); // Constructor
	const bool operator==(const Complex &rhs) const; // "==" operator
private:
	friend ostream &operator<<(ostream&output, const Complex&complex);
	double real; // Real number
	double imaginary; // Imaginary number
}; //end class Complex
