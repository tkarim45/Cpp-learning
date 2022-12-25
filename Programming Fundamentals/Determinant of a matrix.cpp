#include<iostream>
using namespace std;
 
int main(){
 
  int a[3][3], i, j;
 
  long determinant;
  cout<<"Enter the 9 elements of matrix: ";
  for(i = 0 ;i < 3;i++)
      for(j = 0;j < 3;j++)
           cin>>a[i][j];
 
  cout<<"\n The matrix is\n";
  for(i = 0;i < 3; i++){
      cout<<"\n";
      for(j = 0;j < 3; j++)
           cout<<"\t"<<a[i][j];
  }
 
  determinant = a[0][0] * ((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) -a[0][1] * (a[1][0]
   * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
 
  cout<<"\n Determinant of 3X3 matrix: "<<determinant;
 
   return 0;
}
