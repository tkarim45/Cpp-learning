#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include"user.h"
#include"date.h"
#include"trip.h"
#include<vector>

class trip;

using namespace std;

#pragma once
class driver :public user
{
	string driving_license_number;
	string vehicle_identification_number;
public:
	driver();
	driver(string, date DOB, string, string, string,string);
	friend ostream& operator<<(ostream&, driver&);
	void ratePassanger(trip*, float);
	void endARide();
	void pickARide(trip*);
	void printTrips();
	float getAvgRating();
	float get_highest_rating();
	~driver();

	friend class trip;
};
