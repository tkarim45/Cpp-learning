#include<iostream>
using namespace std;
struct date
{
 int date;
 int month;
 int year;
};
int main ()
{
    int i,f=0;
    struct date d[2];
    for(i=0;i<2;i++)
    {
       cout<<"Enter date,month and year for "<<i+1<<" structure"<<endl;
       cout<<"Enter date: ";  cin>>d[i].date;
       cout<<"Enter the month: ";  cin>>d[i].month;
       cout<<"Enter the year: ";  cin>>d[i].year;
       cout<<endl;
    }
    if(d[0].date==d[1].date)
    {
       if(d[0].month==d[1].month)
       {
          if(d[0].year==d[1].year)
          {
             f=1;
          }
       }
    }
    if(f==1)
    cout<<"\nThe dates are equal";
    else
    cout<<"\nThe dates are not equal";
    
    return 0;
}
