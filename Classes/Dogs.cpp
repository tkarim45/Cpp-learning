
#include<iostream>
#include<cstring>
using namespace std;
class Dog
{
	string dogname;
	string dogbreed;
	string doggender;
	string dogcolour;
	string dogweight;
public:
	void setdogname(string name);
	void setdogbreed(string breed);
	void setdoggender(string gender);
	void setdogcolour(string colour);
	void setdogweight(string weight);
	void print();
};
void Dog::setdogname(string name)
{
	dogname = name;
}
void Dog::setdogbreed(string breed)
{
	dogbreed = breed;
}
void Dog::setdoggender(string gender)
{
	doggender = gender;
}
void Dog::setdogcolour(string colour)
{
	dogcolour = colour;
}
void Dog::setdogweight(string weight)
{
	dogweight = weight;
}
void Dog::print()
{
	cout << "Dog Name  : " << dogname << endl;
	cout << "Dog Breed : " << dogbreed << endl;
	cout << "Dog Gender: " << doggender << endl;
	cout << "Dog Colour: " << dogcolour << endl;
	cout << "Dog Weight: " << dogweight << endl;
}
int main()
{
	char dogname[50];
	char dogbreed[50];
	char doggender[50];
	char dogcolour[50];
	char dogweight[50];

	cout << "Enter Dog Name  : "; cin.getline(dogname, 50);
	cout << "Enter Dog Breed : "; cin.getline(dogbreed, 50);
	cout << "Enter Dog Gender: "; cin.getline(doggender, 50);
	cout << "Enter Dog Colour: "; cin.getline(dogcolour, 50);
	cout << "Enter Dog Weight: "; cin.getline(dogweight, 50);

	Dog D1;
	D1.setdogname(dogname);
	D1.setdogbreed(dogbreed);
	D1.setdoggender(doggender);
	D1.setdogcolour(dogcolour);
	D1.setdogweight(dogweight);
	D1.print();
}