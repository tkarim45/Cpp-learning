#include <iostream>
#include<string>
#include<cstring>
using namespace std;
void encrypt(char arr[])
{
	int len=strlen(arr);
    for(int i=0;i<len;i++)
    {
        arr[i]=arr[i]+i;
    }
    for(int i=0;i<len;i++)
    {
        cout<<arr[i];
    }
}
void decrypt (char arr[])
{
	int len=strlen(arr);
     for(int i=0;i<len;i++)
    {
        arr[i]=arr[i]-i;
    }
    for(int i=0;i<len;i++)
    {
        cout<<arr[i];
    }
}
int main()
{
   char arr[100]={};
   cout<<"enter the array"<<endl;
   cin.getline(arr,100);
   cout<<"decrypted array is"<<endl;
   decrypt(arr);
   cout << endl;
   cout << "encrypted array is" << endl;
   encrypt(arr);
    return 0;
}
