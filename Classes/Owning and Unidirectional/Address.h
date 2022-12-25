//Address.h
#include <iostream>
#include <string>
using namespace std;


#ifndef ADDRESS_H
#define ADDRESS_H
class Address
{
	string house_Number;
	string street_Name ;
	string city;
	string country;

public:
	// an overloaded constructor
	Address(string house_Number, string Street_Name, string City, string country);

	//overloaded insertion operator
	friend ostream& operator<<(ostream& osObject, const Address&);
};
#endif