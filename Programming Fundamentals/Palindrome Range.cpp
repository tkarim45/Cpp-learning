#include<iostream>
using namespace std;
int main() 
{
	for (int i = 100; i <= 999; i++)
	{
		int rev = 0;
		for (int j = i; j > 0; j /= 10)
			rev = rev * 10 +j % 10;
		if (i == rev && i %2 != 0 && i %3 != 0)
		{
			cout << i << " ";
		}
	}
}