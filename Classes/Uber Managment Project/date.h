#include<iostream>
#include<ctime>
using namespace std;

#pragma once
class date
{
	int Date;
	int Month;
	int Year;
public:
	date();
	date(int, int, int);
	void set_date(int);
	int get_date();
	void set_month(int);
	int get_month();
	void set_year(int);
	int get_year();
	friend ostream& operator<<(ostream&, const date&);
};