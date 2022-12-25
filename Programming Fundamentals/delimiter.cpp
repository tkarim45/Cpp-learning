#include<iostream>
using namespace std;
void myTokenizer(char input[], char listtoken[100][100], char del)
{
	int i=0,word=0,letter=0;
	while (input[i] != '\0')
	{
		if (input[i] == del)
		{
			word++;
			letter=0;
			i++;
		}
		else
		{
			listtoken[word][letter] = input[i];
			i++;
			letter++;
		}
	}
	cout<<"Token are: "<<endl;
	for (int j=0;j<=word;j++)
	{
		cout<<listtoken[j]<<endl;
	}
	return;
}
int main()
{
	char input[100], del, listtoken[100][100];
	cout<<"Input :";	cin>> input;
	cout << "delimeter :";	cin >> del;
	myTokenizer(input, listtoken, del);
}
