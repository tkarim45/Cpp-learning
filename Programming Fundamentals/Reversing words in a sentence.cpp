#include <iostream>
#include<cstring>
using namespace std;
void reverseword(char arr[])
{
    int len= strlen(arr) - 1;
    for(int i=0; i<=len/2; i++)
    {
        char temp=arr[i];
        arr[i]=arr[len-i];
        arr[len-i]=temp;
    }
}
int main()
{
    char arr[100]={};
    cout<<"Enter the Sentence : ";
    cin.get(arr,100);
    reverseword(arr);
    cout<<arr;
}
