#include <iostream>
#include <string>
#include "Address.h"
#include "Project.h"

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee
{
	string emp_name; 
	Address add;
	Project* p1, * p2;
	int count = 0;
	
public:
	//overloaded constructor
	Employee(string, const Address&);

	//copy constructor
	Employee(const Employee&);

	//overloaded insertion operator
	friend ostream& operator<<(ostream& osObject, const Employee&);

	//overloaded assignment operator
	const Employee & operator=(const Employee& other);

	//Funtion for adding Project in employee class
	void addProject(Project* P);

	//Funtion for Removing Project from employee class
	void removeProject(Project *P);  

	//Destructor
	~Employee();
}; 
#endif