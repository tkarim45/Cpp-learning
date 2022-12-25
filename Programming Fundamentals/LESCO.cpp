#include<iostream>
using namespace std;
int main()
{
	double peak_units, off_peak_units;
	double off_peak_sum=0, peak_sum=0;
	double TOTAL_SUM = 0;
	int num;
	x:
	cout << "Press 1 for User Interface and 2 for Manager Interface: "; cin >> num;
	if (num == 1)
	{
		cout << "Enter Peak Unit: "; cin >> peak_units;
		cout << "Enter the Off-Peak Units: "; cin >> off_peak_units;

		if (peak_units <= 100)
		{
			peak_sum = (peak_units * 16.62);
		}	
		else if (peak_units > 100 && peak_units <= 300)
		{
			peak_sum = ((100 * 16.62) + ((peak_units - 100) * 20.19));
		}
		else if (peak_units > 300)
		{
			peak_sum = ((100 * 16.62) + (100 * 20.19) + ((peak_units - 200) * 25.12));
		}
	
	    //Calculation of Off_Peak Units Price

		if (off_peak_units <= 100)
		{
			off_peak_sum = off_peak_units * 13.85;
		}	
		else if (off_peak_units > 100 && off_peak_units <= 300)
		{
			off_peak_sum = ((100 * 13.85) + ((off_peak_units - 100) * 16.83));
		}
		else if (off_peak_units > 300)
		{
			off_peak_sum = ((100 * 13.85) + (100 * 16.83) + ((off_peak_units - 200) * 20.94));
		}
		TOTAL_SUM = off_peak_sum + peak_sum;
		cout << "Total Bill is: " << TOTAL_SUM << endl;
		exit(-1);
	}

	else if (num == 2)
	{
		int x;
		int OP1, OP2, OP3, MR, SR;
		cout << "Press 1 to Change Off-Peak Unit(1-100)" << endl;
		cout << "Press 2 to Change Off-Peak Unit(101-300)" << endl;
		cout << "Press 3 to Change Off-Peak Unit(301-Onwards)" << endl;
		cout << "Press 4 to Meter Rent" << endl;
		cout << "Press 5 to Change Service Rent "; cin >> x;
		
		switch (x)
		{
			case 1:
				cout << "Change Off-peak unit Price (1-100): "; cin >> OP1;
				off_peak_units = OP1;
				break;
			case 2:
				cout << "Change Off-peak unit Price (101-300): "; cin >> OP2;
				off_peak_units = OP2;
				break;
			case 3:
				cout << "Change Off-peak unit Price (301-Onwards): "; cin >> OP3;
				off_peak_units = OP3;
				break;
			case 4:
				cout << "Change Meter rent: "; cin >> MR;
				break;
			case 5:
				cout << "Change Service rent: "; cin >> SR;
				break;
		}
	}
	else
		cout << "Wrong Input: " << endl;
		goto x;
}