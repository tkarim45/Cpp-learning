#include<iostream>
using namespace std;
int main()
{
    int nums[10] = {4, 5, 4, 4, 7, 22, 4, 7, 4, 8};
    int max_count = 0;
    cout << "Original array: ";
    for (int i=0; i < 10; i++)
	{
		cout << nums[i] <<" ";
	} 
	cout << "\nMost occurred number: ";
    for (int i=0; i<10; i++)
    {
   		int count=1;
   		for (int j=i+1;j<10;j++)
   		{
   			if (nums[i]==nums[j])
           	count++;
		}	
    	if (count>=5)
      	max_count=count;        
    }
    if(max_count<5)
    cout<<"None Popular:"<<endl;
    for (int i=0;i<10;i++)
    {
   		int count=1;
   		for (int j=i+1;j<10;j++)
   		{
   		   	if (nums[i]==nums[j])
           	count++;	
		}
   	   if (count==5 )
       cout << nums[i] << endl;
	}
}
