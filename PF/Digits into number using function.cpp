#include<iostream>
using namespace std;
void printnum(int);
void conversion(int);
int main()
{
	cout<<" Conversion of Digit into Number "<<endl;
	int num;
	cout<<" Enter the Number "; cin>>num;
	conversion(num);
	return 0;
}
void printnum(int digit)
{
	switch(digit)
	{
		case 1:
		cout<<" One "<<"\t"; break;
		
		case 2:
		cout<<" two "<<"\t"; break;
		
		case 3:
		cout<<" three "<<"\t"; break;
		
		case 4:
		cout<<" four "<<"\t"; break;
		
		case 5:
		cout<<" five "<<"\t"; break;
		
		case 6:
		cout<<" six "<<"\t"; break;
		
		case 7:
		cout<<" seven "<<"\t"; break;
		
		case 8:
		cout<<" eight "<<"\t"; break;
		
		case 9:
		cout<<" nine "<<"\t"; break;	
	}
}
void conversion(int num)
{
	if(num<100 || num>999)
	{
	   cout<<" Error Enter the Number within the range "<<endl;
	   return;
    }  
	int d1,d2;
	d2=num%10;
	num=num/10;
	d1=num%10;
	num=num/10;
	printnum(num);
	printnum(d1);
	printnum(d2);
}
