#define _CRTDBG_MAP_ALLOC
#include"date.h"
#include"user.h"
#include"payment.h"
#include"trip.h"
#include<vector>

class trip;

using namespace std;

#pragma once
class passanger :public user
{
	vector<payment*> pay;
	payment p;
public:
	passanger();
	passanger(string, date, string, string, payment);
	friend ostream& operator<<(ostream&, passanger&);
	trip* bookRide(string, string);
	void rateDriver(trip*,float);
	void cancelRide();
	void printTrips();
	float getAvgRating();
	void add_payment_method(payment*);
	void delete_payment_method(payment*);
	void print_pay_method();
	float get_highest_rating();
	~passanger();
	
	friend class trip;
};