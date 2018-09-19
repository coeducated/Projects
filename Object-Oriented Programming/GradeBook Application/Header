#include <string> // program uses C++ standard string class

#define A_GRADE 4.0	// Weight of letter grade 'A'
#define B_GRADE 3.0	// Weight of letter grade 'B'
#define C_GRADE 2.0 // Weight of letter grade 'C'
#define SIZEOF_ARRAY1 100 // Size of the first array
#define SIZEOF_ARRAY2 6	// Size of the second array

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string ); // Initialize course name
   void setCourseName( std::string ); // Set the course name
   std::string getCourseName() const; // Retrieve the course name
   void initializeData();	// Initializes the private data members. 
   void displayMessage() const; // Display a welcome message
   void inputGrades(); // Input arbitrary number of grades from user
   void displayGradeReport() const;  // Display report based on user input
   void displayInputs() const;	// Display grades entered in a tabulate format
   double calculateGrade() const;	// Calculate the class average
   ~GradeBook();	// Destructor
private:
   std::string courseName; // course name for this GradeBook
   char letterGrades[SIZEOF_ARRAY1]; // Stores letter grades
   int countGrades[SIZEOF_ARRAY2];	// Stores the total count of each type of grade entered
}; // end class GradeBook  
