#include <iostream>
#include <string>
using namespace std;

#ifndef PROJECT_H
#define PROJECT_H
class Project
{
	string name;
	int budget;
	int duration; //estimate duration of project in weeks

public: 
	// an overloaded constructor
	Project(string name, int budget, int duration); 

	//copy constructor
	Project(const Project& P);

	//overloaded insertion operator
	friend ostream& operator<<(ostream& osObject, const Project& P);

	//overloaded assignment operator
	bool operator == (const Project* p);

	//overloaded assignment operator
	bool operator != (const Project* p);

	//Function to set budget
	void setBudget(int num);
}; 
#endif