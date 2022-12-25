// This program shows which roll number got highest aggregate
#include <iostream>
using namespace std;
// This program takes roll number and marks of 5 courses as input 2 times
int Sum(int c1, int c2, int c3, int c4, int c5);    //prototype
bool UpdateMax(int highest_Yet, int c1, int c2, int c3, int c4, int c5);    //prototype
int main()
{
    int r_no, max_r_no;
    int c1, c2, c3, c4, c5;
    int max_total = 0;
    cout << "1st student Roll# and marks of five courses: " << endl;
    cin >> r_no >> c1 >> c2 >> c3 >> c4 >> c5;
    max_total = Sum(c1, c2, c3, c4, c5);
    max_r_no = r_no;
    cout << "2nd student Roll# and marks of five courses: " << endl;
    cin >> r_no >> c1 >> c2 >> c3 >> c4 >> c5;
    if(UpdateMax(max_total, c1, c2, c3, c4, c5))
    {
        max_total  = Sum(c1, c2, c3, c4, c5);
        max_r_no = r_no;
    }
/*
    Write the code here for the rest of the Roll Nos and their courses marks
    one by one one...!!!
*/
    cout<<max_r_no<<" has the highest marks "<<max_total<< endl;
    return 0;
}
int Sum(int c1, int c2, int c3, int c4, int c5) //function
{
    return c1+c2+c3+c4+c5;
}
bool UpdateMax(int highest_Yet, int c1, int c2, int c3, int c4, int c5) //function
{
    if(highest_Yet<Sum(c1,c2, c3, c4, c5))
    {
        return true;
    }
    else
    {
        return false;
    }
}
