
#define _CRTDBG_MAP_ALLOC
#include"trip.h"
#include"passanger.h"
#include"driver.h"
void trip::change_status(string status)
{
	this->status = status;
}
void trip::rateDriver(float n)
{
	driver_rating = n;
}
void trip::ratePassanger(float n)
{
	passanger_rating = n;
}

void trip::set_driver(driver* D)
{
	Driver = D;
}
void trip::set_passanger(passanger* P)
{
	Passanger = P;
}
void trip::set_pickup_location(string pick)
{
	pickup_location = pick;
}
void trip::set_dropoff_location(string drop)
{
	dropoff_location = drop;
}
ostream& operator<<(ostream& out, const trip& t)
{
	
	out << "Status: " <<t.status << endl;
	out << "Date: " << *t.Date << endl;
	out << "Pick Up Location: " <<t.pickup_location << endl;
	out << "Drop Off Location: " <<t.dropoff_location << endl;
	out << "Passanger Name: " << t.Passanger->get_name() << endl;
	if (t.status == "Complete")
	{
		out << "Driver Name: " << t.Driver->get_name() << endl;
		out << "Passanger Rating: " << t.passanger_rating << endl;
		out << "Driver Rating: " << t.driver_rating << endl << endl;
	}
	else if (t.status=="Cancelled")
	{
		out << "Driver Name: " << t.Driver << endl;
	}
	
	return out;
}
string trip::getstat()
{
	return status;
}
bool trip::looking4ride()
{
	if (this->status == "looking for driver")
	{
		return true;
	}
	else
		return false;
}
bool trip::completed()
{
	if (this->status == "Complete")
	{
		return true;
	}
	else
		return false;
}
bool trip::cancelled()
{
	if (this->status == "Cancelled")
	{
		return true;
	}
	else
		return false;
}
bool trip::Inprogress()
{
	if (this->status == "InProgress")
	{
		return true;
	}
	else
		return false;
}
float trip::get_passanger_rating()
{
	return passanger_rating;
}
float trip::get_driver_rating()
{
	return driver_rating;
}
void trip::set_passenger_currenttrip()
{
	if (Passanger != nullptr && Passanger->currenttrip!=nullptr)
	{
		Passanger->currenttrip = nullptr;
	}
}
void trip::set_driver_currenttrip()
{
	if (Passanger != nullptr && Passanger->currenttrip != nullptr)
	{
		Driver->currenttrip = nullptr;
	}
	
}
trip::~trip()
{
	delete[] Date;
	delete[] Passanger;
	delete[] Driver;
}
