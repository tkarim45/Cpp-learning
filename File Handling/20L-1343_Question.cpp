#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
char encrypt(char array[],int length)
{
    for (int i=0; i<length ;i++)
	{
		array[i]+=i;
	}
	return array[length];
}
char decrypt(char array[],int length)
{
    for (int i=0; i<length ;i++)
	{
		array[i]-=i;
	}
	return array[length];
}
int main()
{
	char intent;
	int size=0, sizep=0;
	do
	{
		char nuser[20], user[20], npass[10], pass[10], cuser[20], cpass[10], ccuser[20], ccpass[10];
		
		for (int i=0 ; i<20 ; i++)
		{
			
			nuser[i]=' ';
			user[i]=' ';
			
			if (i<10)
			{
				npass[i]=' ';
				pass[i]=' ';
			}	
		}	
		cout<<endl<<"Do you want to login, register, update or exit (L/R/U/E): ";
		cin>>intent;
		cout<<endl;	
		ofstream user_data("Users_Login_Details.txt",ios::app);
		ifstream usedata("Users_Login_Details.txt");
		if (intent=='R' || intent=='r')
		{
			cin.ignore();
			int count=1;
			while (count==1)
			{
				
				count=0;
				cout<<"New Username(max. 20 characters without space): ";
				cin.getline(nuser,20);
				size = strlen(nuser);
				
				while (!usedata.eof())
				{
					usedata>>cuser>>cpass;
					if (strcmp(nuser,cuser)==0)
					{
						cout<<endl<<"Username already taken !  Try a new one:"<<endl;
						count=1;
						break;
					}
				}
			}
			
			cout<<"New Password(4 to 10 characters without space): ";
			cin.getline(npass,10);
			sizep = strlen(npass);
		
			user_data<<nuser;
			for (int i=0 ; i<22-size ; i++)
			{
				user_data<<' ';
			}
			encrypt(npass,sizep);
			user_data<<npass;
			for (int i=0 ; i<10-sizep ; i++)
			{
				user_data<<' ';
			}
			user_data<<endl;
			cout<<endl<<"Registered Successfully !"<<endl;
			cout<<"________________________________________________________________________________________________________"<<endl;
			
		}
		
		else if (intent=='l' || intent=='L')
		{
			cin.ignore();
			int count=1;
			while (count==1)
			{
				ifstream usedata("Users_Login_Details.txt");
				cout<<"Username: ";
				cin.getline(user,20);
				cout<<"Password: ";
				cin.getline(pass,10);
				sizep=strlen(pass);
				encrypt(pass,sizep);
				while (!usedata.eof())
				{
					usedata>>cuser>>cpass;
					if (strcmp(user,cuser)==0)
					{
						if (strcmp(pass,cpass)==0)
						{
							cout<<endl<<"Logged In Successfully !"<<endl;
							count=0;
							break;
						}
					}
				}
				if (count!=0)
				{
					cout<<endl<<"Invalid username or password !   Please try again:"<<endl;
				}
			}
		}
		
		else if (intent=='U' || intent=='u')
		{
			char decision;
			cout<<"Would you like to update your username or password (U/P): ";
			cin>>decision;
			if (decision=='U' || decision=='u')
			{
				ofstream t("temp.txt");
				ifstream tr ("temp.txt");
				
				cin.ignore();
				int count=1;
				
					cout<<" Old Username: ";
					cin.getline(user,20);
					cout<<"Password: ";
					cin.getline(pass,10);
					sizep=strlen(pass);
					encrypt(pass,sizep);
					while (usedata>>cuser>>cpass)
					{
					
					if (strcmp(user,cuser)==0)
					{
						if (strcmp(pass,cpass)==0)
						{
							cout<<"New username: ";
							cin.getline(cuser,20);
							count=0;	
						}
					}
					t<<cuser<<" "<<cpass<<endl;
					}
					if (count==1)
					{
						cout<<"Invalid!"<<endl;
						return 0;
					}
					ofstream rt ("Users_Login_Details.txt");
					while (tr>>cuser>>cpass)
					{
					rt<<cuser<<" "<<cpass<<endl;
					}
				}
					else if (decision=='p' || decision=='P')
			{
				ofstream t("temp.txt");
				ifstream tr ("temp.txt");
				
				cin.ignore();
				int count=1;
				
					cout<<" Username: ";
					cin.getline(user,20);
					cout<<" old Password: ";
					cin.getline(pass,10);
					sizep=strlen(pass);
					encrypt(pass,sizep);
					while (usedata>>cuser>>cpass)
					{
					
					if (strcmp(user,cuser)==0)
					{
						if (strcmp(pass,cpass)==0)
						{
							cout<<"New Password: ";
							cin.getline(cpass,20);	
							sizep=strlen(cpass);
							encrypt(cpass,sizep);
							count=0;
						}
					}
					t<<cuser<<" "<<cpass<<endl;
					}
					if (count==1)
					{
						cout<<"Invalid!"<<endl;
						return 0;
					}
					ofstream rt ("Users_Login_Details.txt");
					while (tr>>cuser>>cpass)
					{
					    rt<<cuser<<" "<<cpass<<endl;
					}
		    	}	
	    	}		
        } 
	while (intent!='E' && intent!='e');
}
