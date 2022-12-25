#include <iostream>
#include <cstring>
using namespace std;



/*Gets input string from user, save in dynamic char
array and returns the pointer of array*/
char* getString(int maxlength)
{
	//TODO <Students> Complete the body of function
	char* temp = new char[maxlength];
	int size = 0;
	cin.getline(temp, maxlength);
	size = 1;
	for (int i = 0; temp[i] != '\0'; i++)
	{
		size++;
	}
	char* new_array = new char[size];
	for (int i = 0; i < size; i++)
	{
		new_array[i] = temp[i];
	}
	delete[] temp;
	temp = new_array;
	return new_array;
}
class Student
{
	char* name; // should end with '\0'
	char rollno[8]; // formate L124356   // should end with '\0'
	int age;
	double cgpa;

public:
	/*Constructor that takes name rollno, age and cgpa as input
	  and initialized the member variables*/
	Student(const char* n, const char* r, int a, double c)
	{
		// TODO <Students> complete this function, 
		//see example of how it runs in main

		//name
		int length = strlen(n) + 1;
		char* temp = new char[length];
		for (int i = 0; i < length; i++)
			temp[i] = n[i];
		name = temp;

		//roll number
		int size = strlen(r) + 1;
		for (int i = 0; i < size; i++)
			rollno[i] = r[i];

		//age
		age = a;

		//cgpa
		cgpa = c;
	}

	/* Constructor that gets values as input form user */
		Student()

	{   //get name 
		cout << "Enter Student Name (not more than 20 char): ";
		name = getString(21); 	// will run when you complete getString function	 
		//get roll no 
		cout << "Enter Roll Number, Formate CBBNNNN C is Campus BB is Batch and NNNN is Roll No: ";
		cin.getline(rollno, 8); //get age		
		cout << "Enter Age: "; cin >> age;
		//get cgpa 
		cout << "Enter cgpa: "; cin >> cgpa;
		cin.ignore();
	}
	void print()
	{
		cout << "Name:\t" << name << endl;
		cout << "Rollno:\t" << rollno << endl;
		cout << "Age:\t" << age << endl;
		cout << "cgpa:\t" << cgpa << endl;
	}
	/* Takes new name form user and sets the name member variable */
		void updateName()
	{
		delete[] name;// free the old name space 
		cout << "Enter New Name (not more than 20 char): ";
		name = getString(21);	 // will run when you complete getString function
	}
	/* Takes new name as input parameter and sets the name member variable. */
		void updateName(const char* n)
	{
		//TODO <Student> complete this function. See sample run in main
		delete[] name;
		int size = strlen(n);
		if (size < 20)
		{
			size = size + 1;
			char* temp = new char[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = n[i];
			}
			name = temp;
		}
	}
	//Take rollnumber as string from user and updates member variable rollno//
	void updateRollno(const char* r)
	{
		//TODO <Student> complete this function. See sample run in main
		for (int i = 0; i < 7; i++)
		{
			rollno[i] = r[i];
		}
	}
	//void updateRollNumv
	~Student()
	{
		cout << "~Student() called for " << name << endl;
		delete[] name;
	}
};

int main()
{
	Student s1("Ali", "L135070", 20, 3.5);
	s1.print();
	s1.updateName();
	s1.updateRollno("L12345678");// only 7 charaters should be copied
	s1.print();
	s1.updateName("Ahmed");
	s1.updateRollno("L567890");// only 7 charaters should be copied
	s1.print();
	system("pause");

	/*Output of the main is

	  Name:   Ali
	  Rollno: L135070
	  Age:    20
	  cgpa:   3.5
	  enter new name, not more than 20 char
	  Sara
	  Name:   Sara
	  Rollno: L123456
	  Age:    20
	  cgpa:   3.5
	  Name:   Ahmed
	  Rollno: L567890
	  Age:    20
	  cgpa:   3.5
	  Press any key to continue . . .*/
}