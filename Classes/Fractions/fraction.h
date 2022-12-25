#include <iostream>
using namespace std;

class fraction
{
	int num;
	int den;
public:
	fraction(int num = 0, int den = 0);
	void set(int n, int d);
	void setDen(int d);
	int getDen() const ;
    int getNum() const ;
	void setNum(int d) ;
	fraction operator/(int i) const;
	friend fraction operator/(int i, const fraction & f);
	friend ostream& operator<<(ostream& osObject, const fraction& f);
	friend istream& operator>>(istream& isObject, fraction& f);
	fraction  operator++();
	fraction operator++(int u);
	void print();
	void input(fraction &f);
	friend fraction operator+(int i, const fraction & f);
	fraction operator+(int i) const;
	static fraction ones();
};