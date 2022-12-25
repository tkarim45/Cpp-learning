#include "Employee.h"

//overloaded constructor
Employee::Employee(string name,const Address& A) : emp_name(name), add(A)
{
	p1 = nullptr;
	p2 = nullptr;
}

//copy constructor
Employee::Employee(const Employee& E) :emp_name(E.emp_name),add(E.add),p1(E.p1), p2(E.p2){}

//overloaded insertion operator
ostream& operator<<(ostream& osObject, const Employee& E)
{
	osObject << "\nEmpolyee Name: " << E.emp_name << endl;
	osObject << "Empolyee Address: " << E.add;
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

//Functinn or Adding Project
void Employee::addProject(Project* p)
{
	if (count < 2)
	{
		if (p1 == p || p2 == p )
		{
			cout << emp_name << " is arleady working on this project " << endl;
		}
		else
		{
			if (p1 == nullptr)
			{
				count++;
				p1 = p;
				cout << "Project was successfully added." << endl;

			}
			else if (p2 == nullptr)
			{
				count++;
				p2 = p;
				cout << "Project was successfully added." << endl;
			}
		}
	}
	else
		cout << emp_name << " is already working on 2 projects " << endl;
}

//Functinn or Removing Project
void Employee::removeProject(Project* p)
{
	if (*p == p1)
	{
		delete p1;
		p1 = nullptr;
		count--;
		cout << "Project Removed Successfully " << endl;
	}
	else if (*p == p2)
	{
		delete p2;
		p2 = nullptr;
		count--;
		cout << "Project Removed Successfully " << endl;
	}
	else
		cout << emp_name<<" is not working on any project " << endl;
}

//Destructor
Employee::~Employee()
{
	p1 = nullptr;
	p2 = nullptr;
}