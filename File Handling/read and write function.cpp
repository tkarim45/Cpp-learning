#include<iostream>
#include<fstream>
#include<time.h>
#include <iomanip>
using namespace std;
int main()
{
	clock_t start, end; 
	start = clock();  
	ifstream ifile("file1.txt");
	ofstream ofile("file1copy.txt");
	if(!ifile || !ofile)
	{
		cout<<"Error Opening file";
	}
	char file[40000];
	while(ifile.read(file, 40000))
	{
		ofile.write(file, 40000);
	}
	end = clock(); 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
	cout << "Time taken by program is : " << fixed << time_taken<< setprecision(5); cout << " sec " << endl; 
	return 0;
}
