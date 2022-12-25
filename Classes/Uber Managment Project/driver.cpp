#define _CRTDBG_MAP_ALLOC
#include"driver.h"

driver::driver():user(),vehicle_identification_number(""),driving_license_number("")
{

}
driver::driver(string name, date Date, string email, string phone_number, string driving_license_number, string vehicle_identification_number): user(name, Date,email,phone_number)
{
	this->driving_license_number = driving_license_number;
	this->vehicle_identification_number = vehicle_identification_number;
}
ostream& operator<<(ostream& out, driver& d)
{
	out << d.get_name() << endl;
	out << d.get_date() << endl;
	out << d.get_email() << endl;
	out << d.get_phone_number() << endl;
	out << "Total Trips: " << d.Trip.size() << endl;
	if (d.currenttrip == nullptr)
	{
		out << "Currently Not Driving " << endl;
	}
	else if (d.currenttrip != nullptr && d.currenttrip->Inprogress())
	{
		out << "Currently Driving " << endl;
	}
	else
		out << "Currently Not Driving " << endl;
	out << d.driving_license_number << endl;
	out << d.vehicle_identification_number << endl;
	return out;
}
void driver::ratePassanger(trip* t, float rating)
{
	if ((currenttrip == nullptr) && (t->completed()))
	{
		if (rating >= 1 && rating <= 5)
		{
			t->ratePassanger(rating);
		}
		else
			cout << "Error In Rating " << endl << endl;
	}
	else
		cout << "Error In Rating " << endl << endl;
}
void driver::endARide()
{
	if (currenttrip != nullptr)
	{
		currenttrip->set_passenger_currenttrip();
		currenttrip->change_status("Complete");
		currenttrip = nullptr;
	}
}
void driver::pickARide(trip* tt)
{
	if (tt->looking4ride())
	{
		currenttrip = tt;
		currenttrip->change_status("InProgress");
		currenttrip->set_driver(this);
		Trip.size() + 1;
		Trip.push_back(currenttrip);
	}
	else
		cout << "This ride is not looking for a driver " << endl << endl;
}

void driver::printTrips()
{
	for (auto j = Trip.begin(); j < Trip.end(); j++)
	{
		cout << **j << endl;
	}
}
float driver::getAvgRating()
{
	float max = 0;
	int flag = 0;
	for (int i = 0; i < Trip.capacity(); i++)
	{
		if (Trip[i]->driver_rating != 0)
		{
			max = max + Trip[i]->driver_rating;
			flag++;
		}
	}
	return (max / flag);
}
float driver::get_highest_rating()
{
	float max = 0;
	int size = Trip.size();
	for (int i = 0; i < size; i++)
	{
		if (Trip[i]->passanger_rating > max)
		{
			max = Trip[i]->passanger_rating;
		}		
	}
	return max;
}
driver::~driver()
{
	delete[] currenttrip;
	Trip.clear();
}