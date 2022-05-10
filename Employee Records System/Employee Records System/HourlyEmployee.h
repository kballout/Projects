#pragma once
#include "Employee.h"

using namespace std;

class HourlyEmployee: public Employee {
private:
	double hourlyPayRate;
	double hoursWorked;
	double amountEarned;
public:
	//Desc: Sets the hourly rate for the employee
	//Pre: Validates the hourly rate is between $15-$100
	//Post: The employee's hourly rate is set
	void setHourlyRate(double value);
	//Desc: Sets the number of hours worked for the employee
	//Pre: Validates the number of hours does not exceed 40
	//Post: The employee's number of hours worked is set
	void setHoursWorked(double value);
	//Desc: Sets the total amount earned for the employee
	//Pre: Hourly rate and number of hours worked have been set prior. As well as the optional overtime.
	//Post: The employee's amount earned is set
	void setAmountEarned(double additionalPay);
	//Desc: Returns the hourly rate of the employee
	//Pre: Hourly rate was set prior
	//Post: The employee's hourly rate is returned
	double getHourlyRate();
	//Desc: Returns the number of hours worked of the employee
	//Pre: Hours worked for the employee was set prior
	//Post: The employee's number of hours worked is returned
	double getHoursWorked();
	//Desc: Returns the amount earned of the employee
	//Pre: Amount earned of the employee has been set prior
	//Post: The employee's amount earned is returned
	double getAmountEarned();
	//Desc: Abstract method used for other classes
	//Pre: N/A
	//Post: N/A
	virtual void calculateEmployeePay() = 0;
};