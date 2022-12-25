#include "fraction.h"
#include <fstream> // to create file stream

int main()
{
	fraction f10 = fraction::ones();
	cout << f10; 
	fraction f1(1, 2);
	fraction f2(1, 2);

	fraction f3 = 2 / ++f2;
	//what will be f3?
	cout << f3 << endl << f2;

	fraction f4 = 2 / f1++;
	cout << f4 << endl << f1;
	//what will be f3?

	//write fraction to file
	//first create a output file stream (ofstream Output stream class to operate on files.
	//ofstream is subtype of ostream
	ofstream ofs;
	ofs.open("output.txt");// new file is created and you will start writing from start of file

	ofs << "Hi file" << endl;// randomly writing anything on file
	ofs<<5;
	ofs<<'/';
  ofs<<6;
	ofs<<endl;

//instead of top 4 lines lets call the overloaded << function for fraction 
	ofs << f1;
	ofs << f3 << f1;

	// change the << oL oper such that new line is writen on every write. 
	ofs.close();

	//ofs was of type ofstream, so how was it passed to ostream type formal parameter in << function?

	//lets read from fraction from file
	fraction f5(0, 0);

	//create input file stream
	ifstream ifs;
	ifs.open("input.txt");//file will be opened and you canread character by character usung ifs

	int num;
	ifs >> num;
	char slash;
	ifs >> slash;
	int den;
	ifs >> den;
	cout << "This is read " << num << slash << den << endl;

	ifs >> f5;

	cout << "This was read directly form file " << f5 << endl;

	ifs.close();

	// open the file containing multiple fractions and read them in array of fractions. 
	//First line in file will constain the number of fractions in file
	ifs.open("fractions.txt");//file will be opened and you canread character by character usung ifs
	int size;
	ifs >> size;
	cout << "size " << size << endl;
	//create array of that size;
	fraction *array = new fraction[4];
	for (int i = 0;i<size; i++)
		ifs >> array[i];

	for (int i = 0;i<size; i++)
		cout << array[i];

	system("pause");



}