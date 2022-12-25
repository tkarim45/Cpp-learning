#include "Project.h"
#include "Employee.h"

// an overloaded constructor
Project::Project(string name, int budget, int duration) : name(name), budget(budget), duration(duration){}

//copy constructor
Project::Project(const Project& P)
{
	name = P.name;
	budget = P.budget;
	duration = P.duration;
}

//overloaded insertion operator
ostream& operator<<(ostream& osObject, const Project& P)
{
	if (&P)
	{
		osObject << "Project Name: " << P.name << ", " << "Budget: " << P.budget << ", " << "Duration: " << P.duration << " Weeks" << endl;
		osObject << "No of emp: " << P.empno << endl;
		return osObject;
	}
}


//oerloaded equal equal operator
bool Project::operator == (const Project* p)
{
	if (this == p)
	{
		return true;
	}
	else if ((name == p->name && budget == p->budget) && duration == p->duration)
	{
		return true;
	}
	return false;
}

//oerloaded not equal operator
bool Project::operator != (const Project* p)
{
	if (this != p)
	{
		return true;
	}
	else if ((name != p->name && budget != p->budget) && duration != p->duration)
	{
		return true;
	}
	return false;
}

//Funtion for adding employees in project
void Project::addempolyes(Employee* E, string empname)
{
	string* nametemp = new string[empno + 1];
	Employee** temp = new Employee* [empno + 1];
	for (int i = 0; i < empno; i++)
	{
		temp[i] = emp[i];
		nametemp[i] = empnames[i];
	}

	temp[empno] = E;
	nametemp[empno] = empname;

	if (temp && nametemp)
	{
		delete[] emp;
		delete[] empnames;
	}
	emp = temp;
	empnames = nametemp;
	empno++;
	cout << "Employee added to project. " << endl;
}

//Funtion for removing employees from project
void Project::removeemployee(Employee* E, string name)
{
	for (int i = 0; i < empno; i++)
	{
		if (emp[i] == E)
		{
			for (int j = i; j < empno-1; j++)
			{
				emp[j] = emp[j + 1];
			}
			
			Employee** temp = new Employee * [empno - 1];
			for (int f = 0; f < empno - 1; f++)
			{
				temp[f] = emp[f];
			}
			if (temp)
			{
				delete[] emp;
			}
			emp = temp;
		}
	}
	for (int i = 0; i < empno; i++)
	{
		if (empnames[i] == name)
		{
			for (int j = i; j < empno-1; j++)
			{
				empnames[j] = empnames[j + 1];
			}
			string* nametemp = new string[empno - 1];
			for (int f = 0; f < empno-1; f++)
			{
				nametemp[f] = empnames[f];
			}
			if (nametemp)
			{
				delete[] empnames;
			}
			empnames = nametemp;
		}
	}
	empno--;
	cout << "Employee Removed from project. " << endl;
}

//Function for printing employeed names
void Project::printEmployees()
{
	for (int i = 0; i < empno; i++)
	{
		cout << empnames[i] << endl;
	}
	cout << endl;
}


//Funtion for setting the budget
void Project::setBudget(int num)
{
	budget = num;
}