#include "bankAccount.h"
BankAccount::BankAccount(string name, int ID, double balance) : name(name), ID(ID), balance(balance)
{
	//Overloaded Constructor
	cout << "Over-Loaded Constructor Invoked " << endl;
	total_trans = 0;     //Initialization
	tran_capacity = 10;
	transactions = new double[tran_capacity] {};
}
void BankAccount::setNickName(string n)
{
	//Change NickName
	nickName = n;
}
void BankAccount::printLastNTransactions(int n) const
{
	//Prints Last N transactions
	if (total_trans == 0)
		cout << "No transaction made yet " << endl << endl;
	else
	{
		cout << "Transactions: ";
		for (int i = total_trans-1; i >=total_trans-n; i--)
		{
			if (transactions[i] != 0 && i>=0)
			{
				cout << transactions[i] << " ";
			}
		}
		cout << endl << endl;
	}
}
void BankAccount::withDraw(double amount)
{
	//Deductus Money whenever the User Withdraws Money
	if (amount > balance)
	{
		cout << "Balance not enough to make this transaction " << endl << endl;
	}
	else
	{
		addtoTran(amount * -1);
		balance = balance - amount;
	}
}
void BankAccount::deposit(double amount)
{
	//Deposits Money whenever the User Deposits Money
	addtoTran(amount);
	balance = balance + amount;
}
double BankAccount::getBalance()const
{
	//Returns the Current Balance 
	return balance;
}
void BankAccount::print() const
{
	//Prints the Following Information
	cout << "Name: " << name << endl;
	cout << "Nickname: " << nickName << endl;
	cout << "ID: " << ID << endl;
	cout << "Balance: " << balance << endl << endl;
}
void BankAccount::growTranArray()
{
	//Doubles the size of the array Whenever the Transaction Array gets filled
	double* temp = transactions;
	tran_capacity *= 2;
	transactions = new double[tran_capacity];
	for (int i = 0; i < tran_capacity / 2 ; i++)
	{
		transactions[i] = temp[i];
	}
	delete[] temp;
}
void BankAccount::addtoTran(double amount)
{
	//Stores every Transaction in the Transaction Array
	transactions[total_trans] = amount;
	total_trans++;
	if (tran_capacity == total_trans)
	{
		growTranArray();
	}
}
void BankAccount::copy(const BankAccount& B)
{
	cout << "Copy Instructor Invoked " << endl;
	name = B.name;
	nickName = B.nickName;
	ID  = B.ID;
	balance = B.balance;
	total_trans = B.total_trans;
	tran_capacity = B.tran_capacity;
	for (int i = 0; i < total_trans; i++)
	{

		transactions[i] = B.transactions[i];

	}
}
BankAccount::~BankAccount()
{
	//Destructor
	cout << "Destructor Invoked " << endl;
	delete[] transactions;
}