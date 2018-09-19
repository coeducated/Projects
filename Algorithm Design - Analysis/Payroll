#include <iostream>					// Provides cout, cin, endl, fixed
#include <iomanip>					// Provides setw, setprecision
#include <string>					// Provides the library for the string data type
#include <cstdlib>					// provides exit
#include <fstream>					// provides ofstream, ifstream

using namespace std;

#define MIN_HOURS			 0.00	// minimum hours per week
#define MAX_HOURS		    60.00	// maximum hours per week
#define MIN_RATE			 0.00	// minimum pay rate
#define MAX_RATE			99.99	// maximum pay rate
#define REGULAR_HOURS_LIMIT 40.00	// hours at which overtime begins
#define OVERTIME_RATE		 1.50	// overtime rate
#define TAX_RATE			 0.30	// tax rate (30%)
#define PARKING_RATE	    10.00	// parking deduction
#define TRANSIT_RATE		 5.00	// transit deduction
#define SIZE				   10	// array size

void input_employee_data(ifstream &infile, string &full_name, double &hours, double &hourly_rate, double &deductions);
string join_name(string first_name, string last_name);
void split_hours(double hours, double &regular_hours, double &overtime_hours);
double calculate_gross_pay(double regular_hours, double overtime_hours, double hourly_rate);
double calculate_tax(double gross_pay, double tax_rate);
double calculate_net_pay(double gross_pay, double tax, double deductions);
void output_payroll_data(ofstream &outfile, string full_name, double regular_hours, double overtime_hours, double hourly_rate, double gross_pay, double tax, double deductions, double net_pay);
void sort_employees(double store_gp[], string name[], int count);

int main()
{
	ofstream outfile;				// output stream
	ifstream infile;				// input stream
	int      count,					// number of employees processed
		     i;						// general array-element counter
	string   full_name,				// employee's full name
		     name[SIZE];			// array for employee names
	double   hours,					// number of hours worked
		     regular_hours,			// number of regular hours
		     overtime_hours,		// number of overtime hours
		     hourly_rate,			// hourly pay rate
		     gross_pay,				// employee's gross pay
		     tax,					// employee's tax amount
		     deductions,			// after-tax deductions
		     net_pay,				// employee's net pay
		     total_gross_pay,		// total gross pay of employees
		     min_gross_pay,			// minimum gross_pay
		     max_gross_pay,			// maximum_gross_Pay
		     average_gross_pay,		// average gross_pay
		     store_gp[SIZE],	    // array for gross pay
		     sum;					// accumulator for array

	infile.open("c:\\temp\\empdata.txt");
	if (!infile.is_open()) {
		cout << "Cannot open empdata file" << endl;
		exit(EXIT_FAILURE);
	}

	outfile.open("c:\\temp\\report.txt");
	if (!outfile.is_open()) {
		cout << "Cannot open output file" << endl;
		exit(EXIT_FAILURE);
	}
		 
	cout << fixed << setprecision(2);
	
	// Initialize counters and accumulators
	count = 0;
	total_gross_pay = 0.00;
	sum = 0;
	i = 0;
	
	outfile << endl;
	outfile << "                      Reg.   Ovt.   Hourly  Gross  "
		<< "                  Net    " << endl;
	outfile << "Name                  Hours  Hours  Rate    Pay    "
		<< "  Taxes   Deduct  Pay    " << endl;
	outfile << "====================  =====  =====  ======  ======="
		<< "  ======  ======  =======" << endl;

	// Attempt to read information from the first employee in the file
	input_employee_data(infile, full_name, hours, hourly_rate, deductions);

	while (!infile.eof() && count < SIZE)
	{
		// Process the employees from the file
		if (count < SIZE) {
			name[i] = full_name;

			// Processing section
			split_hours(hours, regular_hours, overtime_hours);
			gross_pay = calculate_gross_pay(regular_hours, overtime_hours, hourly_rate);

			store_gp[i] = gross_pay;
			i++;

			tax = calculate_tax(gross_pay, TAX_RATE);
			net_pay = calculate_net_pay(gross_pay, tax, deductions);

			// Output section
			output_payroll_data(outfile, full_name, regular_hours, overtime_hours, hourly_rate, gross_pay, tax, deductions, net_pay);

			// Increment counters and accumulators
			count++;
			total_gross_pay += gross_pay;

			// Sort gross pay from largest to smallest
			sort_employees(store_gp, name, count);

			// Attempt to read information for the next employee in the file
			input_employee_data(infile, full_name, hours, hourly_rate, deductions);
		}
	}

	infile.close();

	// Output summary information
	cout << endl;
	cout << "Employees processed: " << count << endl;
	cout << "Total gross pay: $" << total_gross_pay << endl;
	cout << endl;
	cout << endl;

	// Output payroll summary
	outfile << endl;
	outfile << "==============================" << endl;
	outfile << "   Employee Payroll Summary   " << endl;
	outfile << "==============================" << endl;
	outfile << endl;
	outfile << "                      Gross   " << endl;
	outfile << "Name                  Pay     " << endl;
	outfile << "====================  ========" << endl;

	for (i = 0; i < count; i++) {
		outfile << left << setw(20) << name[i] << " " << right << setw(9) << store_gp[i] << endl;
	}
	outfile << endl;

	for (i = 0; i < count; i++) {
		sum += store_gp[i];
	}
	outfile << "Total gross pay  : $" << " " << setw(7) << sum << endl;
	average_gross_pay = sum / count;
	outfile << "Average gross pay: $" << " " << setw(7) << average_gross_pay << endl;

	min_gross_pay = store_gp[0];
	max_gross_pay = store_gp[0];

	for (i = 1; i < count; i++) {
		if (store_gp[i] < min_gross_pay) {
			min_gross_pay = store_gp[i];
		}
		if (store_gp[i] > max_gross_pay) {
			max_gross_pay = store_gp[i];
		}
	}

	outfile << "Minimum gross pay: $" << " " << setw(7) << min_gross_pay << endl;
	outfile << "Maximum gross pay: $" << " " << setw(7) << max_gross_pay << endl;
	outfile << endl;
	
	outfile.close();
}

