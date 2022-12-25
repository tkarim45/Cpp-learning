#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include"date.h"
#include"payment.h"
#include"trip.h"
#include<vector>
using namespace std;


#pragma once
class user
{
	string name;
	string email;
	string phone_number;
	date Date;
protected:
	vector <trip*> Trip;
	trip* currenttrip;
public:
	user();
	user(string, date&, string, string);
	void change_name(string);
	void change_DOB(date&);
	void change_phone_number(string);
	string get_name();
	date get_date();
	string get_email();
	string get_phone_number();
	virtual float getAvgRating();
	virtual float get_highest_rating();
	friend ostream& operator<<(ostream&, user&);
	void print();

	~user();
};
