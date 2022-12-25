#include "Address.h"
#include "Employee.h"
#include "Project.h"

int main()
{
	Project* P1 = new Project("Database Project 1", 15000, 10);
	Project* P2 = new Project("Database Project 2", 100000, 18);

	Employee* E1 = new Employee("Sam", Address("19B", "Foggy Street", "London", "UK"));
	Employee* E2 = new Employee("Ali", Address("19B", "Foggy Street", "London", "UK"));
	Employee* E3 = new Employee("Sara", Address("19B", "Foggy Street", "London", "UK"));

	E1->addProject(P1);
	E1->addProject(P2);
	E2->addProject(P2);
	E3->addProject(P1);
	E3->addProject(P2);

	cout << *E1 << endl;
	cout << *E2 << endl;
	cout << *E3 << endl;

	cout << *P1 << endl;
	cout << *P2 << endl;

	P1->printEmployees();
	P2->printEmployees();

	E1->removeProject(P1);

	cout << *P1 << endl;
	P1->printEmployees();
}


