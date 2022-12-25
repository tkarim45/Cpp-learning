#include "Address.h"

// an overloaded constructor
Address::Address(string house_Number, string street_Name, string city,string country)
{
	this->house_Number=house_Number;	
	this->street_Name= street_Name;
	this->city= city;
	this->country=country;
}

//overloaded insertion operator
ostream& operator<<(ostream& osObject, const Address& A)
{
	osObject<<A.house_Number<<", "<<A.street_Name<<", "<<A.city<<", "<<A.country<<"."<<endl; 
	return osObject;
}

