#include "ThreeDvector.h";
#include <iostream>
using namespace std;
ThreeDvector& ThreeDvector::setx(double a)
{
	x = a;
	return *this;
}
ThreeDvector& ThreeDvector::sety(double b)
{
	y = b;
	return *this;
}
ThreeDvector& ThreeDvector::setz(double c)
{
	z = c;
	return *this;
}
ThreeDvector::ThreeDvector()
{
	x = 0;
	y = 0;
	z = 0;
}
ThreeDvector::ThreeDvector(double a, double b, double c): x(a), y(b), z(c) 
{
}
ThreeDvector ThreeDvector::operator+(const ThreeDvector& A) const
{
	ThreeDvector temp;
	temp.x = this->x + A.x;
	temp.y = this->y + A.y;
	temp.z = this->z + A.z;
	return temp;
}
ThreeDvector ThreeDvector::operator+(int i) const
{
	ThreeDvector temp;
	temp.x = this->x + i;
	temp.y = this->y + i;
	temp.z = this->z + i;
	return temp;
}
ThreeDvector ThreeDvector::operator*(int x) const
{
	ThreeDvector temp;
	temp.x = this->x * x;
	temp.y = this->y * x;
	temp.z = this->z * x;
	return temp;
}
double ThreeDvector::operator*(const ThreeDvector& A) const
{
	double temp = 0;
	temp = (this->x * A.x) + (this->y * A.y) + (this->z * A.z);
	return temp;
}
bool ThreeDvector::operator==(const ThreeDvector& A) const
{
	if ((this->x == A.x) && (this->y == A.y) && (this->z == A.z))
		return true;
	else
		return false;
}
bool ThreeDvector::operator!=(const ThreeDvector& A) const
{
	if ((this->x != A.x) && (this->y != A.y) && (this->z != A.z))
		return true;
	return false;
}
bool ThreeDvector::operator>(const ThreeDvector& A) const
{
	if (mag() > A.mag())
		return true;
	return false;
}
void ThreeDvector::operator=(const ThreeDvector& A)
{
	this->x = A.x;
	this->y = A.y;
	this->z = A.z;
}
double ThreeDvector::operator[](double const x) const
{
	if (x == 0)
		return x;
	else if (x == 1)
		return y;
	else if (x == 2)
		return z;
	else
		cout << "Index out of range." << endl;
	return 0;
}
