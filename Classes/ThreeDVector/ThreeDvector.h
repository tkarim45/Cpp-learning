#include <iostream>
#include <cmath>
using namespace std; 
class ThreeDvector
// this class represnet a 3D vector, each 3D vector has three components, x, y, and z
{
	//components of vector 
	double x;
	double y;  
	double z; 
public:
	// setx such that cascased set can work  
	ThreeDvector& setx(double a);
	
	// sety such that cascased set can work
	ThreeDvector& sety(double b);
	

	// setz such that cascased set can work
	ThreeDvector& setz(double c);


	// constructor with default values of  all x, y, z  0 
	ThreeDvector();
	ThreeDvector(double a, double b, double c);

	// overloaing operator+ to add two threeDvectors
	ThreeDvector operator+(const ThreeDvector& A) const;
	

	// overloaing operator+ to do  threeDvectors+ int
	// it will add the interger in all components of vector. 
	ThreeDvector operator+(int i) const;

	// overloaing operator* to do  threeDvectors * int
	// it will multiply the interger in all components of vector. 
	ThreeDvector operator*(int i) const;
	

	// overloaing operator* to do take dot product of two vectors
    // for example if one vector is 1,2,3 and other is 4,5,6 there returned value will be  (1*2+5*2+3*6) that is, the dot product 
	double operator*(const ThreeDvector& A) const;
	

	// return true if all components of 1 vector are equal to the other
	bool operator==(const ThreeDvector& A) const;
	

	// return false  if all components of 1 vector are equal to the other
	bool operator!=(const ThreeDvector& A) const;

		// returns true of mag of calling vector is > magnitudes of other vector
		// use mag member function to get the value of ThreeDVector object magnitude.
	bool operator>(const ThreeDvector& A) const;
	

	//overloaded operator=, see the syntax is slides, give in class,  to complete the function 
	void operator=(const ThreeDvector& A);


	// return x, y, z if index 0, 1, 2 is passed as input respectively. 
	//if any other index  is passed print "index out of range" and return 0
	//hint vector[i] will be called as vector.operator[](i)
	//for example if vector is (10,2.0,3.6)  vector[0] will return 10 vector[1] will return 2.0 and vector[2] will return 3.6
	double operator[](double const i) const;


	// DONOT CHANGE FOLLOWING FUNCTIONS
	// returns sum of square of coordinates,
	double mag() const
	{
		return pow(x, 2) + pow(y, 2) + pow(z, 2);
	}
	// print the vector
	void print()
	{
		cout <<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
	}
};