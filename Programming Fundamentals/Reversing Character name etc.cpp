#include<iostream>
#include<cstring>
using namespace std;
void reverse(char[], int);
int main()
{
	char name[100];
	cout<<"Enter your Name "; cin>>name;
	reverse(name,strlen(name));
	cout<<"Your Reverse Name is "<<name<<endl;
}
void reverse(char character[], int size)
{
	for(int i=0; i<size/2; i++)
	{
		char temp;
		temp=character[i];
		character[i]=character[(size-i)-1];
		character[(size-i)-1]=temp;
	}
}
