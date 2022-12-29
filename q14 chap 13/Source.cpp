//Programmer Name:Muhammad Danyal
//Reg no: 4304/bsse/f21/b

//Q14 a.Define the class bankAccount to store a bank customer’s account
//numberand balance.Suppose that account number is of type int, and
//balance is of type double.Your class should, at least, provide the
//following operations : set the account number, retrieve the account
//number, retrieve the balance, deposit and withdraw money, and print
//account information.Add appropriate constructors.
//b.Every bank offers a checking account.Derive the class
//checkingAccount from the class bankAccount(designed in
//	part(a)).This class inherits members to store the account number
//	and the balance from the base class.A customer with a checking
//	account typically receives interest, maintains a minimum balance,
//	and pays service charges if the balance falls below the minimum
//	balance.Add member variables to store this additional information.
//	In addition to the operations inherited from the base class, this class
//	should provide the following operations : set interest rate, retrieve
//	interest rate, set minimum balance, retrieve minimum balance, set
//	service charges, retrieve service charges, post interest, verify if the
//	balance is less than the minimum balance, write a check, withdraw
//	(override the method of the base class), and print account information.Add appropriate constructors.
//	c.Every bank offers a savings account.Derive the class
//	savingsAccount from the class bankAccount(designed in part
//	(a)).This class inherits members to store the account numberand
//	the balance from the base class.A customer with a savings account
//	typically receives interest, makes deposits, and withdraws money.In
//	addition to the operations inherited from the base class, this class
//	should provide the following operations : set interest rate, retrieve
//	interest rate, post interest, withdraw(override the method of the
//		base class), and print account information.Add appropriate constructors.
//	d.Write a program to test your classes designed in parts(b) and (c).
#include<iostream>
#include<string>

using namespace std;
class bankaccount {
protected:
	int accNo;
	double balance;
	float depositamm;
	float withdrawamm;
public:
	bankaccount(int acc=0,double bal=0,float dep=0.0,float with=0.0):accNo(acc),balance(bal),depositamm(dep),withdrawamm(with) {}
	void set();
	void get();
	void deposit();
	void withdraw();
};
void bankaccount::set() {
	cout << "Enter account Number:";
	cin >> accNo;
	cout << "Set balance:";
	cin >> balance;
	cout << "Account No: " << accNo << endl;
	cout << "Balance: " << balance << endl;
}
void bankaccount::deposit() {
	cout << "current balance:" << balance<<endl;
	cout << "Enter deposit amount:";
	cin>> depositamm;
	balance = balance + depositamm;
	cout << "Balance=" << balance<<endl;
}
void bankaccount::withdraw() {
	cout << "current balance:" << balance << endl;
	cout << "Enter Withdraw amount:";
	cin >> withdrawamm;
	if (withdrawamm < balance) {
		balance = balance - withdrawamm;
		cout << "Balance= " << balance << endl;
	}
	else
		cout << "unsufficient amount" << endl;
}
void bankaccount::get() {
	cout << "Account No: " << accNo << endl;
	cout << "Balance: " << balance << endl;	
}
class checkingaccount : public bankaccount {
	double interest;
	float scharges;
	float withdrawamm;
	float minbalance;
public:
	checkingaccount(double inter=0,float sc=0.0,float w=0,float min=0, int acc = 0, double bal = 0, float dep = 0.0, float with = 0.0):bankaccount(acc,bal,dep,with),interest(inter),scharges(sc),withdrawamm(w),minbalance(min){}
	void get();
	void setinterest();
	void setminbal();
	void setscharges();
	void verify();
	void retrive();	
};
void checkingaccount::get() {
	bankaccount::get();
}
void checkingaccount::setinterest() {
	get();
	cout << "Set interest rate:";
	cin >> interest;
	interest = (interest/ 100) * balance;
	balance = balance + interest;
	cout << "Balance:" << balance;
}
void checkingaccount::setminbal() {
	cout << "Set minimum balance:";
	cin >> minbalance;
}
void checkingaccount::setscharges() {
	get();
	cout << minbalance;
	cout << "set service charges:";
	cin >> scharges;
	if (balance <= minbalance) {
		balance=balance - scharges;
		cout << "remaining balance:" << balance<<endl;
	}
}
void checkingaccount::verify() {
	get();
	cout << minbalance;
	if (balance <= minbalance) {
		cout << "unsufficent balance in account.\n";
	}
	else
		cout << "Your account have enough balance.\n";
}
void checkingaccount::retrive() {
	get();
	cout << "Interest rate: " << interest << endl;
	cout << "minimum balance: " << minbalance << endl;
	cout << "Service charges: " << scharges << endl;
	cout << "verifing for minimum balance:";
	verify();
}
class savingaccount :public bankaccount{
public:
	checkingaccount c;
	void setter();
	void getter();
};
void savingaccount::setter() {
	bankaccount::set();
	bankaccount::deposit();
	bankaccount::withdraw();
	c.setinterest();
	c.setminbal();
	c.setscharges();
}
void savingaccount::getter() {
	c.retrive();	
}
int main() {
	int choice;	
	checkingaccount c;
	savingaccount s;
	while (true) {
		cout << "________________MAIN MENU_______________" << endl;
		cout << " 1.Set information" << endl;
		cout << " 2.Deposit Amount" << endl;
		cout << " 3.Withdraw Amount" << endl;
		cout << " 4.Retrive information" << endl;
		cout << " 5.Exit" << endl;
		cout << "What you want to do? \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "--------------Set Data--------------\n";			
			s.setter();
			break;
		case 2:
			system("cls");
			cout << "--------------Deposit Amount--------------\n";
			c.deposit();
			break;
		case 3:
			system("cls");
			cout << "--------------Withdrawal Amount--------------\n";
			c.withdraw();
			break;
		case 4:
			system("cls");
			cout << "--------------Retrive Amount--------------\n";
			s.getter();
			break;
		case 5:
			exit(0);
		default:
			cout << "Enter a valid input.\n";
			break;
		}
	}
}
