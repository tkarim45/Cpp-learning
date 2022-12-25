 #include<iostream>
using namespace std;
int calculator(int value1,int value2,char symbol);
int main()
{
	int value1,value2;
	char symbol,choice;
	do
	{	
    	cout<<"Enter two Numbers ="; cin>>value1>>value2;
    	cout<<"Enter the Symbol = "; cin>>symbol;
	    cout<<value1<<symbol<<value2<<" is: "<<calculator(value1,value2,symbol)<<endl;
    	cout<<"(c)ontinue and (s)top = "; cin>>choice;
    	cout<<endl;
    } 
    while(choice=='c' || choice=='C');
    return 0;

}
int calculator(int value1,int value2, char symbol)
{
	int ans;
	switch(symbol)
	{
		case '+':
		ans=value1+value2;
		return ans;
		
		case '*':
		ans=value1*value2;
		return ans;
		
		case '-':
		ans=value1-value2;
		return ans;
		
		case '/':
		ans=value1/value2;
		return ans;
		
		case '%':
		ans=value1&value2;
		return ans;		
	}
}
