#include<iostream> 
using namespace std; 
void leaders(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        int j; 
        for (j = i+1; j<n; j++) 
        { 
            if (arr[i] <= arr[j]) 
            break; 
        }     
        if (j == n) 
        cout << arr[i] << " "; 
    } 
} 
int main() 
{ 
    int arr[] = {7,10,4,3,6,5,2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    leaders(arr, n); 
    return 0; 
}
