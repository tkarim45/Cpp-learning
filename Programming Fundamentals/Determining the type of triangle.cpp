#include<iostream>
using namespace std;
int calculatingdistance(int p1x,int p1y,int p2x,int p2y)
{
	return (p1x-p2x)*(p1x-p2x)+(p1y-p2y)*(p1y-p2y);
}
int Determingtriangletype(int p1x,int p1y,int p2x,int p2y,int p3x, int p3y)
{
	int s1,s2,s3;
	s1=calculatingdistance(p1x,p1y,p2x,p2y);
	s2=calculatingdistance(p2x,p2y,p3x,p3y);
	s3=calculatingdistance(p3x,p3y,p1x,p1y);
	
	if(s1==s2 && s1==s3)
	{
		return 1;
	}
	else if(s1==s3 && s1!=s2)
	{
		return 2;
	}
	else
	return 3;
}
void Displaytrinagletype(int type)
{
	switch(type)
	{
		case 1:
		cout<<"Equilateral Traiangle "<<endl; break;
		
		case 2:
		cout<<"Isoceles Traiangle "<<endl; break;
		
		case 3:
		cout<<"Scalene Traiangle "<<endl; break;
	}
}
int main()
{
	int p1x,p1y,p2x,p2y,p3x,p3y;
	cout<<" Enter the Points "<<endl;
	cout<<"P1: "; cin>>p1x>>p1y;
	cout<<"P2: "; cin>>p2x>>p2y;
	cout<<"P3: "; cin>>p3x>>p3y;
	
	int type=Determingtriangletype(p1x,p1y,p2x,p2y,p3x,p3y);
	Displaytrinagletype(type);
	return 0;
	
}
