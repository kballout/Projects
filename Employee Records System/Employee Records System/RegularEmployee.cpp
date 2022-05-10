#include <iostream>
#include "RegularEmployee.h"

using namespace std;

void RegularEmployee::setOvertimeHours(double hours) {
	if (getHoursWorked() == 40) {
		while (hours > 20) {
			cout << "An employee may not work more than 20 hours of overtime, please enter a valid number" << endl;
			cin >> hours;
		}
		overtimeHours = hours;
		cout << "Overtime hours are set" << endl << endl;
	}
	else {
		cout << "An employee may not get overtime hours if they havent worked the regular 40 hours first" << endl;
		cout << "Overtime hours will be set to 0" << endl;
		overtimeHours = 0;
	}
}
double RegularEmployee::getOvertimeHours() {
	return overtimeHours;
}
void RegularEmployee::calculateEmployeePay() {
	double additionalPay = 0;
	additionalPay = (getHourlyRate() * 1.5 * getOvertimeHours());
	setAmountEarned(additionalPay);
}
void RegularEmployee::printEmployeeRecord() {
	cout << "Employee Name: " << GetName() << endl;
	cout << "SSN last 4 digits: " << GetSsn() << endl;
	cout << "Employee ID: " << GetEmployeeNumber() << endl;
	cout << "Tax Rate: " << GetTaxRateCode() << endl;
	cout << "Hourly Pay Rate: " << getHourlyRate() << endl;
	cout << "Hours Worked: " << getHoursWorked() << endl;
	cout << "Overtime Hours Worked: " << getOvertimeHours() << endl;
	calculateEmployeePay();
	cout << "Gross Amount Earned: " << getAmountEarned() << endl;
	double netIncome = getAmountEarned() - (getAmountEarned() * GetTaxRateCode());
	cout << "Net Income: " << netIncome << endl;
	cout << "Intercom: "; makeNoise();
	cout << endl;
}