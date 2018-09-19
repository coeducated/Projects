#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define MAXEMPS 100
#define SIZE 99
#define TAXRATE 0.15

void InputEmployeeData(string &full_name, double &PayRate, double &HrsWkd);
string JoinName(string Firstname, string Lastname);
double CalculateGross(double HrsWkd, double PayRate);
double CalculateTax(double GrossPay);
double CalculateNet(double GrossPay, double TaxAmt);
void AddDetailToAccumulators(int EmployeeCount, double store_payrate[], double store_hourswkd[], double store_grosspay[], double store_taxamt[], double store_netpay[], double &totPayRate, double &totHrsWkd, double &totGrossPay, double &totTaxAmt, double &totNetPay, double &avgPayRate, double &avgHrsWkd, double &avgGrossPay, double &avgTaxAmt, double &avgNetPay);
char get_yesno(string question);

int main()
{
	string Firstname;
	string Lastname;
	string full_name;
	string Employees[MAXEMPS];
	double PayRate = 0.00;
	double HrsWkd = 0.00;
	double GrossPay;
	double TaxAmt;
	double NetPay;
	double store_payrate[SIZE];
	double store_hourswkd[SIZE];
	double store_grosspay[SIZE];
	double store_taxamt[SIZE];
	double store_netpay[SIZE];
	int EmployeeCount = 0;
	int i = 0;
	double totPayRate = 0;
	double totHrsWkd = 0;
	double totGrossPay = 0;
	double totTaxAmt = 0;
	double totNetPay = 0;
	double avgPayRate = 0;
	double avgHrsWkd = 0;
	double avgGrossPay = 0;
	double avgTaxAmt = 0;
	double avgNetPay = 0;

	do {
		// Input Functions
		InputEmployeeData(full_name, PayRate, HrsWkd);
		Employees[i] = full_name;
		store_hourswkd[i] = HrsWkd;
		store_payrate[i] = PayRate;
		// Utility Functions
		GrossPay = CalculateGross(HrsWkd, PayRate);
		store_grosspay[i] = GrossPay;
		TaxAmt = CalculateTax(GrossPay);
		store_taxamt[i] = TaxAmt;
		NetPay = CalculateNet(GrossPay, TaxAmt);
		store_netpay[i] = NetPay;
		EmployeeCount++;
		i++;
	} while (get_yesno("Process another employee") == 'Y');



	// Output Functions
	cout << fixed << setprecision(2);
	cout << endl;
	cout << "Employee               Pay     Hours     Gross     Tax      Net" << endl;
	cout << "Name                   Rate    Worked    Pay       Amount   Pay" << endl;
	cout << "========               ====    ======    =====     ======  ======" << endl << endl;
	
	
	for (int i = 0; i < EmployeeCount; i++)
	{
		cout << left << setw(20) << Employees[i] << right << setw(7) << store_payrate[i] << setw(10) <<store_hourswkd[i] << setw(9) <<store_grosspay[i] << setw(11) <<store_taxamt[i] << setw(8) << store_netpay[i] << endl;	
	}

	
	AddDetailToAccumulators(EmployeeCount, store_payrate, store_hourswkd, store_grosspay, store_taxamt, store_netpay, totPayRate, totHrsWkd, totGrossPay, totTaxAmt, totNetPay,avgPayRate, avgHrsWkd, avgGrossPay, avgTaxAmt, avgNetPay);
	cout << endl;
	cout << "Totals " << right << setw(20) << totPayRate  << setw(7) << setw(10) << totHrsWkd << setw(9) << totGrossPay << setw(11) << totTaxAmt << setw(8) << totNetPay << endl;
	cout << endl;
	cout << "Averages " << right << setw(18) << avgPayRate << setw(7) << setw(10) << avgHrsWkd << setw(9) << avgGrossPay << setw(11) << avgTaxAmt << setw(8) << avgNetPay << endl;
	cout << endl;

	system("pause");
	return 0;
}

void InputEmployeeData(string &full_name, double &PayRate, double &HrsWkd)
{
	string Firstname;
	string Lastname;
	cout << "Enter Employee(s) first name: ";
	cin >> Firstname;
	cout << "Enter Employee(s) last name: ";
	cin >> Lastname;
	full_name = JoinName(Firstname, Lastname);
	cout << "Enter Employee(s) pay rate: ";
	cin >> PayRate;
	cout << "Enter Employee(s) hours worked: ";
	cin >> HrsWkd;
}

string JoinName(string Firstname, string Lastname)
{
	string full_name;
	full_name = Lastname + ", " + Firstname;
	return full_name;
}

double CalculateGross(double HrsWkd, double PayRate)
{
	if (HrsWkd <= 40)
		return HrsWkd * PayRate;
	else
		return 40 * PayRate + (HrsWkd - 40) * 1.5 * PayRate;
}

double CalculateTax(double GrossPay)
{
	return GrossPay * TAXRATE;
}

double CalculateNet(double GrossPay, double TaxAmt)
{
	return GrossPay - TaxAmt;
}

void AddDetailToAccumulators(int EmployeeCount, double store_payrate[], double store_hourswkd[], double store_grosspay[], double store_taxamt[], double store_netpay[], double &totPayRate, double &totHrsWkd, double &totGrossPay, double &totTaxAmt, double &totNetPay, double &avgPayRate, double &avgHrsWkd, double &avgGrossPay, double &avgTaxAmt, double &avgNetPay)
{
	for (int i = 0; i < EmployeeCount; i++)
	{
		totPayRate += store_payrate[i];
		totHrsWkd += store_hourswkd[i];
		totGrossPay += store_grosspay[i];
		totTaxAmt += store_taxamt[i];
		totNetPay += store_netpay[i];
	}
	avgPayRate = totPayRate / EmployeeCount;
	avgHrsWkd = totHrsWkd / EmployeeCount;
	avgGrossPay = totGrossPay / EmployeeCount;
	avgTaxAmt = totTaxAmt / EmployeeCount;
	avgNetPay = totNetPay / EmployeeCount;
	
}

char get_yesno(string question)
{
	char answer; 

	do {
		cout << question << " (Y/N)? ";
		cin >> answer;
		if (answer == 'y') {
			answer = 'Y';
		}
		else if (answer == 'n') {
			answer = 'N';
		}
		if (answer != 'Y' && answer != 'N') {
			cout << "Please type 'Y' for yes or 'N' for no"
				<< endl << endl;
		}
	} while (answer != 'Y' && answer != 'N');

	return answer;
}
