// Telephone number encryption program - 
// Purpose - A program that encrypts telephone data so that it can be transmitted more securely.
#include <iostream> // allows program to output data to the screen
#include <iomanip> // parameterized stream manipulators
#include <cmath> // standard C++ math library
#include "Encrypt.h" // include definition of class Encrypt
using namespace std; 

// Encrpyt constructor
Encrypt::Encrypt(int num)
{
	cout << "\n** The default constructor is called" << endl;
	cout << "   and the passed in number is " << num << ".**" << endl;
	storeData(num); // calls function to initialize storeData
	displayOriginalData(); // calls function to display original data
	displayEncryptedData(); // calls function to display encrypted data
}

// Function that stores the data in the array
// Pre - An 8 digit number is passed into the function
//
// Post - Nothing is returned from the function. If the data is <= 0, elements 0-3 are set to 9436, Else, elements 0-3 are stored with the last 4 digits
void Encrypt::storeData(int data)
{
	if (data <= 0) // set default values in the array if data is <= 0
	{
		digits[0] = 9;	// Set 1st element of the array to 9
		digits[1] = 4;	// Set 2nd element of the array to 4
		digits[2] = 3;	// Set 3rd element of the array to 3
		digits[3] = 6;	// Set 4th element of the array to 6
		cout << endl;
		cout << " XXX The inputed number is less than or equal to 0." << endl; 
		cout << "     The number is reset to 9436. XXX" << endl; 
	}
	else
	{
		data %= 10000; // converts data into a 4 digit number
		digits[3] = data % 10; // stores the 4th element in the array
		digits[2] = (data / 10) % 10; // stores the 3rd element in the array
		digits[1] = ((data / 10) / 10) % 10; // stores the 2nd element in the array
		digits[0] = (((((data / 10) / 10) / 10) % 10)); // stores the 2nd element in the array
	}
	encryptData();	// calls function to encrypt stored data	
}

// Function that outputs the first 4 elements in the array
// Pre - Nothing is passed into the function
//
// Post - Nothing is returned from the function. The original data is displayed
void Encrypt::displayOriginalData()
{
	cout << "\n     The original data is  ";
	for (int i = 0; i < 4; i++) // loop through each element in the array, starting with the 1st one
	{
		cout << " " << digits[i];
	}
	cout << endl;
}

// Function that outputs the last 4 elements in the array	
// Pre - Nothing is passed into the function
//
// Post - Nothing is returned from the function. The encrypte data is now displayed
void Encrypt::displayEncryptedData()
{
	cout << "     The encrypted data is ";
	for (int i = 4; i < 8; i++) // loop through each element in the array, starting with the 4th one
	{
		cout << " " << digits[i];
	}
	cout << endl;
}

// Function that encrypts the firt 4 digits and stores them in the last 4 digits
// Pre - Nothing is passed into the function
//
// Post - Nothing is returned from the function. The data is now encrypted
void Encrypt::encryptData()
{
	// Adds 7 to the digit and mod by 10 to get the encrypted digit
	digits[4] = ((digits[2] + 7) % 10); // Copy the 3rd element of the array to the 5th element
	digits[5] = ((digits[3] + 7) % 10); // Copy the 4rd element of the array to the 6th element
	digits[6] = ((digits[0] + 7) % 10); // Copy the 1st element of the array to the 7th element
	digits[7] = ((digits[1] + 7) % 10); // Copy the 2nd element of the array to the 8th element
}
