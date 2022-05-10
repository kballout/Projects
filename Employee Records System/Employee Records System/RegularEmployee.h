#pragma once
#include "HourlyEmployee.h"

class RegularEmployee : public HourlyEmployee {
private:
	double overtimeHours;
public:
	//Desc: Sets the number of overtime hours for the employee
	//Pre: Employee worked 40 regular hours and overtime hours does not exceed 20
	//Post: Employee's overtime hours are set. Agency employees have 0 set for overtime
	void setOvertimeHours(double hours);
	//Desc: Returns the number of overtime hours for the employee
	//Pre: Overtime hours for the employee have been set prior
	//Post: Employee's overtime hours are returned
	double getOvertimeHours();
	//Desc: Calculates the amount earned for the employee
	//Pre: Hourly rate, number of hours, and overtime hours have been set prior. 
	//Post: The amount earned for the employee is set
	virtual void calculateEmployeePay();
	//Desc: Prints the details of the employee
	//Pre: Function is called and all details (Name, ssn, ID, Tax code, hourly rate, hours worked, overtime hours) have all been set prior
	//Post: Displays employee information
	virtual void printEmployeeRecord();
};