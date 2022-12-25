#include<iostream>
using namespace std;
int main()
{ 
  int a[3][3], i, j;
  long Trace;
  cout<<"Enter the 9 elements of matrix: "<<endl;
  for(i = 0 ;i < 3;i++)
      for(j = 0;j < 3;j++)
           cin>>a[i][j];
 
  cout<<"\n The matrix is\n";
  for(i = 0;i < 3; i++)
  {
    cout<<"\n";
    for(j = 0;j < 3; j++)
    cout<<"\t"<<a[i][j];
  }
  cout<<endl;
  Trace= a[0][0] + a[1][1] + a[2][2];
  cout<<"Trance of the Matrix is "<<Trace;
  return 0;
}
