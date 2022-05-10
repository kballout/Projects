#include <iostream>
#include <string>
#include "AgencyEmployee.h"

using namespace std;

void AgencyEmployee::setCompanyName(string name) {
	companyName = name;
	cout << "Company name is set" << endl << endl;
}
string AgencyEmployee::getCompanyName() {
	return companyName;
}
void AgencyEmployee::makeNoise() {
	string message1 = "Right, so there's three more people we can easily lose.";
	string message2 = "So what would you say you do here?";
	string message3 = "We fixed the glitch.";
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
void AgencyEmployee::calculateEmployeePay() {
	setAmountEarned(0);
}
void AgencyEmployee::printEmployeeRecord() {
	cout << "Employee Name: " << GetName() << endl;
	cout << "SSN last 4 digits: " << GetSsn() << endl;
	cout << "Employee ID: " << GetEmployeeNumber() << endl;
	cout << "Tax Rate: " << GetTaxRateCode() << endl;
	cout << "Hourly Pay Rate: " << getHourlyRate() << endl;
	cout << "Hours Worked: " << getHoursWorked() << endl;
	calculateEmployeePay();
	cout << "Gross Amount Earned: " << getAmountEarned() << endl;
	double netIncome = getAmountEarned() - (getAmountEarned() * GetTaxRateCode());
	cout << "Net Income: " << netIncome << endl;
	cout << "Agency Company: " << companyName << endl;
	cout << "Intercom: "; makeNoise();
	cout << endl;
}