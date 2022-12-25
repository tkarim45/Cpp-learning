#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include"date.h"
using namespace std;

class passanger;
class driver;

#pragma once
class trip
{
	string status;
	date* Date;
	driver* Driver;
	passanger* Passanger;
	string pickup_location;
	string dropoff_location;
	float driver_rating=0;
	float passanger_rating=0;
public:
	void change_status(string);
	void rateDriver(float);
	void ratePassanger(float);
	void set_driver(driver*);
	void set_passanger(passanger*);
	void set_pickup_location(string);
	void set_dropoff_location(string);
	friend ostream& operator<<(ostream& out, const trip& );
	string getstat();
	bool looking4ride();
	bool completed();
	bool cancelled();
	bool Inprogress();
	float get_passanger_rating();
	float get_driver_rating();
	void set_passenger_currenttrip();
	void set_driver_currenttrip();
	~trip();

	friend class passanger;
	friend class driver;
};