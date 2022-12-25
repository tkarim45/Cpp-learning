#include<iostream>
using namespace std;
bool LeapYearCheck(int year); //prototype of function LeapYearCheck
int main()
{
int year;
cout<<"enter year:"; 
cin>> year;
if(LeapYearCheck(year))
{
cout<<"It is a leap year"<<endl;
}
else
{
cout<<"It is not a leap year"<<endl;
}
return 0;
}
bool LeapYearCheck(int year) //function
{
if(year % 4 == 0 &&( year % 100 != 0 || year % 400 == 0))
{
return true;
}
return false;
}
