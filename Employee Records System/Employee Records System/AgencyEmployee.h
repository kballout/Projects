#pragma once
#include "HourlyEmployee.h"

using namespace std;

class AgencyEmployee: public HourlyEmployee {
private:
	string companyName;
public:
	//Desc: User sets the company name of the agency employee
	//Pre: Company name string is passed as a parameter
	//Post: Company name is set to the user string
	void setCompanyName(string name);
	//Desc: Returns company name
	//Pre: Company name has been set prior
	//Post: Company name is returned
	string getCompanyName();
	//Desc: Displays a random message out to the intercom
	//Pre: Function is called
	//Post: Random message is displayed
	void makeNoise();
	//Desc: Calculates and sets the amount earned for the employee 
	//Pre: Hourly rate and number of hours worked was set prior
	//Post: Sets the amount earned
	void calculateEmployeePay();
	//Desc: Prints the details of the employee
	//Pre: Function is called and all details (Name, ssn, ID, Tax code, hourly rate, hours worked, company name) have all been set prior
	//Post: Displays employee information
	void printEmployeeRecord();
};