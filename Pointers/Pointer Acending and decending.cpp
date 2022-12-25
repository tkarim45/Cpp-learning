#include<iostream>
using namespace std;
int main()
{
    int a = 5;
    int b = 10;
    int c = 12;
    int* aptr = &a;
    int* bptr = &b;
    int* cptr = &c;
    if (*aptr > *bptr && *aptr > *cptr)
    {
        if (*bptr > *cptr)
        {
            cout << "Ascending Order is: " << *cptr << " " << *bptr << " " << *aptr << " " << endl;
            cout << "Median of num: " << *bptr << endl;
        }
        else
        {
            cout << "Ascending Order is: " << *bptr << " " << *cptr << " " << *aptr << " " << endl;
            cout << "Median of num: " << *cptr << endl;
        }
    }
    else if (*bptr > *aptr && *bptr > *cptr)
    {
        if (*aptr > *cptr)
        {
            cout << "Ascending Order is: " << *cptr << " " << *aptr << " " << *bptr << " " << endl;
            cout << "Median of num: " << *aptr << endl;
        }
        else
        {
            cout << "Ascending Order is: " << *aptr << " " << *cptr << " " << *bptr << " " << endl;
            cout << "Median of num: " << *cptr << endl;
        }
    }
    else
    {
        if (*aptr > *bptr)
        {
            cout << "Ascending Order is: " << *bptr << " " << *aptr << " " << *cptr << " " << endl;
            cout << "Median of num: " << *aptr << endl;
        }
        else
        {
            cout << "Ascending Order is: " << *aptr << " " << *bptr << " " << *cptr << " " << endl;
            cout << "Median of num: " << *bptr << endl;
        }
    }
}