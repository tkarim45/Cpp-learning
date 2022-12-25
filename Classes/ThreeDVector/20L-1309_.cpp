#include "ThreeDvector.h"
#include <iostream>
using namespace std;
int main()
{
	ThreeDvector V1;
	ThreeDvector V2 (4,5,6);
	V1.print();  // output (0, 0, 0)
	V2.print(); //output (4, 5, 6)

	V1.setx(1).sety(2).setz(3);// cascaded call

	ThreeDvector test;

	test= V1+V2; 
	test.print(); // output (5, 7, 9)


	test= V1+10;
	test.print(); // output (11, 12, 13)


	test= V1*10; 
	test.print();// output (10, 20, 30)



	cout<<V1*V2<<endl;  // output 32


	cout<<(V1>V2)<<endl; // output 0
	cout<<(V1==V2)<<endl;// output 0
	cout<<(V1!=V2)<<endl;// output 1


	cout<<V2[0]<<endl;  // output  4
	cout<<V2[1]<<endl;  // output  5
	cout<<V2[2]<<endl;  // output  6
	cout<<V2[3]<<endl;  // output  index out of range
	system("pause");
}

