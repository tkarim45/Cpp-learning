#include<iostream>
using namespace std;
int main()
{
    int a[5][5],ord;
    cout<<"Enter row and column of matrix (max 5*5): ";
    cin>>ord;
    cout<<"Enter matrix a1 : "<<endl;
    for(int i=0;i<ord;i++)
        for(int j=0;j<ord;j++)
           cin>>a[i][j];
    for(int i=0;i<ord;i++)
        for(int j=0;j<ord;j++)
         {
             if(i!=j)
             {
                if(a[i][j]!=0)
                {
                    notidentity:
                    cout<<"Matrix is not Identity Matrix";
                    return 0;
                }
             }
              else
              {
                  if(a[i][j]!=1)
                    goto notidentity;
              }
         }
    cout<<"Matrix is Identity matrix ";
    return 0;
}
