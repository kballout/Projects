#include <iostream>
#include <vector>
#include "Employee.h"


using namespace std;

void Employee::SetFirstName(string first) {
	firstName = first;
	cout << "First name has been set" << endl << endl;
}
void Employee::SetLastName(string last) {
	lastName = last;
	cout << "Last name has been set" << endl << endl;
	
}
void Employee::SetSsn(string ssn) {
	bool isAlphaFound = true;
	while (isAlphaFound == true) {
		for (int index = 0; index < ssn.length(); index++) {
			if (ssn.length() != 11) {
				break;
			}
			if (ssn.at(3) != '-' || ssn.at(6) != '-') {
				break;
			}
			if (isalpha(ssn.at(index))) {
				isAlphaFound = true;
				break;
			}
			else {
				isAlphaFound = false;
			}
		}
		if (isAlphaFound == true) {
			cout << "The social security number you entered is invalid. Please enter the SSN in the proper format including the hyphens." << endl << "(Example: 123-45-6789)" << endl;
			cin >> ssn;
		}
	}
	for (int index = 0; index < socialSecurityNumber.length(); index++) {
		socialSecurityNumber.at(index) = ssn.at(index);
	}
	cout << "SSN has been set" << endl << endl;
}
void Employee::SetEmployeeNumber(string empNum) {
	vector<char> lastCharOfEmpNum = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I','J','K','L','M' };
	bool isValid = false;
	while (isValid == false) {
		for (int index = 0; index < lastCharOfEmpNum.size(); index++) {
			if (empNum.at(3) != '-') {
				break;
			}
			if (empNum.length() != 5) {
				break;
			}
			if (isalpha(empNum.at(0)) || isalpha(empNum.at(1)) || isalpha(empNum.at(2))) {
				break;
			}
			if (toupper(empNum.at(4)) == lastCharOfEmpNum.at(index)) {
				for (int innerIndex = 0; innerIndex < empNum.length(); innerIndex++) {
					employeeNumber.at(innerIndex) = empNum.at(innerIndex);
				}
				cout << "The employee number has been set" << endl << endl;
				return;
			}
		}
		cout << "The employee number you entered is invalid. Please enter the employee number in the proper format with the hyphen." << endl << "The final character should be a letter A-M. (Example: 123-A)" << endl;
		cin >> empNum;
	}
}
void Employee::SetTaxRateCode(int taxRate) {
	while (taxRate != 1 && taxRate != 2 && taxRate != 3) {
		cout << "You have entered an invalid tax rate. Please enter either 1 for 25%, 2 for 20%, or 3 for 15% tax rate" << endl;
		cin >> taxRate;
	}
	taxRateCode = taxRate;
	cout << "Tax rate has been set" << endl << endl;
}
string Employee::GetName() {
	string fullName = firstName + " " + lastName;
	return fullName;
}
string Employee::GetSsn() {
	for (int index = 0; index < 6; index++) {
		if (socialSecurityNumber.at(index) != '-') {
			socialSecurityNumber.at(index) = 'X';
		}
	}
	return socialSecurityNumber;
}
string Employee::GetEmployeeNumber() {
	return employeeNumber;
}
double Employee::GetTaxRateCode() {
	double value = 0;
	if (taxRateCode == 1) {
		value = 0.25;
	}
	if (taxRateCode == 2) {
		value = 0.20;
	}
	if (taxRateCode == 3) {
		value = 0.15;
	}
	return value;
}
void Employee::makeNoise() {
	string message1 = "I believe you have my stapler.";
	string message2 = "Excuse me, but I think you have my stapler.";
	string message3 = "I could set the building on fire.";
	int random = rand() % 3 + 1;
	if (random == 1) {
		cout << message1 << endl;
	}
	if (random == 2) {
		cout << message2 << endl;
	}
	if (random == 3) {
		cout << message3 << endl;
	}
}
void Employee::calculateEmployeePay() {};
void Employee::printEmployeeRecord() {};