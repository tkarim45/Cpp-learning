#include<iostream>
#include<fstream>
#include<time.h>
#include <iomanip>
using namespace std;
int main()
{
	clock_t start, end; 
	start = clock();  
	ifstream ifile("file.txt");
	ofstream ofile("filecopy.txt");
	char c; 
	if(!ifile || !ofile)
	{
		cout<<"Error Opening file";
	}
	while(ifile.get(c) && ifile.tellg()<40000)
	{
		ofile.put(c);
	}
    end = clock(); 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
	cout << "Time taken by program is : " << fixed << time_taken<< setprecision(5); cout << " sec " << endl; 
	return 0;
}

