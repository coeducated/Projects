#include <iostream>
#include <iomanip>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// Constructor initializes courseName with string supplied as argument.
// Initializes counter data members to 0.
GradeBook::GradeBook( string name )
{
	cout << "The Grade Book Constructor is called" << endl;
	initializeData(); // call initializeData function
	setCourseName(name); // name to setCourseName
	displayMessage(); // call displayMessage function
	cout << "The Grade Book, " << getCourseName() << ", contains" << endl << endl << endl;
	displayGradeReport(); // call displayGradeReport function
	cout << "*****The end of Grade Book Constructor.*****" << endl << endl << endl;
} 

// *Function Prototype*
// Pre: A string is passed into the function.
// Post: Nothing is returned. The coursename is set.
void GradeBook::setCourseName( string name )
{
   if ( name.size() <= 30 ) 
      courseName = name; 
   else
   { 
      courseName = name.substr( 0, 30 ); // select first 25 characters
      cerr << "Name \"" << name << "\" exceeds maximum length (30).\n"
         << "Limiting courseName to first 30 characters.\n" << endl;
   } 
} 

// *Function Prototype*
// Pre: Nothing is passed into the function.
// Post: The private data is returned. It retrieves the course name.
string GradeBook::getCourseName() const
{
   return courseName;
} 

// *Function Prototype*
// Pre: Nothing is passed into the function
// Post: Nothing is returned from the function. The data is initialized.
void GradeBook::initializeData() 
{
	courseName = ""; // initialize courseName to an empty string
	countGrades[0] =  // initialize a count to 0
		countGrades[1] =  // initialize b count to 0
		countGrades[2] =  // initialize c count to 0
		countGrades[3] =  // initialize d count to 0
		countGrades[4] =  // initialize f count to 0
		countGrades[5] = 0;  // initialize error count to 0
	letterGrades[SIZEOF_ARRAY1] = NULL;
}

// *Function Prototype*
// Pre: Nothing is passed into the function.
// Post: Nothing is returned from the function. It displays a welcome message.
void GradeBook::displayMessage() const
{
   // this statement calls getCourseName to get the 
   // name of the course this GradeBook represents
   cout << "Welcome to the grade book for\n" << getCourseName() << "!\n" 
      << endl;
} 

// *Function Prototype*
// Pre: Nothing is passed into the function.
// Post: Nothing is returned from the function. This collects input from the user.
void GradeBook::inputGrades() 
{
   cout << setw(8) << " " << "Enter letter grades." << endl;
   cout << setw(8) << " " << "Or Enter the EOF character to end input." << endl;
   cout << setw(8) << " " << "(Use Ctl + D, or Ctl + Z)" << endl;

   // loop until user types end-of-file key sequence
   for (int grade = 0; ((letterGrades[grade] = cin.get()) != EOF) && (grade < 100); grade++)
   {
	   switch (letterGrades[grade]) // switch statement nested in while
	   {
	   case 'A': case'a': // grade was uppercase A / lowercase a
		   letterGrades[grade] = toupper(letterGrades[grade]); // convert lowercase to uppercase
		   countGrades[0]++; 
		   cout << setw(8) << " " << "Enter letter grades." << endl;
		   cout << setw(8) << " " << "-->     Or Enter the EOF character to end input." << endl;
		   cout << setw(8) << " " << "(Use Ctl + D, or Ctl + Z)" << endl;
		   break; 

	   case 'B': case'b': // grade was uppercase B / lowercase b
		   letterGrades[grade] = toupper(letterGrades[grade]); // convert lowercase to uppercase
		   countGrades[1]++; 
		   cout << setw(8) << " " << "Enter letter grades." << endl;
		   cout << setw(8) << " " << "-->     Or Enter the EOF character to end input." << endl;
		   cout << setw(8) << " " << "(Use Ctl + D, or Ctl + Z)" << endl;
		   break; 

	   case 'C': case'c': // grade was uppercase C / lowercase c
		   letterGrades[grade] = toupper(letterGrades[grade]); // convert lowercase to uppercase
		   countGrades[2]++; 
		   cout << setw(8) << " " << "Enter letter grades." << endl;
		   cout << setw(8) << " " << "-->     Or Enter the EOF character to end input." << endl;
		   cout << setw(8) << " " << "(Use Ctl + D, or Ctl + Z)" << endl;
		   break; 

	   case 'D': case'd': // grade was uppercase A / lowercase a
		   letterGrades[grade] = toupper(letterGrades[grade]); // convert lowercase to uppercase
		   countGrades[3]++; 
		   cout << setw(8) << " " << "Enter letter grades." << endl;
		   cout << setw(8) << " " << "-->     Or Enter the EOF character to end input." << endl;
		   cout << setw(8) << " " << "(Use Ctl + D, or Ctl + Z)" << endl;
		   break; 

	   case 'F': case'f': // grade was uppercase A / lowercase a
		   letterGrades[grade] = toupper(letterGrades[grade]); // convert lowercase to uppercase
		   countGrades[4]++; 
		   cout << setw(8) << " " << "Enter letter grades." << endl;
		   cout << setw(8) << " " << "-->     Or Enter the EOF character to end input." << endl;
		   cout << setw(8) << " " << "(Use Ctl + D, or Ctl + Z)" << endl;
		   break; 

	   case '\n': 
	   case '\t': 
	   case ' ': 
		   break; 

	   default: // catch all other characters and mention that incorrect grade was entered
		   countGrades[5]++; 
		   cout << setw(8) << " " << "XXXX An incorrect letter grade entered.  XXXX" << endl;
		   cout << setw(8) << "\"" << letterGrades[grade] << "\"" << " is not a proper letter grade." << endl << endl;
		   cout << setw(8) << " " << "Enter letter grades." << endl;
		   cout << setw(8) << " " << "-->     Or Enter the EOF character to end input." << endl;
		   cout << setw(8) << " " << "(Use Ctl + D, or Ctl + Z)" << endl;
	   } 
   } 
} 

