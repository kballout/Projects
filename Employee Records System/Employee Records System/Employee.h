#pragma once
#include <string>

using namespace std;

class Employee {
private:
	string firstName = "";
	string lastName = "";
	string socialSecurityNumber = "XXX-XX-XXXX";
	string employeeNumber = "XXX-L";
	int taxRateCode;
public:
	//Desc: Sets the employee first name to the user string 
	//Pre: User string is sent as a parameter
	//Post: First name of employee is set
	void SetFirstName(string first);
	//Desc: Sets the employee last name to the user string 
	//Pre: User string is sent as a parameter
	//Post: last name of employee is set
	void SetLastName(string last);
	//Desc: Sets the SSN of the employee 
	//Pre: SSN number in the proper format is sent as a parameter
	//Post: SSN of the employee is set
	void SetSsn(string ssn);
	//Desc: Sets the employee ID
	//Pre: User string is sent as a parameter in the proper format
	//Post: Employee ID number is set
	void SetEmployeeNumber(string empNum);
	//Desc: Sets the employee Tax code
	//Pre: User input is validated (1,2, or 3)
	//Post: Tax rate code of the employee is set
	void SetTaxRateCode(int taxRate);
	//Desc: Returns employee's full name
	//Pre: First name and last name of the employee are joined
	//Post: Employee full name is returned
	string GetName();
	//Desc: Returns the employee's SSN in a special format
	//Pre: Employee SSN is made private with X's revealing only the last 4 digits
	//Post: SSN is returned
	string GetSsn();
	//Desc: Returns employee ID number
	//Pre: Employee ID was set prior
	//Post: Employee ID number is returned
	string GetEmployeeNumber();
	//Desc: Actual tax rate is returned as a decimal
	//Pre: Tax code was set prior and is converted to the suitable decimal
	//Post: Tax rate is returned
	double GetTaxRateCode();
	//Desc: Displays a random message out to the intercom
	//Pre: Function is called
	//Post: Random message is displayed
	virtual void makeNoise();
	//Desc: Abstract method used in other classes
	//Pre: N/A
	//Post: N/A
	virtual void calculateEmployeePay() = 0;
	//Desc: Abstract method used in other classes
	//Pre: N/A
	//Post: N/A
	virtual void printEmployeeRecord() = 0;

	
};