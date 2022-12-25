/*Following program takes 3 integar from the user and arange them in acending and desending order.*/
#include<iostream>
using namespace std;
int main()
{
	int x,y,z;
	cout<<"Enter three integars"<<endl;
	cin>>x>>y>>z;
	cout<<"Ascending order of three integars"<<endl;
	if (x<y && y<z)
	{
        cout<<x<<endl;
		cout<<y<<endl;
		cout<<z<<endl;
		cout<<"Descending order of three integars"<<endl;
		cout<<z<<endl;
		cout<<y<<endl;
		cout<<x<<endl;
	}
	else if (y<x && x<z)
	{
		cout<<y<<endl;
		cout<<x<<endl;
		cout<<z<<endl;
		cout<<"Descending order of three integars"<<endl;
		cout<<z<<endl;
		cout<<x<<endl;
		cout<<y<<endl;	
	}
	else if (z<y && y<x)
	{
		cout<<z<<endl;
		cout<<y<<endl;
		cout<<x<<endl;
		cout<<"Descending order of three integars"<<endl;
		cout<<x<<endl;
		cout<<y<<endl;
		cout<<z<<endl;
	}
	else if (z<x && x<y)
	{
		cout<<z<<endl;
		cout<<x<<endl;
		cout<<y<<endl;
		cout<<"Descending order of three integars"<<endl;
		cout<<y<<endl;
		cout<<x<<endl;
		cout<<z<<endl;
	}
	else if (y<z && z<x)
	{
		cout<<y<<endl;
		cout<<z<<endl;
		cout<<x<<endl;
		cout<<"Descending order of three integars"<<endl;
		cout<<x<<endl;
		cout<<z<<endl;
		cout<<y<<endl;
	}
    else if (x<z && z<y)
    {
    	cout<<x<<endl;
    	cout<<z<<endl;
    	cout<<y<<endl;
		cout<<"Descending order of three integars"<<endl;
		cout<<y<<endl;
		cout<<z<<endl;
		cout<<x<<endl;	
	}
	system("pause");
	return 0;
}
