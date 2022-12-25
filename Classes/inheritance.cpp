#include<iostream>
using namespace std;
class person
{
	string first_name;
	string last_name;
protected:
	int age;
public:
	person();
	person(string, string, int);
	void set_first_name(string);
	string get_first_name();
	void set_last_name(string);
	string get_last_name();
	void print();
	~person();
};
class student : public person
{
	float cgpa;
public:
	student();
	student(string, string, int, float);
	void set_cgpa(float);
	int get_cgpa();
	void print();
	~student();
};
class faculty : public person
{
	int course_count;
	int ext_digit;
public:
	faculty();
	faculty(string, string, int, int, int);
	void print();
	~faculty();
};
class graduate : public student
{
	string thesis;
public:
	graduate();
	graduate(string, string, int, float, string);
	void print();
	~graduate();
};
class undergraduate : public student
{
	string fyp_name;
public:
	undergraduate();
	undergraduate(string, string, int, float, string);
	void print();
	~undergraduate();
};
person::person():first_name(""),last_name(""),age(0)
{
	cout << "Person Default Constructor Called " << endl;
}
person::person(string fname, string lname, int age)
{
	cout << "Person Overloaded Constructor Called " << endl;
	first_name = fname;
	last_name = lname;
	this->age = age;
}
void person::set_first_name(string n)
{
	first_name = n;
}
string person::get_first_name()
{
	return first_name;
}
void person::set_last_name(string n)
{
	last_name = n;
}
string person::get_last_name()
{
	return last_name;
}
void person::print()
{
	cout << "Name: " << first_name << " " << last_name << endl;
	cout << "Age: " << age << endl;
}
person::~person()
{
	cout << "~Prson() Called " << endl;
}
student::student():cgpa(0),person("", "", 0)
{
	cout << "Student Default Constructor Called " << endl;
}
student::student(string fname, string lname, int age, float cgpa): person(fname, lname, age)
{
	cout << "Student Overloaded Constructor Called " << endl;
	this->cgpa = cgpa;
}
void student::print()
{
	person::print();
	cout << "CGPA: " << cgpa << endl;
}
void student::set_cgpa(float n)
{
	cgpa = n;
}
int student::get_cgpa()
{
	return cgpa;
}
student::~student()
{
	cout << "~Student() Called " << endl;
}
faculty::faculty():course_count(0), ext_digit(0), person("","",0)
{
	cout << "Faculty Default Constructor Called " << endl;
}
faculty::faculty(string fname, string lname, int age, int course_count, int ext_digit):person(fname, lname, age)
{
	cout << "Faculty Overloaded Constructor Called " << endl;
	this->course_count = course_count;
	this->ext_digit = ext_digit;
}
void faculty::print()
{
	person::print();
	cout << "Course Count: " << course_count << endl;
	cout << "Telephone Extension: " << ext_digit << endl;
}
faculty::~faculty()
{
	cout << "~Faculty() Called " << endl;
}
graduate::graduate():thesis(""),student("","",0,0)
{
	cout << "Gradaute Default Constructor Called " << endl;
}
graduate::graduate(string fname, string lname, int age, float cgpa, string thesis) :student(fname, lname, age, cgpa)
{
	cout << "Graduate Overloaded Constructor Called " << endl;
	this->thesis = thesis;
}
void graduate::print()
{
	student::print();
	cout << "Thesis Topic: " << thesis << endl;
}
graduate::~graduate()
{
	cout << "~Graduate() Called " << endl;
}
undergraduate::undergraduate():fyp_name(""),student("","",0, 0)
{
	cout << "Undergraduate Default Constructor Called " << endl;
}
undergraduate::undergraduate(string fname, string lname, int age, float cgpa, string fyp_name):student(fname, lname, age, cgpa)
{
	cout << "Undergraduate Overloaded Constructor Called " << endl;
	this->fyp_name = fyp_name;
}
void undergraduate::print()
{
	student::print();
	cout << "Final year project: " << fyp_name << endl;
}
undergraduate::~undergraduate()
{
	cout << "~Undergrauate() Called " << endl;
}

int main()
{
	student s("Ted", "Thompson", 22, 3.91);
	faculty f("Richard", "Karp", 45, 2, 420);	
	undergraduate u("Ted", "Thompson", 22, 3.91, "The Event Locator");
	graduate      g("Arnold", "Gates", 25, 3.01, "Distributed Algorithms");
	s.print();
	f.print();
	u.print();
	g.print();
}