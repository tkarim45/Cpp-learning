#include <iostream>
using namespace std;
int main()
{
	int max_value,value=2;
	cout << "Display primes up to what value? "; cin >> max_value;
	while (value <= max_value)
	{
		bool is_prime = true; 
		int trial_factor = 2;
		while (trial_factor < value)
		{
			if (value % trial_factor == 0)
			{
				is_prime = false; 
				break; 
			}
			trial_factor++;
		}
		if (is_prime)
		cout << value << " "; 
		value++; 
	}
	cout << endl; 
}
