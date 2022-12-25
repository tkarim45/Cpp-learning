#include <iostream>
#include <string>
using namespace std;

class Employee;

#ifndef PROJECT_H
#define PROJECT_H
class Project
{
	string name;
	int budget;
	int duration; 
	string* empnames; // Array for storing names
	Employee** emp;  //Array for storing employees
	void addempolyes(Employee* E, string name);   //Funtion for adding employees in project
	void removeemployee(Employee* E, string name);  //Funtion for removing employees from project
	int empno=0;

public: 
	// an overloaded constructor
	Project(string name, int budget, int duration);

	//copy constructor
	Project(const Project&);

	//overloaded insertion operator
	friend ostream& operator<<(ostream& osObject, const Project&);

	//oerloaded equal equal operator
	bool operator == (const Project* p);

	//oerloaded not equal operator
	bool operator != (const Project* p);

	//Function for printing employeed names
	void printEmployees();

	//Funtion for setting the budget
	void setBudget(int); 

	//Project can access employee class
	friend class Employee;
}; 
#endif