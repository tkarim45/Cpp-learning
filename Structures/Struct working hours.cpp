#include <iostream>
using namespace std;
struct worker
{
	int salary;
	float workhours ;
    char name[50];
   
} w[10];
int main()
{ 
    for(int i=0;i<2;i++)
    {
        cout << "Enter information of the workers "<<i+1 << endl;	
        cout << "Enter name: "; cin >> w[i].salary;
        cout << "Enter Salary: "; cin>>w[i].salary; cout<<"$";
        cout << "Enter workhours: ";  cin>>w[i].workhours;
        cout << endl;
        
        if(w[i].workhours>=12)
        {
        	w[i].salary=w[i].salary+150;
	    }
		else if(w[i].workhours>=10)
        {
        	w[i].salary=w[i].salary+100;
		}
	    else if(w[i].workhours>=8)
        {
        	w[i].salary=w[i].salary+50;
		}
    }
    cout << "Displaying Information: " << endl;
    for(int i = 0;i<10;++i)
    {
        cout << "\nName: " << w[i].name << endl;
        cout << "Salary: " << w[i].salary<< endl;
        cout << "Working Hours: " << w[i].workhours << endl;
    }
    return 0;
}
