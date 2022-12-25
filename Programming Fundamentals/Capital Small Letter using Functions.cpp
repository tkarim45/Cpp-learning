#include<iostream>
using namespace std;
int CharacterType(char Sym);
void PrintCharacterType(int T);
int main()
{	
	char cha;
	cout<<"Enter the character = "; cin>>cha;
	int type=CharacterType(cha);
	PrintCharacterType(type);
	return 0;
}
void PrintCharacterType(int T)
{
	switch(T)
	{
		case 1:
		cout<<"Capital Letter "<<endl; break;
		
		case 2:
		cout<<"Small Letter "<<endl; break;
		
		case 3:
		cout<<"Non "<<endl; break;		
	}
}
int CharacterType(char Sym)
{
	if(Sym>='A'&& Sym<='Z')
	return 1;
	
	else if(Sym>='a' && Sym<='z')
	return 2;
	
	else
	return 3;
}
