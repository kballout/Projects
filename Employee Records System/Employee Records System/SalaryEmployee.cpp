#include <iostream>
#include "SalaryEmployee.h"

using namespace std;

void SalaryEmployee::setAnnualPay(double value) {
	while (value <= 0) {
		cout << "Please input a vaild annual pay value of greater than 0" << endl;
		cin >> value;
	}
	annualPay = value;
	cout << "Annual pay is set." << endl << endl;
}
double SalaryEmployee::getAnnualPay() {
	return annualPay;
}
double SalaryEmployee::getWeeklyPay() {
	calculateEmployeePay();
	return weeklyPay;
}
void SalaryEmployee::makeNoise() {
	string message1 = "Yeah, if you could remember to put the new cover page on the TPS reports that would be great.";
	string message2 = "Yeah… I'm gonna need you to come in on Saturday.";
	string message3 = "Oh, oh, and I almost forgot. Ahhh, I'm also gonna need you to go ahead and come in on Sunday, too.";
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
void SalaryEmployee::calculateEmployeePay() {
	weeklyPay = annualPay / 52.0;
}
void SalaryEmployee::printEmployeeRecord() {
	cout << "Employee Name: " << GetName() << endl;
	cout << "SSN last 4 digits: " << GetSsn() << endl;
	cout << "Employee ID: " << GetEmployeeNumber() << endl;
	cout << "Tax Rate: " << GetTaxRateCode() << endl;
	cout << "Annual Gross Salary: " << getAnnualPay() << endl;
	double amountOwed = getAnnualPay() - (getAnnualPay() * GetTaxRateCode());
	cout << "Annual Net Salary: " << amountOwed << endl;
	cout << "Weekly Salary: " << getWeeklyPay() << endl;
	cout << "Intercom: "; makeNoise();
	cout << endl;
}