#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
using namespace std;
void Createfile()
{
	std::fstream fil;
	fil.open ("Student.txt",ios::app);
	char ch,S[100];
	cout<<"Enter line";
	cin.getline(S,sizeof(S));
	fil<<S<<endl;
}
void Displayfile()
{
	fstream fil;
	fil.open("Student.txt",ios::in);
	char S[100];
	while(!fil.eof())
	{      fil.getline(S,100);
		cout<<S<<endl;
	}
}
void Reversefile()
{
	fstream fil;
	fil.open("Student.txt",ios::in);
	char W[100];
	while(!fil.eof())
	{ 
	  fil.getline(W,100);
		for (int i=strlen(W)-1;i>=0;i--)
		    cout<<W[i];
		    cout<<"\n";
	}
}
int main()
{	
    Createfile();
    Displayfile();
    Reversefile();
    return 0;
}
