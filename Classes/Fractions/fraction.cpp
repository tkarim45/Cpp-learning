# include "fraction.h"

fraction::fraction(int num, int den) : num(num), den(den)
	{	}
	void fraction::set(int n, int d)
	{
		if (d != 0) { num = n; den = d; }
		else { num = 1; den = 1; }
	}
	void fraction::setDen(int d)
	{
		if (d != 0)
		{
			(*this).den = d;
		}
		else
		{
			cout << "den cannot be zero";
		}


	}
	int fraction::getDen() const { return den; }
	void fraction::setNum(int d) {
		(*this).num = d;
	}
	int fraction::getNum() const {
		return num;
	}

	fraction fraction::operator/(int i) const
	{
		fraction temp;
		temp.den = this->den*i;
		temp.num = this->num;
		return temp;
	}
	fraction operator/(int i, const fraction & f)
	{
		fraction temp;
		temp.den = f.den*i;
		temp.num = f.num;
		return temp;
	}

	ostream& operator<<(ostream& osObject, const fraction& f)
	{
   		osObject << f.num << '/' << f.den << endl;
		return osObject;
	}
	istream& operator>>(istream& isObject, fraction& f)
	{
		char temp;
		int oldnum = f.num;
		isObject >> f.num;
		isObject >> temp;
		if (temp == '/')
			isObject >> f.den;
		else
		{
			cout << "Incorrect format" << endl;
			f.num = oldnum;
		}
		return isObject;
	}

	fraction  fraction::operator++()
	{

		this->num = this->num + this->den;
		return *this;

	}
	fraction fraction::operator++(int u)
	{
		fraction temp = *this;
		this->num = this->num + this->den;
		return temp;
	}
	void fraction::print()
	{
		cout << num << "/" << den << endl;
	}
	void fraction::input(fraction &f)
	{
		char temp;
		int oldnum = f.num;
		cin >> f.num;
		cin >> temp;
		if (temp == '/')
			cin >> f.den;
		else
		{
			cout << "Incorrect format" << endl;
			f.num = oldnum;
		}
	}
	fraction operator+(int i, const fraction & f)
	{
		fraction temp;
		temp.num = f.den*i + f.num;
		temp.den = f.den;
		return temp;

	}
	fraction fraction::operator+(int i) const
	{
		fraction temp;
		temp.num = this->den*i + this->num;
		temp.den = this->den;
		return temp;
	}
	fraction fraction::ones()
	{
		fraction x(1,1);
		return x; 		
	}