//
// An input module that reads the employee's name, hours, and hourly pay rate from
// the user.The module prompts the user to enter the employee�s first and last names,
// but provides a concatenated full name in the form �Last, First�
//
// Pre : User enters employee's first and last name, their hours worked, and hourly rate.
// Post: The name is concatenated into a full name. Deductions are calculated.
//
void input_employee_data(ifstream &infile, string &full_name, double &hours,
	double &hourly_rate, double &deductions)
{
	string first_name,	// employee's first name, input by user
		   last_name;	// employee's last name, input by user
	
	infile >> first_name;
	infile >> last_name;

	full_name = join_name(first_name, last_name);

	infile >> hours;
	infile >> hourly_rate;
	infile >> deductions;
}

//
// A processing module that concatenates an employee's first and last
// names to a full name in the form "Last, First".
//
// Pre : The 'first_name', 'last_name' parameters contain the users input value.
// Post: The users input data is conctaneated into a full name value in the form of last, first
//
string join_name(string first_name, string last_name)
{
	string full_name;	   // employee's concatenated full name
	
	full_name = last_name + ", " + first_name;
	
	return full_name;
}

//
// A processing module that splits the total number of hours worked by
// an employee into regular and overtime hours.
//
// Pre : The 'hours' parameter contains the number of hours worked.
// Post: The 'regular_hours', and 'overtime_hours' parameters are calculated
//
void split_hours(double hours, double &regular_hours,
	double &overtime_hours)
{
	if (hours <= REGULAR_HOURS_LIMIT) {
		regular_hours = hours;
		overtime_hours = 0.0;
	}
	else {
		regular_hours = REGULAR_HOURS_LIMIT;
		overtime_hours = hours - REGULAR_HOURS_LIMIT;
	}
}

//
// A processing module that calculates an employee's gross pay, given
// the number of hours worked (regular and overtime) and hourly rate.
//
// Pre : The 'regular_hours', 'overtime_hours', and 'hourly_rate' parameters were calculated and contain their respective values.
// Post: The 'gross_pay' parameter is calculated given the above parameters.
//
double calculate_gross_pay(double regular_hours, double overtime_hours,
	double hourly_rate)
{
	double gross_pay;	// employee's gross pay
	
	gross_pay = (regular_hours * hourly_rate) + (overtime_hours *
		          hourly_rate * OVERTIME_RATE);
	
	return gross_pay;
}

//
// A processing module that calculates the tax on an employee's gross
// pay.
//
// Pre : The 'gross_pay' parameter contains a calculated value; The 'tax_rate' parameter contains a global constant.
// Post: The 'tax' parameter is calculated.
//
double calculate_tax(double gross_pay, double tax_rate)
{
	double tax;	 // employee's tax amount
	
	tax = gross_pay * tax_rate;
	
	return tax;
}

//
// A processing module that calculates an employee's net pay, given
// gross pay, taxes and deductions.
//
// Pre : The 'gross_pay' and 'tax' parameters contain the users calculated values; The 'deductions' parameter contains a global constant.
// Post: The 'net_pay' parameter contains a calculated value
//
double calculate_net_pay(double gross_pay, double tax,
	double deductions)
{
	double net_pay;	 // employee's net pay
	
	net_pay = gross_pay - tax - deductions;
	
	return net_pay;
}

//
// An output module that displays formatted payroll data for an
// employee, including headers.
//
// Pre : The 'full_name', 'regular_hours', 'overtime_hours', 'hourly_rate', 'gross_pay', 'tax', 'deductions', and 'net_pay' parameters contain the users calculated values
// based on their data input.
// Post: (none)
//
void output_payroll_data(ofstream &outfile, string full_name, double regular_hours,
double overtime_hours, double hourly_rate, double gross_pay,
	double tax, double deductions, double net_pay)
{
	outfile << fixed << setprecision(2);
	outfile << left << setw(20) << full_name << "  ";
	outfile << right;
	outfile << setw(5) << regular_hours << "  ";
	outfile << setw(5) << overtime_hours << "  ";
	outfile << setw(6) << hourly_rate << "  ";
	outfile << setw(7) << gross_pay << "  ";
	outfile << setw(6) << tax << "  ";
	outfile << setw(6) << deductions << "  ";
	outfile << setw(7) << net_pay << endl;
}

// A sorting module that arranges the gross pay from largest to smallest
//
// Pre : takes in the store_gp and name arrays containing values from a txt file
// Post: Sorts the gross pay from largest to smallest
//
void sort_employees(double store_gp[], string name[], int count)
{
	int pass,			// pass counter
		i;				// general counter for comparing adjacent elements
	bool swaps;			// flags if elements were swapped during a pass
	double temp_gp;		// facilitates swapping of adjacent values
	string temp_name;	// facilitates swapping of adjacent strings 

	swaps = true;
	for (pass = 1; (pass < count) && swaps; pass++) {
		swaps = false;

		for (i = 0; i < count - pass; i++) {
			if (store_gp[i] < store_gp[i + 1]) {
				temp_name = name[i];
				temp_gp = store_gp[i];
				store_gp[i] = store_gp[i + 1];
				store_gp[i + 1] = temp_gp;
				name[i] = name[i + 1];
				name[i + 1] = temp_name;

				swaps = true;
			}
		}
	}
}
