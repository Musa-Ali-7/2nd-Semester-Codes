// Write a C++ program that simulates a banking application by 
//defining a base class Account and derived classes SavingsAccount, 
//CheckingAccount, and FixedDeposit. Each derived class should implement its 
//own method for calculating interest: calculateInterest for savings accounts at 
//a 4% interest rate, for checking accounts at a 1% interest rate, and for fixed 
//deposits at a 7% interest rate per year. Overload the calculateInterest function 
//to take objects of these different account types and return the calculated 
//interest. In the main function, create instances of each account type, display 
//their details, and calculate the interest using the overloaded functions. 
//Implement appropriate constructors and methods to handle account balance 
//and term (for fixed deposits).

#include<iostream>
using namespace std;

class Account {
	public:
		float balance;
			Account (float b) {
				balance = b;
			}
};

class SavingsAccount : public Account {
	public:
	SavingsAccount ( float b ) : Account ( b ) {} ;
	float calculateInterest(SavingsAccount& s) {
		return s.balance * 0.04;
	}
};

class CheckingAccount : public Account {
	public:
		CheckingAccount ( float b ) : Account ( b ) {} ;
	float calculateInterest(CheckingAccount& c) {
		return c.balance * 0.01;
	}
};

class FixedDeposit : public Account {
	public:
		FixedDeposit ( float b ) : Account ( b ) {
		};
	float calculateInterest(FixedDeposit& f) {
		return f.balance * 0.07;
	}
};
int main () {
	cout << "Savings Account " << endl;
	SavingsAccount s(5000);
	cout << s.calculateInterest(s) << endl;
	cout << "Checking Account " << endl;
	CheckingAccount c(6500);
	cout << c.calculateInterest(c) << endl;
	cout << "Fixed Deposit " << endl;
	FixedDeposit f(7800);
	cout << f.calculateInterest(f) << endl;
	return 0;
}
