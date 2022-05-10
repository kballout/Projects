#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Employee.h"
#include "AgencyEmployee.h"
#include "HourlyEmployee.h"
#include "RegularEmployee.h"
#include "SalaryEmployee.h"

using namespace std;
//Desc: Add a salary based employee
//pre: Function is called
//post: User adds all details of the employee. Finally the employee is added to the list of employees
void addSalaryEmployee(vector<Employee*> &listOfEmployees) {
	SalaryEmployee* newSalaryEmployee = new SalaryEmployee;
	string firstName;
	string lastName;
	string ssn;
	string empNum;
	int taxCode;
	double annualPay;
	cout << "What is the first name of the employee?" << endl;
	cin >> firstName;
	newSalaryEmployee->SetFirstName(firstName);
	cout << "What is the last name of the employee?" << endl;
	cin >> lastName;
	newSalaryEmployee->SetLastName(lastName);
	cout << "Please enter the Social Security number of " << firstName << " in the following format including the hyphens." << endl << "(example: 123-45-6789)" << endl;
	cin >> ssn;
	newSalaryEmployee->SetSsn(ssn);
	cout << "Please enter " << firstName << "'s employee ID in the following format including the hyphen.(example: 123-L)" << endl << "Note: the last digit must be a letter A-M" << endl;
	cin >> empNum;
	newSalaryEmployee->SetEmployeeNumber(empNum);
	cout << "Please enter a Tax Rate Code for " << firstName << ". 1 for 25%, 2 for 20%, or 3 for 15%" << endl;
	cin >> taxCode;
	newSalaryEmployee->SetTaxRateCode(taxCode);
	cout << "Please enter a value for the annual pay. Note: must be greater than 0" << endl;
	cin >> annualPay;
	newSalaryEmployee->setAnnualPay(annualPay);
	listOfEmployees.push_back(newSalaryEmployee);
}
//Desc: Add a regular based employee
//pre: Function is called
//post: User adds all details of the employee. Finally the employee is added to the list of employees
void addRegularEmployee(vector<Employee*> &listOfEmployees) {
	RegularEmployee* newRegularEmployee = new RegularEmployee;
	string firstName;
	string lastName;
	string ssn;
	string empNum;
	int taxCode;
	double hourlyRate;
	double hoursWorked;
	double overtime;
	cout << "What is the first name of the employee?" << endl;
	cin >> firstName;
	newRegularEmployee->SetFirstName(firstName);
	cout << "What is the last name of the employee?" << endl;
	cin >> lastName;
	newRegularEmployee->SetLastName(lastName);
	cout << "Please enter the Social Security number of " << firstName << " in the following format including the hyphens." << endl << "(example: 123-45-6789)" << endl;
	cin >> ssn;
	newRegularEmployee->SetSsn(ssn);
	cout << "Please enter " << firstName << "'s employee ID in the following format including the hyphen.(example: 123-L)" << endl << "Note: the last digit must be a letter A-M" << endl;
	cin >> empNum;
	newRegularEmployee->SetEmployeeNumber(empNum);
	cout << "Please enter a Tax Rate Code for " << firstName << ". 1 for 25%, 2 for 20%, or 3 for 15%" << endl;
	cin >> taxCode;
	newRegularEmployee->SetTaxRateCode(taxCode);
	cout << "Please enter a value for the hourly rate between $15 to $100 per hour" << endl;
	cin >> hourlyRate;
	newRegularEmployee->setHourlyRate(hourlyRate);
	cout << "Please enter the amount of hours " << firstName << " worked" << endl;
	cin >> hoursWorked;
	newRegularEmployee->setHoursWorked(hoursWorked);
	cout << "Enter the amount of overtime hours " << firstName << " worked" << endl << "Note: an employee must have worked the 40 regular hours to receive overtime hours. Also the overtime hours may not exceed 20" << endl;
	cin >> overtime;
	newRegularEmployee->setOvertimeHours(overtime);
	listOfEmployees.push_back(newRegularEmployee);
}
//Desc: Add an agency based employee
//pre: Function is called
//post: User adds all details of the employee. Finally the employee is added to the list of employees
void addAgencyEmployee(vector<Employee*> &listOfEmployees) {
	AgencyEmployee* newAgencyEmployee = new AgencyEmployee;
	string firstName;
	string lastName;
	string ssn;
	string empNum;
	int taxCode;
	double hourlyRate;
	double hoursWorked;
	string companyName;
	cout << "What is the first name of the employee?" << endl;
	cin >> firstName;
	newAgencyEmployee->SetFirstName(firstName);
	cout << "What is the last name of the employee?" << endl;
	cin >> lastName;
	newAgencyEmployee->SetLastName(lastName);
	cout << "Please enter the Social Security number of " << firstName << " in the following format including the hyphens." << endl << "(example: 123-45-6789)" << endl;
	cin >> ssn;
	newAgencyEmployee->SetSsn(ssn);
	cout << "Please enter " << firstName << "'s employee ID in the following format including the hyphen.(example: 123-L)" << endl << "Note: the last digit must be a letter A-M" << endl;
	cin >> empNum;
	newAgencyEmployee->SetEmployeeNumber(empNum);
	cout << "Please enter a Tax Rate Code for " << firstName << ". 1 for 25%, 2 for 20%, or 3 for 15%" << endl;
	cin >> taxCode;
	newAgencyEmployee->SetTaxRateCode(taxCode);
	cout << "Please enter a value for the hourly rate between $15 to $100 per hour" << endl;
	cin >> hourlyRate;
	newAgencyEmployee->setHourlyRate(hourlyRate);
	cout << "Please enter the amount of hours " << firstName << " worked" << endl;
	cin >> hoursWorked;
	newAgencyEmployee->setHoursWorked(hoursWorked);
	cout << "What is the name of the company Agency " << firstName << " Works for?" << endl;
	cin >> companyName;
	newAgencyEmployee->setCompanyName(companyName);
	listOfEmployees.push_back(newAgencyEmployee);
}
//Desc: Displays current list of employees
//Pre: Employees have been added to the list prior to calling this function
//Post: List of all employees and their details are displayed
void displayCurrentEmployees(vector<Employee*> &listOfEmployees) {
	cout << endl << endl;
	for (int index = 0; index < listOfEmployees.size(); index++) {
		listOfEmployees.at(index)->printEmployeeRecord();
		cout << endl << endl;
	}
}


int main() {
	srand(time(0));
	int choice = 0;
	vector<Employee*> listOfEmployees;
	
	do {
		cout << "Welcome to the Employee Record System" << endl;
		cout << "-------------------------------------" << endl;
		cout << "Main Menu" << endl;
		cout << "Please choose one of the following options" << endl;
		cout << "1) Add a Salary Employee" << endl;
		cout << "2) Add a Regular Employee" << endl;
		cout << "3) Add a Agency Employee" << endl;
		cout << "4) Display all current employees" << endl;
		cout << "5) Quit Program" << endl;
		cin >> choice;
		
		if (choice == 1) {
			addSalaryEmployee(listOfEmployees);
		}
		if (choice == 2) {
			addRegularEmployee(listOfEmployees);
		}
		if (choice == 3) {
			addAgencyEmployee(listOfEmployees);
		}
		if (choice == 4) {
			displayCurrentEmployees(listOfEmployees);
		}
	} while (choice != 5);
	
	return 0;
}