// *Function Prototype*
// Pre: Nothing is passed into the function
// Post: Nothing is returned from the function. This displays a grade report with the total number of data entered, the total number of students that recieved grades, the number
// of students who recieved each grade, and the class average.
void GradeBook::displayGradeReport() const
{
	cout << endl << endl << "The total number of data entered is " << countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4] + countGrades[5];
	cout << "\nThe total number of students receive grades is " << countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4] << endl;
	cout << "Number of students who received each letter grade:"
		<< "\nA:       " << countGrades[0] // display number of A grades
		<< "\nB:       " << countGrades[1] // display number of B grades
		<< "\nC:       " << countGrades[2] // display number of C grades
		<< "\nD:       " << countGrades[3] // display number of D grades
		<< "\nF:       " << countGrades[4] // display number of F grades
		<< "\nError:   " << countGrades[5] // display number of incorrect grades
		<< endl;

	if (countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4] != 0)
	{
		// call function calculateGrade and display the calculated GPA
		cout << "\nThe class average is: " << fixed << setprecision(2) << calculateGrade()
			<< endl << endl << endl;
	}
	else
	{
		cout << "\nThe class average is: 0.0" << endl << endl;
	}
} 

// *Function Prototype*
// Pre: Nothing is passed into the function.
// Post: Nothing is returned from the function. The data entered from the user is displayed in a 4 row table.
void GradeBook::displayInputs() const
{
	cout << "The data entered is listed at the following:";
	for (int a = 0; a < countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4] + countGrades[5]; a++)
	{
		if ((a % 4) == 0) // Start new line after 4 elements have been displayed
		{
			cout << endl;
		} 
		cout << "[" << a << "] -> " << left << setw(9) << letterGrades[a];
	}; 
}

// *Function Prototype*
// Pre: Nothing is passed into the function.
// Post: The calculated GPA is returned from the function.
double GradeBook::calculateGrade() const
{
	return ((A_GRADE * countGrades[0] + B_GRADE * countGrades[1] + C_GRADE * countGrades[2] + countGrades[3]) /
		(countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4]));
}

// Destructor
// Pre: Nothing is passed into this functiom
// Post: Nothing is returned from this function. This is a destructor to clear memory.
GradeBook::~GradeBook()
{
	cout << "Destructor is called" << endl << endl;
	string name;
	name = ""; 
	setCourseName(name); 
}
