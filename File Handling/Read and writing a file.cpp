#include<iostream>
#include<fstream>
#include<string>
using namespace std;
main()
{
	ifstream infile;
	infile.open("Aaa.txt");
	
	if(!infile.is_open())
	{
		cout<<"File not opened";
		exit(1);
	}
	string fruits;
	while(!infile.eof())
	{
		infile>>fruits;
		cout<<fruits<<endl;
	}
	infile.close();	
	return 0;
}
