#include<iostream> 
using namespace std; 
void Counter(string str) 
{ 
    int upper = 0, lower = 0, number = 0, spaces = 0,total=0; 
    for (int i = 0; i < str.length(); i++) 
    { 
        if (str[i] >= 'A' && str[i] <= 'Z') 
            upper++; 
        else if (str[i] >= 'a' && str[i] <= 'z') 
            lower++; 
        else if (str[i]==' ') 
            spaces++;   
    }
	total=upper+lower+spaces; 
    cout << "Upper case letters: " << upper << endl; 
    cout << "Lower case letters : " << lower << endl; 
    cout << "Spaces : " << spaces << endl; 
    cout << "Total : " << total << endl; 
} 
int main() 
{ 
    string str = "Hello, I am a student of FAST University"; 
    Counter(str); 
    return 0; 
} 
