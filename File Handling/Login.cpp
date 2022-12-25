#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
const int num=100;
string Usernm[num]={};  // Global Variable
string Passwd[num]={};
void openfile()  // Fucntion for opening and reading file
{
	string line;
	ifstream myfile("D:\\login.txt");		
	if(myfile.is_open())
	{
		for(int i=0;(i<100 && myfile>>Usernm[i]>>Passwd[i]);i++)
		{
			
		}
	}
	cout<<"File Couldn't Open "<<endl;	
}
void login()  //function for login
{
	int key,check;
	char user[20],pass[10];
	system("cls");
	cin.ignore();
	cout<<"Enter Username: "; cin.getline(user, 20);
	cout<<"Enter Password: "; cin.getline(pass, 10);
	cout<<"Enter Key: "; cin>>key;	
	for(int i = 0; (i<10 && pass[i] != '\0'); i++)  //encrypting user password
	{
       pass[i]=pass[i]+key;
	}
	
	for(int i=0;i<num;i++)   //Checking wheather the user entered correct password and username
	{
		if(Usernm[i]==user && Passwd[i]==pass)
		{
			check=1;
			system("cls");
			break;
		}
	}
	if(check==1)  
	{
		cout<<"Login Successfully\n";
		cout<<"\nWelcome "<<user;
		Sleep(3000);
		system("cls");
	}
	else
    {
        cout<<"\nLogin Error, Please Check Your Username and Password";
        Sleep(3000);
        system("cls");
    }
}
void registr()  //Function for registering a new user
{
	int key;
	char user[20],pass[10];
	system("cls");
	cin.ignore();
	cout<<"Enter Username: "; cin.getline(user, 20);
	cout<<"Enter Password: "; cin.getline(pass, 10);
	cout<<"Enter Key for Password Encryption and Remember this key for Login: "; cin>>key;
	for(int i = 0; (i<10 && pass[i] != '\0'); i++)  //encrypting the user password
	{
       pass[i]=pass[i]+key;
	}
	for(int i=0;i<num;i++)
	{
		if(Usernm[i]=="\0")   //Storing user name and password in global variable
		{
			Usernm[i]=user;
			Passwd[i]=pass;
			cout<<"\nRegistered Successfully";
			break;
		}
	}
}
void resetusernm(string usernm)  //function for reseting username
{
	char user[20];
	for(int i=0;i<num;i++)
	{
		if(Usernm[i]==usernm)  
		{
			cin.ignore();
			cout<<"Enter New Username: "; cin.getline(user, 20);
			Usernm[i]=user;
			cout<<"\nUsername Update Successfully";
			Sleep(2000);
			system("cls");
			break;
		}
	}
}
void resetpasswd(string usernm, string passwd) //function for reseting password
{
	char pass[20];
	int key;
	for(int i=0;i<num;i++)
	{
		if(Usernm[i]==usernm && Passwd[i]==passwd)
		{
			cin.ignore();
			cout<<"Enter New Password: "; cin.getline(pass, 10);
			cout<<"Enter Key for Password Encryption and Remember this key for Login: "; cin>>key;
			for(int j = 0; (j<10 && pass[j] != '\0'); j++)
        	{
                pass[j]=pass[j]+key;
        	}
			Passwd[i]=pass;
			cout<<"\nPassword Update Successfully";
			Sleep(2000);
			system("cls");
			break;
		}
	}
}
void savefile()  //Function for storing all the data in the file 
{
	ofstream myfile;
	myfile.open("D:\\login.txt");
	for(int i=0;i<num;i++)
	{
		if(Usernm[i]=="\0")
		{
			break;
		}
		else
		{
			myfile<<Usernm[i]<<" "<<Passwd[i]<<endl;
		}
	}
	myfile.close();
}

main()
{
	openfile();	  
	cout<<"\t\tWelcome to login page\t\t\n\n";  //login menu
	int key,choice,check=0;
	string user,pass;
	system("cls");
	do                       
	{
		cout<<"1. Login\n";
        cout<<"2. Register\n";
        cout<<"3. Reset Username\n";
        cout<<"4. Reset Password\n";
        cout<<"5. Exit and Save to Text File \n\n";
        cout<<"Enter your choice: "; cin>>choice;
        cout<<endl;
        
        switch(choice)
        {
            case 1:
                login();
                break;
            case 2:
                registr();
                Sleep(2000);
                system("cls");
                break;
            case 3:            //checks the username and password for reseting the username
            	system("cls");
            	cin.ignore();
				cout<<"Enter Old Username: "; getline(cin,user)	;
				cout<<"Enter Password: "; getline(cin,pass)	;
				cout<<"Enter Key: "; cin>>key;
	            for(int i = 0; (i<10 && pass[i] != '\0'); i++)
	            {
                   pass[i]=pass[i]+key;
            	}
            	for(int i=0;i<num;i++)
             	{
	            	if(Usernm[i]==user && Passwd[i]==pass)
	            	{
	            		check=1;
	             		system("cls");
	            		break;
	             	}
             	}
             	if(check==1)
             	{
             		resetusernm(user);
				}
                else
                {
                  cout<<"\nLogin Error, Please Check Your Username and Password";
                  Sleep(3000);
                  system("cls");
                }
             	break;
            case 4:                //checks the username and password for reseting the username
  		        system("cls");
            	cin.ignore();
				cout<<"Enter Username: "; getline(cin,user)	;
				cout<<"Enter Old Password: "; getline(cin,pass)	;
				cout<<"Enter Key: "; cin>>key;
	            for(int i = 0; (i<10 && pass[i] != '\0'); i++)
	            {
                   pass[i]=pass[i]+key;
            	}
            	for(int i=0;i<num;i++)
             	{
	            	if(Usernm[i]==user && Passwd[i]==pass)
	            	{
	            		check=1;
	             		system("cls");
	            		break;
	             	}
             	}
             	if(check==1)
             	{
             		resetpasswd(user,pass);
				}
                else
                {
                  cout<<"\nLogin Error, Please Check Your Username and Password";
                  Sleep(3000);
                  system("cls");
                }
		     	break;
        }     
	}
	while(choice!=5);    
	savefile();  //stroes all the data in the text file or updates the text file accordingly when the user enters 5
	cout<<"Exit......Saving to file"<<endl;
	return 0;	
}
