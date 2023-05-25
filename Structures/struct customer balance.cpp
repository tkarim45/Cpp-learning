#include<stdio.h>
#include<iostream>

using namespace std;

class dummy
{
private:

	static int counter;
	int id;
	int* b; //a simple variable on heap
public:
	dummy()
	{
		++counter;
		id = counter;
		b = new int(-1);
		cout << "dummy() constructor was invoked for dummy " << id << endl << endl;
	}
	dummy(int y)
	{
		++counter;
		id = counter;
		b = new int(y);
		cout << "dummy(int y) constructor was invoked for dummy " << id << endl << endl;
	}
	dummy(const dummy& otherDummy)
	{
		++counter;
		id = counter;
		cout << "dummy(const dummy &) copy constructorwas invoked for dummy " << id << endl;
		cout << "dummy to be copied is " << otherDummy.id << endl << endl;
	}
	~dummy()
	{
		delete b;
			cout << "~dummy()  destructor was invoked for dummy " << id << endl << endl;
	}
	dummy createBiggerDummy() // returns a copy of this newdummy
	{
		cout << "createBiggerDummy() was invoked for dummy " << id << endl << endl;
		dummy biggerDummy;
		return biggerDummy;
	}
	void  print()
	{
		cout << "ID:" << id << endl << "b: " << *b << endl;
	}
};

int dummy::counter = 0;

int main()
{
	dummy* d1 = new dummy();
	dummy** d6 = new dummy * [2];
	d6[1] = new dummy(7);

}
