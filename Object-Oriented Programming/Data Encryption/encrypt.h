// .........................................
// Telephone number encryption program - 
// Purpose - A program that encrypts telephone data so that it can be transmitted more securely.
using namespace std; // program uses names from the std namespace

class Encrypt
{
public:
	static const int arraySize = 8;	// Size of array
	Encrypt(int); // default constructor, initializes storeData, displays original and encrypted data
	void storeData(int); // stores last 4 digits of number in array, provides default
	void displayOriginalData(); // display the first 4 elements of the array
	void displayEncryptedData(); // display last 4 elements of the array
	void encryptData(); // encrypt first 4 elements of array and store in the last 4 elements of array

private:
	int digits[arraySize]; // array that stores the original and encrypted data
}; // end class Encrypt
