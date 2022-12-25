#include<iostream>
using namespace std;
int DeterminePointLocation (int p1x,int p1y,int p2x,int p2y,int p3x,int p3y,int p4x,int p4y,int px,int py)
{
     if(((px<p1x) || (px<p2x) || (px>p3x) || (px>p4x)) && ((py<p1y) || (py<p2y) || (py>p3y) || (py>p4y)))
    {
        return 1;
    }
    if(((py>p1y) || (py<p2y) || (py<p3y) || (py>p4y)) && ((px>p1x) || (px>p2x) || (px<p3x) || (px<p4y)))
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
void DisplayPointLocation(int type)
{
   if(type==1)
   {
       cout<<"point lies inside rectangle"<<endl;
   }
   else  if(type==2)
   {
       cout<<"point lies outside rectangle"<<endl;
   }
   else  if(type==3)
   {
       cout<<"point lies on the rectangle"<<endl;
   }
}
int main()
{
    char choice;
    int p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y,px,py;
    cout << "enter points:" << endl;
    cout << "P1: ";
    cin >> p1x >> p1y;
    cout << "P2: ";
    cin >> p2x >> p2y;
    cout << "P3: ";
    cin >> p3x >> p3y;
    cout << "P4: ";
    cin >> p4x >> p4y;
    cout << "P: ";
    cin >> px >> py;
    bool type= DeterminePointLocation (p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y,px,py);
    DisplayPointLocation(type);
    return 0;
}
