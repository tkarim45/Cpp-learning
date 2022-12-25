#include<iostream>
using namespace std;
int main (){
	
	int n,y,m,w,d;
	cout<<" Enter Number of Days = "<<endl;  cin>>n;
	y=n/365;
	n=n%365;
	m=n/30;
	w=n%30/7;
	d=n%24;
	cout<<"Years : "<<y<<"\nMonths : "<<m<<"\nWeek : "<<w<< "\nDays :"<<d<<endl;	
	system("pause");
	return 0;
	
}
