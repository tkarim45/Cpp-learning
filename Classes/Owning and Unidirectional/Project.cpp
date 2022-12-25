#include "Project.h"

// an overloaded constructor
Project::Project(string name, int budget, int duration) : name(name), budget(budget), duration(duration) {}

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
		return osObject;
	}
}

//overloaded assignment operator
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

//overloaded assignment operator
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

//Function to set budget
void Project::setBudget(int num)
{
	budget = num;
}