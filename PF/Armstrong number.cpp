
#include <iostream>
using namespace std;
int main() 
{
    int num, x, remainder, sum = 0;
    cout << "Enter a three-digit integer: ";
    cin >> num;
    x = num;
    while (x!=0)
	{
        remainder=x% 10;
        sum+=remainder*remainder*remainder;
        x /= 10;
    }
    if (sum == num)
    cout << num << " is an Armstrong number.";
    else
    cout << num << " is not an Armstrong number.";
    return 0;
}
