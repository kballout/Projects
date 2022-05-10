#pragma once
#include "Employee.h"

using namespace std;

class SalaryEmployee: public Employee {
private:
	double annualPay;
	double weeklyPay;
public:
	//Desc: Sets the annual pay for the employee
	//Pre: Annual pay cannot be 0 or less
	//Post: The annual pay of the employee is set
	void setAnnualPay(double value);
	//Desc: Returns the annual pay of the employee
	//Pre: Annual pay has been set prior
	//Post: Annual pay of the employee is returned
	double getAnnualPay();
	//Desc: Returns the weekly pay of the employee
	//Pre: Annual pay has been set to calculate weekly pay
	//Post: Weekly pay of the employee is returned
	double getWeeklyPay();
	//Desc: Displays a random message out to the intercom
	//Pre: Function is called
	//Post: Random message is displayed
	virtual void makeNoise();
	//Desc: Calculates the weekly pay of the employee
	//Pre: Annual pay has been set
	//Post: Weekly pay of the employee is set
	virtual void calculateEmployeePay();
	//Desc: Prints the details of the employee
	//Pre: Function is called and all details (Name, ssn, ID, Tax code, hourly rate, annual pay) have all been set prior
	//Post: Displays employee information
	virtual void printEmployeeRecord();
};