#define _CRTDBG_MAP_ALLOC
#include"passanger.h"

passanger::passanger():user(), pay(NULL)
{

}
passanger::passanger(string name, date Date, string email, string phone_number, payment p) : user(name, Date, email, phone_number), pay(NULL)
{
	this->p = p;	
}
ostream& operator<<(ostream& out, passanger& p)
{
	out << p.get_name() << endl;
	out << p.get_date() << endl;
	out << p.get_email() << endl;
	out << p.get_phone_number() << endl;
	out << "Total Trips: " << p.Trip.size() << endl;
	out << p.p;
	if (p.currenttrip==nullptr)
	{
		out << "Currently Not Riding " << endl;
	}
	else if (p.currenttrip != nullptr)
	{
		out << "Currently Riding " << endl;
	}
	return out;
}
trip* passanger::bookRide(string A, string B)
{	
	if (currenttrip == nullptr)
	{
		currenttrip = new trip;
		currenttrip->change_status("looking for driver");
		currenttrip->Date = new date;
		currenttrip->set_pickup_location(A);
		currenttrip->set_dropoff_location(B);
		currenttrip->set_passanger(this);
		Trip.push_back(currenttrip);
		Trip.size()+1;
		return currenttrip;
	}
	else
		cout << "\nCannot Ride two rides at once " << endl << endl;
		return 0;
}
void passanger::rateDriver(trip* t, float rating)
{
	if ((currenttrip == nullptr) && (t->completed()))
	{
		if (rating >= 1 && rating <= 5)
		{
			t->rateDriver(rating);
			currenttrip = nullptr;
		}
		else
			cout << "Error In Rating " << endl << endl;
	}
	else
		cout << "Error In Rating " << endl << endl;
}
void passanger::cancelRide()
{
	
	if (currenttrip != nullptr /* && (currenttrip->getstat()=="looking for driver")*/)
	{
		if (currenttrip->getstat() == "Inprogress")
		{
			currenttrip->set_driver_currenttrip();
		}
		currenttrip->change_status("Cancelled");
		currenttrip = nullptr;
		
	}
	else
		cout << "Error in cancelling ride " << endl << endl;
}
void passanger::printTrips()
{
	for (auto j = Trip.begin(); j < Trip.end(); j++)
	{
		cout<< **j << endl;
	}
}
float passanger::getAvgRating()
{
	float max=0;
	int flag = 0;
	for (int i = 0; i < Trip.capacity()-1; i++)
	{
		if (Trip[i]->passanger_rating != 0 )
		{
			max = max + Trip[i]->passanger_rating;
			flag++;
		}
	}
	return (max / flag);
}
void passanger::add_payment_method(payment* p)
{
	pay.push_back(p);
}
void passanger::delete_payment_method(payment* p)
{
	for (auto j = pay.begin(); j < pay.end(); j++)
	{
		if (*j == p)
		{
			cout << "Payment Successfully delete " << endl << endl;
			vector<payment*>::iterator new_end;
			new_end = remove(pay.begin(), pay.end(), p);
		}
	}
}
void passanger::print_pay_method()
{
	for (auto j = pay.begin(); j < pay.end(); j++)
	{
		cout << **j << endl;
	}
}
float passanger::get_highest_rating()
{
	float max = 0;
	int size = Trip.size();
	for (int i = 0; i < size; i++)
	{

		if (Trip[i]->passanger_rating > max)
			max = Trip[i]->passanger_rating;
	}
	return max;
}
passanger::~passanger()
{
	////delete[] currenttrip;
	//pay.clear();
	//Trip.clear();
}
