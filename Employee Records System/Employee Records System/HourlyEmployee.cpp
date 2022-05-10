#include <iostream>
#include "HourlyEmployee.h"

using namespace std;

void HourlyEmployee::setHourlyRate(double value) {
	while (value < 15 || value > 100) {
		cout << "Please input a valid rate between $15-$100 per hour" << endl;
		cin >> value;
	}
	hourlyPayRate = value;
	cout << "Hourly pay rate is set" << endl << endl;
}
void HourlyEmployee::setHoursWorked(double value) {
	while (value > 40) {
		cout << "Please input a valid number of hours worked. (less than 40 hours)" << endl;
		cin >> value;
	}
	hoursWorked = value;
	cout << "Hours worked is set" << endl << endl;
}
void HourlyEmployee::setAmountEarned(double additionalPay) {
	amountEarned = (getHourlyRate() * getHoursWorked()) + additionalPay;
}
double HourlyEmployee::getHourlyRate() {
	return hourlyPayRate;
}
double HourlyEmployee::getHoursWorked() {
	return hoursWorked;
}
double HourlyEmployee::getAmountEarned() {
	return amountEarned;
}
void HourlyEmployee::calculateEmployeePay(){}