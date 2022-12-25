#include<iostream>
using namespace std;
//Task 1
class rectangle
{
private:
	int length;
	int width;
	int area;
public:
	int get_length();
	void set_length(int L);
	int get_width();
	void set_width(int W);
	void set_area();
	bool is_square();
	void set_values();
	void print();
};
int rectangle::get_length()
{
	return length;
}
int rectangle::get_width()
{
	return width;
}
void rectangle::set_length(int length1)
{
	if (length1 <= 0)
	{
		cout << "Length Should be Greater than Zero: " << endl;
	}
	else
		length = length1;
}
void rectangle::set_width(int Width1)
{
	if (Width1 <= 0)
	{
		cout << "Width Should be Greater than Zero: " << endl;
	}
	else
		width = Width1;
}
void rectangle::set_area()
{
	int area1;
	area1 = length * width;
	area = area1;
}
void rectangle::set_values()
{
	int length1, width1;
	cout << "Enter length: ";  cin >> length1;
	cout << "Enter width: ";  cin >> width1;
	set_length(length1);
	set_width(width1);
}
bool rectangle::is_square()
{
	if (length == width)
		return true;
	else
		return false;
}
void rectangle::print()
{
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
}





//Task 2 
class Cuboid
{
private:
	int length;
	int width;
	int height;

public:
	void set_length(int L);
	void set_width(int W);
	void set_height(int H);
	int get_L();
	int get_H();
	int get_W();
	int volume();
	void print();
	void area();
	bool is_cube();
};
void Cuboid::set_length(int L)
{
	if (L >= 0)
	{
		length = L;
	}
	else
		cout << "Length Should be greater than 0 " << endl;
}
void Cuboid::set_width(int W)
{
	if (W >= 0)
	{
		width = W;
	}
	else
		cout << "\Width Should be greater than than 0" << endl;
}
void Cuboid::set_height(int H)
{
	if (H >= 0)
	{
		height = H;
	}
	else
		cout << "Heigth Should be greater than than 0 " << endl;
}
int Cuboid::get_L()
{
	return length;
}
int Cuboid::get_H()
{
	return height;
}
int Cuboid::get_W()
{
	return width;
}
int Cuboid::volume()
{
	int C_volume = length * width * height;
	return C_volume;
}
void Cuboid::area()
{
	int area;
	area = 2 * ((length * width) + (width * height) + (height * length));
}
void Cuboid::print()
{
	int volume = Cuboid::volume();
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout<< "Height: " << height << endl;
	cout << "Volume: " << volume << endl;
}
bool Cuboid::is_cube()
{
	bool check;
	if (length == width && width == height && length == height)
	{
		check = true;
	}
	else
	{
		check = false;
	}
	return check;
}




//Task 3 
int main()
{
	rectangle R1;
	R1.set_values();
	bool flag = R1.is_square();
	if (flag)
	{
		cout << "Square" << endl;
	}
	else
		cout << "Not Square" << endl;
	R1.print();

	Cuboid C1;
	int h, w, l;
	cout << "Enter Heigth: "; cin >> h;
	cout << "Enter width: "; cin >> w;
	cout << "Enter length: "; cin >> l;
	C1.set_height(h);
	C1.set_length(l);
	C1.set_width(w);
	bool flag1 = C1.is_cube();
	if (flag)
	{
		cout << "Cuboid" << endl;
	}
	else
		cout << "Not Cuboid" << endl;
	C1.print();
}