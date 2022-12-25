#include<iostream>
using namespace std; 
#define n 4 
void swapUpperToLower(int arr[n][n]) 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { 
            int temp = arr[i][j]; 
            arr[i][j] = arr[j][i]; 
            arr[j][i] = temp; 
        } 
    }  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) 
            cout << arr[i][j] << " "; 
        cout << endl; 
    } 
} 
int main() 
{ 
    int arr[n][n] = { { 2, 3, 5, 6 }, 
                    { 4, 5, 7, 9 }, 
                    { 8, 6, 4, 9 }, 
                    { 1, 3, 5, 6 } }; 
  
    swapUpperToLower(arr);
    return 0; 
} 


