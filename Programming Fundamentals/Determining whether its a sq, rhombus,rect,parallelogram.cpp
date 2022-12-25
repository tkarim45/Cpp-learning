#include <iostream>
using namespace std;
int calculate_Distance(int p1x,int p1y, int p2x,int p2y)
{
    return (p1x-p2x)*(p1x-p2x)+(p1y-p2y)*(p1y-p2y);
}
int DetermineQuadrilateralType(int p1x,int p1y, int p2x,int p2y,int p3x,int p3y,int p4x,int p4y)
{
    int s1,s2,s3,s4,dg1,dg2;
    s1=calculate_Distance(p1x,p1y,p2x,p2y);
    s2=calculate_Distance(p2x,p2y,p3x,p3y);
    s3=calculate_Distance(p3x,p3y,p4x,p4y);
    s4=calculate_Distance(p4x,p4y,p1x,p1y);
    dg1=calculate_Distance(p1x,p1y,p3x,p3y);
    dg2=calculate_Distance(p2x,p2y,p4x,p4y);
    if (s1==s2 && s1==s3 && s1==s4)
    {   // Square or Rhombus
        if (dg1==dg2)
        {
            return 1;    // Square case
        }
        else
        {
            return 2;   // Rhombus Case
        }
    }
    else if (s1==s3 && s2==s4 && s1 != s2)
    {   // Rectangle or Parallelogram
        if (dg1==dg2)
        {
            return 3;    // Rectangle
        }
        else
        {
            return 4;   // Parallelogram
        }
    }
    else
    {
        return 5;     // Any other Quadrilateral
    }
}
void DisplayQuadrilateralType(int type)
{
    switch(type)
    {
    case 1:
         cout << "Its a square" << endl;break;
    case 2:
        cout << "Its a rhombus" << endl;break;
    case 3:
        cout << "Its a rectangle" << endl;break;
    case 4:
        cout << "Its a parallelogram" << endl;break;
    case 5:
        cout << "Its a quadrilateral" << endl;break;
    }
}
int main()
{
	int p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y;
	cout<<"Enter the Points "<<endl;
	cout<<"P1 = "; cin>>p1x>>p1y;
	cout<<"P2 = "; cin>>p2x>>p2y;
	cout<<"P3 = "; cin>>p3x>>p3y;
	cout<<"P4 = "; cin>>p4x>>p4y;
	
	int type= DetermineQuadrilateralType(p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y);
    DisplayQuadrilateralType(type);
	return 0;	
}
