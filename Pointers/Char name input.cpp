#include <iostream>
using namespace std;
char* getname();
int main()
{
	int no_of_students;
	cout << "Enter number of students: "; cin >> no_of_students;
	cin.ignore();
	char** student_names = new char* [no_of_students];
	for (int i = 0; i < no_of_students; i++)
		student_names[i] = getname();

	for (int i = 0; i < no_of_students; i++)
		cout << "Student " << i+1 << ": " << student_names[i] << endl;

	for (int i = 0; i < no_of_students; i++)
		delete student_names[i];

	delete[] student_names;
	student_names = nullptr;
}
char* getname()
{	
	cout << "Enter name (not more than 20 characters long):";
	const int max_length = 21; 
	char temp[max_length];
	cin.getline(temp, max_length); 
	int size = 1;
	for (int i = 0; temp[i] != '\0'; i++)
		size++;
	
	char* name = new char[size];
	
	for (int i = 0; i < size; i++)
		name[i] = temp[i];
	
	return name;
}