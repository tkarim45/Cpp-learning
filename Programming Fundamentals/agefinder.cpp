#include<iostream>
using namespace std;
bool validate(int day, int month,int year);
bool validatecurrentdate(int bday,int bmonth,int byear,int cday, int cmonth,int cyear);
void agefinder(int bday,int bmonth,int byear,int cday, int cmonth,int cyear);
int main()
{
	int dob,mob,yob;
	int cd,cm,cy;
	char choice;
	do
	{
		do
	    {
		   cout<<"Enter   Birth ( Day, Month, Year ) ";cin>>dob>>mob>>yob;
	    }
	    while(validate(dob,mob,yob)==false);
	    do
	    {
		   cout<<"Enter Current ( Day, Month, Year ) ";cin>>cd>>cm>>cy;
	    }
	    while(validate(cd,cm,cy)==false || validatecurrentdate(dob,mob,yob,cd,cm,cy)==false);
	    agefinder(dob,mob,yob,cd,cm,cy);	    
	    cout<<"c(ontinue and (s)top "<<endl;
	    cin>>choice;
	    cout<<endl;
	}	
	while(choice=='c');
	return 0;
} 
bool validate(int day,int month,int year)
{
	if(day<=0 || day>31)
	return false;
	
	else if(month<=0 || month>12)
	return false;
	
	else if((month==4 || month==6 || month==9 || month==11) && day<31)
	return true;
	
	else if((month==1 || month==3 || month==5 || month==7 || month==8 || month==10))
	return true;
	
	else if((month==2 && month%4==0) && day<=29)
	return true;
	
	else if((month==2 && day<=28))
	return true;
	
	else 
	return false;	
}
bool validatecurrentdate(int bday,int bmonth,int byear,int cday, int cmonth,int cyear)
{
	if(cyear>byear)
	return true;
	
//	else if(cyear<byear)
//	return false;
	
//	else if(cmonth>bmonth)
//	return true;
	
//	else if(cmonth<bmonth)
//	return false;
	
//	else if(cday>=bday)
//	return true;
	
	else
	return false;
}
void agefinder(int bday,int bmonth,int byear,int cday, int cmonth,int cyear)
{
	int days=cday-bday;
	if(days<0)
	{
		cmonth--;
		if((cmonth==4 || cmonth==6 || cmonth==9 || cmonth==11))
		{
			days+=30;
		}
		else if((cmonth==1 || cmonth==3 || cmonth==5 || cmonth==7 || cmonth==8 || cmonth==10))
		{
			days+=31;
		}
        else if((cmonth==2 && cmonth%4==0))
		{
			days+=29;
		}
		else
		days+=28;				
	}
	int months=cmonth-bmonth;
	if(months<0)
	{
		cyear--;
		months+=12;
	}
	int years=cyear-byear;
	cout<<"Your age is "<<years<<" years "<<months<<" months and "<<days<<" days "<<endl;
}
