#include "Employee.h"

//overloaded constructor
Employee::Employee(string name, const Address& A) : emp_name(name), add(A)
{
	p1 = nullptr;
	p2 = nullptr;
}

//copy constructor
Employee::Employee(const Employee& E) :emp_name(E.emp_name), add(E.add), p1(E.p1), p2(E.p2) {}

//overloaded insertion operator
ostream& operator<<(ostream& osObject, const Employee& E)
{
	osObject << "\nEmpolyee Name: " << E.emp_name << endl;
	osObject << "Employee Address: " << E.add;
	osObject << "Is Currently working on: " << endl;
	osObject << *E.p1;
	osObject << *E.p2;
	return osObject;
}

//overloaded assignment operator
const Employee& Employee::operator=(const Employee& other)
{
	emp_name = other.emp_name;
	add = other.add;
	p1 = other.p1;
	p2 = other.p2;
	return *this;
}

//Funtion for adding Project in employee class
void Employee::addProject(Project* p)
{
	if (count < 2)
	{
		if (p1 == p || p2 == p)
		{
			cout << emp_name << " is already working on this project " << endl;
		}
		else
		{
			if (p1 == nullptr)
			{
				count++;
				p1 = p;
				cout << "Project was added successfully in Employee. " << endl;
				p->addempolyes(this, this->emp_name);

			}
			else if (p2 == nullptr)
			{
				count++;
				p2 = p;
				cout << "Project was added successfully in Employee. " << endl;
				p->addempolyes(this, this->emp_name);
			}
		}
	}
	else
		cout << emp_name << " is already working on 2 projects " << endl;
	
}

//Funtion for Removing Project from employee class
void Employee::removeProject(Project* p)
{
	if (*p == p1)
	{
		cout << "Project Removed Successfully " << endl;
		p->removeemployee(this, this->emp_name);
		p1 = nullptr;
		count--;
	}
	else if (*p == p2)
	{
		cout << "Project Removed Successfully " << endl;
		p->removeemployee(this, this->emp_name);
		p2 = nullptr;
		count--;
	}
	else
	{
		cout << emp_name << " is not working on any project " << endl;
	}
}

//Destructor
Employee::~Employee()
{
	p1 = nullptr;
	p2 = nullptr;
}