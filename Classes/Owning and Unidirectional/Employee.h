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
	const Project* p1, *p2;
	int count;
public:
	//overloaded constructor
	Employee(string name, const  Address& A);

	//copy constructor
	Employee(const Employee& E);

	//overloaded insertion operator
	friend ostream& operator<<(ostream& osObject, const Employee& E);

	//overloaded assignment operator
	const Employee& operator=(const Employee& other);

	//Functinn or Adding Project
	void addProject(Project* p);

	//Functinn or Removing Project
	void removeProject(Project *p);

	//Destructor
	~Employee();
}; 
#endif