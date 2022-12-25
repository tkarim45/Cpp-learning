#include<iostream>
#include<cmath>
using namespace std;

class complexnum   //Declaring Classes 
{
	public:
		double real;
		double img;
		void print()
		{
			cout << real << " + " << img << "i" << endl;
			cout << mag() << endl;
		}
		double mag()
		{
			double mag = pow(real, 2) + pow(img, 2);
			mag = pow(mag, 0.5);
			return mag;
		}
};
int main()   //Classes Input
{
	complexnum c1;
	complexnum c2;

	c1.real = 2;
	c1.img = -10.7;
	c2.real = 7;
	c2.img = -8;
	//cout << c1.real << " + " << c1.img << "i" << endl;
	c1.print();
	c2.print();
	//cout << c1.mag() << endl;
}
	


