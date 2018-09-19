#include "Complex.h"

using namespace std;

Complex::Complex(double realPart, double imaginaryPart)
	: real(realPart),
	imaginary(imaginaryPart)
{
	this->real = realPart;
	this->imaginary = imaginaryPart;
} // end Complex Constructor

// Overload the extraction operator
ostream &operator<<(ostream&output, const Complex &complex)
{
	if (complex.imaginary > 0)
		output << complex.real << " + " << complex.imaginary << "i";
	else if (complex.imaginary == 0)
		output << complex.real;
	else if (complex.imaginary < 0)
		output << complex.real << " - " << -complex.imaginary << "i";
	return output;
} // end Function operator "<<"
const bool Complex::operator==(const Complex &rhs) const
{
	if ((real == rhs.real) && (imaginary == rhs.imaginary))
		return true;
	else
		return false;
} // end "==" operator
