

                                           /* Taimour Abdul Karim   
                                                  20L-1309           */
#include <iostream>
#include<vector>
#include<fstream>
#include "payment.h"
#include "driver.h"
#include "date.h"
#include "passanger.h"
#include "trip.h"
using namespace std;

const int SIZE = 20;
//an array of trips to keep pointers of all the trips of uber application
//This array will keep data of all the trips ever created. 
trip** uberTrips = new trip * [SIZE];
int n = 0;

void addToUberTrips(trip* t)// function to add new trips to uberTrips
{
	if (n < SIZE - 1 && t != nullptr)
	{
		uberTrips[n++] = t;
	}
}
void printUberTrips() //function to print uberTrips
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << *uberTrips[i] << endl;
	}
}

//vector<user*>UsersArray;
//void readfile(const char* f)
//{
//	ifstream fin;
//	fin.open(f);
//	int size = 50;
//	int Date, Month, Year;
//	string name, email, phone_number,check;
//	char* tempuser = new char[1];
//	char* tempdate = new char[50];
//	char* tempmonth = new char[50];
//	char* tempyear = new char[50];
//	char* tempname = new char[50];
//	char* tempemail = new char[50];
//	char* tempphone = new char[50];
//	if (fin.is_open())
//	{
//		while (!fin.eof())
//		{
//			fin.getline(tempuser,size,',');
//			check = tempuser;
//			fin.getline(tempname, size, ',');
//			name = tempname;
//			fin.getline(tempdate, size,'-');
//			Date = atoi(tempdate);
//			fin.getline(tempmonth, size, '-');
//			Month = atoi(tempmonth);
//			fin.getline(tempyear, size, ',');
//			Year = atoi(tempyear);
//			fin.getline(tempemail, size, ',');
//			email = tempemail;
//			fin.getline(tempphone, size, '\n');
//			phone_number = tempphone;
//			if (check == "p")
//			{
//				passanger* p1 = new passanger(name, date(Date, Month, Year), email, phone_number, payment("", ""));
//				UsersArray.push_back(p1);
//				p1 = nullptr;
//			}
//			else if (check == "d")
//			{
//				driver* d1 = new driver(name, date(Date, Month, Year), email, phone_number, "", "");
//				UsersArray.push_back(d1);
//				d1 = nullptr;
//			}
//		}
//	}
//	else
//	{
//		cout << "Error in Opening File: " << endl;
//	}
//	tempuser = nullptr;
//	tempdate = nullptr;
//	tempmonth = nullptr;
//	tempyear = nullptr;
//	tempname = nullptr;
//	tempemail = nullptr;
//	tempphone = nullptr;
//}
//void printuser()
//{
//	for (int i = 0; i < UsersArray.size(); i++)
//	{
//		cout << *UsersArray[i];
//	}
//	cout << endl;
//	for (auto i : UsersArray)
//	{
//		passanger* p = dynamic_cast<passanger*>(i);
//		if (p != nullptr)
//		{
//			cout << *p << endl;
//		}
//		driver* d = dynamic_cast<driver*>(i);
//		if (d != nullptr)
//		{
//			cout << *d << endl;
//		}
//	}
//}
//user most_Highly_Rated_User()
//{
//	float max = 0;
//	user* u = nullptr;
//	for (auto i : UsersArray)
//	{
//		if (i->get_highest_rating() > max)
//		{
//			max = i->get_highest_rating();
//			u = i;
//		}
//	}
//	if (u == nullptr)
//	{
//		exit(0);
//	}	
//	return *u;
//}
//driver* most_Highl_Rated_Driver()
//{
//	float max = 0;
//	driver* d = nullptr;
//	for (auto i : UsersArray)
//	{
//		driver* d2 = dynamic_cast<driver*>(i);
//		if (d2 != nullptr)
//		{
//			if (d2->get_highest_rating() > max)
//			{
//				max = d2->get_highest_rating();
//				d = d2;
//			}
//		}
//	}
//	if (d == nullptr)
//	{
//		exit(0);
//	}
//	return d;
//}
//passanger* most_Highly_Rated_Passenger()
//{
//	float max = 0;
//	passanger* p = nullptr;
//	for (auto i : UsersArray)
//	{
//		passanger* p1 = dynamic_cast<passanger*>(i);
//		if (p1 != nullptr)
//		{
//			if (p1->get_highest_rating() > max)
//			{
//				max = p1->get_highest_rating();
//				p = p1;
//			}
//		}
//	}
//	if (p == nullptr)
//	{
//		exit(0);
//	}
//	return p;
//}
int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	passanger* p1 = new passanger("P1", date(10, 10, 1990), "ali@yahoo.com", "0334564334", payment("111-222-333-333", "card"));
	driver* d1 = new driver("D1", date(16, 1, 1990), "ayesha@yahoo.com", "0357757585", "Lin1197717", "VIN9817917");

	//////Test Case 1, user books, driver picks, driver ends (rating can be given only in this case)
	cout << *p1 << endl;
	cout << *d1 << endl;

	addToUberTrips(p1->bookRide("A", "B"));// will create a new trip and add it to uberTrips array
	cout << *uberTrips[n - 1];// will print this trip

	addToUberTrips(p1->bookRide("C", "D"));//prints error as p1 has already booked a ride

	d1->pickARide(uberTrips[n - 1]); //will assign  d1 to uberTrip[0], the status of this ride will also change to InProgress

	d1->ratePassanger(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete

	cout << *p1 << endl;
	cout << *d1 << endl;

	d1->endARide(); //will change the status of uberTrip[0] to Complete

	d1->ratePassanger(uberTrips[n - 1], 5); // no error as the trip is not complete
	p1->rateDriver(uberTrips[n - 1], 4); // no error as the trip is not complete
	cout << *uberTrips[n - 1] << endl;
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->pickARide(uberTrips[n - 1]);//prints error as the ride is completed
	cout << "-------------------------------------" << endl << endl;

	////////////Test case 2: User books, driver picks, user cancels, ratings are not applicable to cancelled ride
	//addToUberTrips(p1->bookRide("C", "D"));
	//d1->pickARide(uberTrips[n - 1]);
	//cout << *p1 << endl;
	//cout << *d1 << endl;
	//p1->cancelRide(); //Since passenger is in progress cannot end ride
	//p1->cancelRide();//error as there is no current ride
	//cout << *p1 << endl;
	//cout << *d1 << endl;
	//d1->ratePassanger(uberTrips[n - 1], 5); //error as the ride was not complete
	//p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	//cout << "-------------------------------------" << endl << endl;

	////////////Test Case 3: User Books, user Cancels, driver cannot pick this ride now, ratings are not applicable to this ride
	//addToUberTrips(p1->bookRide("D", "E"));
	//p1->cancelRide();
	//d1->pickARide(uberTrips[n - 1]); //error as this ride is not looking for driver
	//d1->ratePassanger(uberTrips[n - 1], 5); //error as the ride was not complete
	//p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	//cout << "-------------------------------------" << endl<<endl;

	////////////Test Case 4: getting avg ratings adn print trip funnction
	//////////Adding some more test data
	//addToUberTrips(p1->bookRide("X", "Y"));
	//d1->pickARide(uberTrips[n - 1]);
	//d1->endARide();
	//d1->ratePassanger(uberTrips[n - 1], 3);
	//p1->rateDriver(uberTrips[n - 1], 5);

	//addToUberTrips(p1->bookRide("X", "Y"));
	//d1->pickARide(uberTrips[n - 1]);
	//d1->endARide();
	//d1->ratePassanger(uberTrips[n - 1], 6);//error as the rating is not between 1 and 5 
	//d1->ratePassanger(uberTrips[n - 1], 4);
	//d1->ratePassanger(uberTrips[n - 1], 3);// will upate the passanging rating from 4 to 3
	//p1->rateDriver(uberTrips[n - 1], 1);

	//p1->printTrips();
	//d1->printTrips();
	//cout << p1->getAvgRating() << endl;
	//cout << d1->getAvgRating() << endl;

	//cout << "-------------------------------------" << endl << endl;

	//payment* pay1 = new payment("111-222-333-333", "card");
	//payment* pay2 = new payment(2500, "cash");
	//p1->add_payment_method(pay1);
	//p1->add_payment_method(pay2);
	//p1->print_pay_method();
	//p1->delete_payment_method(pay1);
	//p1->print_pay_method();


	delete d1;
	delete p1;

	/*for (int i = 0; i < SIZE; i++)
	{
		delete uberTrips[i];
	}
	delete[] uberTrips;*/

	cout << "-------------------------------------" << endl << endl;

	//const char* file = "D://Visual Studio//Visual Studio//Programs//Classes//Project//user.txt";

	//readfile(file);
	//printuser();

	//passanger* shahmeer = dynamic_cast<passanger*>(UsersArray[0]);
	//passanger* ibrahim = dynamic_cast<passanger*>(UsersArray[2]);
	//passanger* mustafa = dynamic_cast<passanger*>(UsersArray[3]);
	//passanger* sana = dynamic_cast<passanger*>(UsersArray[5]);

	//driver* meher = dynamic_cast<driver*>(UsersArray[1]);
	//driver* ali = dynamic_cast<driver*>(UsersArray[4]);
	//driver* noor = dynamic_cast<driver*>(UsersArray[6]);

	//trip* Trip = shahmeer->bookRide("A", "B");
	//meher->pickARide(Trip);
	//meher->endARide();
	//shahmeer->rateDriver(Trip, 5);
	//meher->ratePassanger(Trip, 2);

	//Trip = ibrahim->bookRide("C", "D");
	//meher->pickARide(Trip);
	//meher->endARide();
	//ibrahim->rateDriver(Trip, 4);
	//meher->ratePassanger(Trip, 3);

	//Trip = sana->bookRide("E", "F");
	//meher->pickARide(Trip);
	//meher->endARide();
	//sana->rateDriver(Trip, 5);
	//meher->ratePassanger(Trip, 4);

	////printuser();

	//cout << "-------------------------------------" << endl << endl;

	//user User = most_Highly_Rated_User();
	//User.print();

	//cout << "-------------------------------------" << endl << endl;

	//passanger* MHRP = most_Highly_Rated_Passenger();
	//cout << *MHRP << endl << endl;

	//cout << "-------------------------------------" << endl << endl;

	//driver* MHRD = most_Highl_Rated_Driver();
	//cout << *MHRD << endl << endl;


}