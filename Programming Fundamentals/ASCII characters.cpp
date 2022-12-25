// Program tp Print Different ASCII Characters

#include<iostream>
using namespace std;
main()
{
	int num=0;
	while(num<=256)
	{
		cout<<"Num is:"<<num<<endl;
		cout<<"Letter is: "<<char (num)<<endl; // Will print the different ASCII Characters
		cout<<endl;
		num++;
	}
}
