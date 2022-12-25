#define _CRTDBG_MAP_ALLOC
#include"user.h"

user::user() :name(""), Date(0, 0, 0), email(""), phone_number(""), currenttrip(NULL)
{

}
user::user(string name, date& Date, string email, string phone_number)
{
	this->name = name;
	this->email = email;
	this->phone_number = phone_number;
	this->Date = Date;
}
void user::change_name(string name)
{
	this->name = name;
}
void user::change_DOB(date& Date)
{
	this->Date = Date;
}
void user::change_phone_number(string phone_number)
{
	this->phone_number = phone_number;
}
string user::get_email()
{
	return email;
}
string user::get_name()
{
	return name;
}
date user::get_date()
{
	return Date;
}
string user::get_phone_number()
{
	return phone_number;
}
float user::get_highest_rating()
{
	return 0;
}
ostream& operator<<(ostream& out, user& u)
{
	out << u.name << "," << u.Date << "," << u.email << "," << u.phone_number << endl;
	return out;
}
void user::print()
{
	cout << name << endl << endl;
}
float user::getAvgRating()
{
	return 0;
}
user::~user()
{
	delete[] currenttrip;
	Trip.clear();
}
