/*
	Use left right arrow keys to navigate menu
	hit enter to select an option
	when running for very first time, you must register first, upon trying to login program will prompt and take you to registration to create file
*/


#include<iostream>
#include<cstring>
#include<fstream>
#include<windows.h>
#include<conio.h>

using namespace std;

HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);

void new_user();
int is_avail();
void login();
void recov();
void pass_change();
void name_change();
int nm_check();
void home_page();
void SIGNUP();
void LOGIN();
void RECOVERY();
void RECOV_OPT1();
void RECOV_OPT2();
int recov_opt=0;


char record[34];
char name[20];
char pass[10];
int len;
long pos;


int main()
{
	LOGIN();
}

void new_user()
{
	START:
	system("cls");
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<endl<<endl;
	cout<<"                                ";
	cout<<"SECURE ENCLAVE";
	cout<<endl<<endl<<"               ------------------------------------------------"<<endl<<endl<<endl;
	cout<<"                               ";
	cout<<"USER REGISTERY";
	cout<<endl<<endl<<endl;
	
	string u_name;
	string u_pass;
	
	ofstream infile;
	infile.open("L20_1113.txt",ios::app);
		
	do // Loop for repeating username input
	{
		for(int i=0;i<20;i++)
		{
			name[i]=0;
		}
		cout<<"               Enter your Username (1 - 20) ";
		SetConsoleTextAttribute(Color, 2);
		getline(cin,u_name); // input from user
		len=u_name.length(); // calculating length of string
		strncpy(name,u_name.c_str(),len);
		
		for(int i=0;i<20;i++)
		strncpy(name,u_name.c_str(),len);
		if (is_avail()==1)
		{SetConsoleTextAttribute(Color, 4);
		cout<<"                                            Username Unavailable"<<endl<<endl;
		Sleep(1000);
		goto START;
		}
	}while((len<1)||(len>20)||(is_avail()));
	
	// copying string to array
	for (int i=0;i<20;i++)
		record[i]=0;
		
	for(int i=0;i<len;i++)
	{
		record[i]=name[i];
	}
	record[31]=48+(len%10);
	record[30]=48+(len/10);
	
	PASS_START:
	
	system("cls");
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<endl<<endl;
	cout<<"                                ";
	cout<<"SECURE ENCLAVE";
	cout<<endl<<endl<<"               ------------------------------------------------"<<endl<<endl<<endl;
	cout<<"                               ";
	cout<<"USER REGISTERY";
	cout<<endl<<endl<<endl;
	cout<<"               Enter your Username (1 - 20) ";
	SetConsoleTextAttribute(Color, 2);
	cout<<name<<endl<<endl;
	do
	{
		SetConsoleTextAttribute(Color, 9);
		cout<<"               Enter your Password (4 - 10) ";
		SetConsoleTextAttribute(Color, 2);
		getline(cin,u_pass);
		len=u_pass.length();
		if ((len<4)||(len>10))
		{
			SetConsoleTextAttribute(Color, 4);
			cout<<"                                            Incorrect Password"<<endl;
			Sleep(1000);
			goto PASS_START;
		}
	}while((len<4)||(len>10));
	strncpy(pass,u_pass.c_str(),len);
	for (int i=20;i<30;i++)
		record[i]=0;
	for (int i=0;i<len;i++)
	{
		record[20+i]=(pass[i]^len);
	}
	record[32]=48+len;
	
	for (int i=0;i<34;i++)
	{
		infile.put(record[i]);
	}
	infile<<endl;
	cout<<endl<<endl<<"                    User Registered Successfully"<<endl;
	Sleep(2000);
	LOGIN();
	infile.close();
	
}

int is_avail()
{
	START:
	ifstream infile;
	infile.open("L20_1113.txt",ios::in);
	while(!infile)
	{
		SetConsoleTextAttribute(Color, 4);
		cout<<endl<<endl<<"                            Please register first"<<endl;
		Sleep(1000);
		new_user();
	}
	int len_pass;
	int len_u_name;
	do
	{
		pos=infile.tellg();
		infile.read(record,35);
		len_u_name=int((record[30]-48)*10)+(int(record[31]-48));
		if (len==len_u_name)
		{
			short check=0;
			for (int c=0;c<len;c++)
			{
				if (name[c]!=record[c])
				check++;
			}
			if (check==0)
			{
				infile.close();
				return 1;
			}
		}			
	}while(!infile.eof());
	infile.close();
	return 0;
}

void login()
{
	START:
	system("cls");
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<endl<<endl;
	cout<<"                                ";
	cout<<"SECURE ENCLAVE";
	cout<<endl<<endl<<"               ------------------------------------------------"<<endl<<endl<<endl;
	cout<<"                                  ";
	cout<<"USER LOGIN";
	cout<<endl<<endl<<endl;
	
	int len_u;
	string u_name;
	string u_pass;
	do // Loop for repeating username input
	{
		cout<<"               Enter your Username (1 - 20) ";
		SetConsoleTextAttribute(Color, 2);
		getline(cin,u_name); // input from user
		len=u_name.length(); // calculating length of string
		strncpy(name,u_name.c_str(),len);
		for(int i=0;i<20;i++)
		strncpy(name,u_name.c_str(),len);
		if (is_avail()==0)
		{SetConsoleTextAttribute(Color, 4);
		cout<<"                                            Username not Found"<<endl<<endl;
		Sleep(1000);
		goto START;
		}
	}while((len<1)||(len>20)|| (!is_avail()));
	len=int(record[32]-48);
	int u_att=0;
	do
	{
		PASSWORD:
		system("cls");
		SetConsoleTextAttribute(Color, 9);
		cout<<endl<<endl<<endl;
		cout<<"                                ";
		cout<<"SECURE ENCLAVE";
		cout<<endl<<endl<<"               ------------------------------------------------"<<endl<<endl<<endl;
		cout<<"                                  ";
		cout<<"USER LOGIN";
		cout<<endl<<endl<<endl;
		cout<<"               Enter your Username (1 - 20) ";
		SetConsoleTextAttribute(Color, 2);
		cout<<name<<endl<<endl;
		SetConsoleTextAttribute(Color, 9);
		cout<<"               Enter your Password (4 - 10) ";
		SetConsoleTextAttribute(Color, 2);
		getline(cin,u_pass);
		len_u=u_pass.length();
		for (int i=0;i<len;i++)
		{
			pass[i]=(record[20+i]^len);
		}
		char pass1[len_u];
		strcpy(pass1,u_pass.c_str());
		if((strcmp(pass,pass1))==0)
		{
			if(recov_opt==0)
			cout<<endl<<endl<<"                            login successful (Going to account security)"<<endl;
			if(recov_opt==1)
			name_change();
			if(recov_opt==2)
			pass_change();
			Sleep(2000);
			RECOV_OPT1();
		}
		else
		{
			SetConsoleTextAttribute(Color, 4);
			if(u_att<2)
			cout<<"                                            Incorrect Password"<<endl;
			u_att++;
			if (u_att==3)
			{
				cout<<"                                            too many password attempts (Going to Rcovery options)"<<endl;
				Sleep(2000);
				system("cls");
				RECOV_OPT1();	
			}
			else
			Sleep(1000);
			goto PASSWORD;
		}
	}while((len_u<4)||(len_u>10));
}

void pass_change()
{
	START:
	system("cls");
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<endl<<endl;
	cout<<"                                ";
	cout<<"SECURE ENCLAVE";
	cout<<endl<<endl<<"               ------------------------------------------------"<<endl<<endl<<endl;
	cout<<"                               ";
	cout<<"CHANGE PASSWORD";
	cout<<endl<<endl<<endl;
	char record_n[35];
	long file_len;
	ifstream infile; // file open
	infile.open("L20_1113.txt"); // file opem
	while(!infile.eof()){ // file check
		file_len=infile.tellg();
		infile.read(record_n,35);
	}
	infile.close();
	file_len/=35;
	file_len*=35;
	pos/=35;
	pos*=35;
	string u_pass;
	do
	{
		cout<<"               Enter your New Password (4 - 10) ";
		SetConsoleTextAttribute(Color, 2);
		getline(cin,u_pass);
		len=u_pass.length();
	}while((len<4)||(len>10));
	strncpy(pass,u_pass.c_str(),len);
	for (int i=20;i<30;i++)
		record[i]=0;
	for (int i=0;i<len;i++)
	{
		record[20+i]=(pass[i]^len);
	}
	record[32]=48+len;
	
	char new_arr[file_len];
	for (int c=0;c<file_len;c++)
	{
		new_arr[c]=0;
	}
	
	
	infile.open("L20_1113.txt",ios::in);
	for (int row=0;row<(file_len/35);row++)
	{
		infile.read(record_n,35);
		int c=0;
		for(int col=(row*35);col<((row*35)+34);col++)
		{
			new_arr[col]=record_n[c];
			c++;
		}
		cout<<endl;
	}
	infile.close();
		
	for(int c=0;c<34;c++)
	{
		new_arr[pos+c]=record[c];
	}
	
	cout<<endl<<endl<<"                        Password changed Successfully"<<endl;
	
	ofstream outfile;
	outfile.open("L20_1113.txt",ios::out);
	int c=0;
	for (int row=0;row<(file_len/35);row++)
	{
		for(int col=(row*35);col<((row*35)+34);col++)
		{
			outfile.put(new_arr[col]);
			c++;
		}
		outfile<<endl;
	}
	outfile.close();
	Sleep(2000);
	LOGIN();
}

void name_change()
{
	START:
	system("cls");
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<endl<<endl;
	cout<<"                                ";
	cout<<"SECURE ENCLAVE";
	cout<<endl<<endl<<"               ------------------------------------------------"<<endl<<endl<<endl;
	cout<<"                               ";
	cout<<"CHANGE USERNAME";
	cout<<endl<<endl<<endl;
	
	char n_name[20];
	strcpy(n_name,name);
	char n_pass[10];
	strcpy(n_pass,pass);
	char record_n[35];
	long file_len;
	ifstream infile; // file open
	infile.open("L20_1113.txt"); // file opem
	while(!infile.eof()){ // file check
		file_len=infile.tellg();
		infile.read(record_n,35);
	}
	infile.close();
	file_len/=35;
	file_len*=35;
	pos/=35;
	pos*=35;
	string u_name;
	do
	{
		cout<<"               Enter your New Username (1 - 20) ";
		SetConsoleTextAttribute(Color, 2);
		getline(cin,u_name);
		len=u_name.length();
		strncpy(name,u_name.c_str(),len);
		if (nm_check()==1)
		{SetConsoleTextAttribute(Color, 4);
		cout<<"                                                Username Unavailable"<<endl<<endl;
		Sleep(1000);
		goto START;
		}
	}while((len<1)||(len>20));
	strncpy(name,u_name.c_str(),len);
	for (int i=0;i<20;i++)
		record[i]=0;
	for(int i=0;i<len;i++)
	{
		record[i]=name[i];
	}
	record[31]=48+(len%10);
	record[30]=48+(len/10);
	
	char new_arr[file_len];
	for (int c=0;c<file_len;c++)
	{
		new_arr[c]=0;
	}
	
	
	infile.open("L20_1113.txt",ios::in);
	for (int row=0;row<(file_len/35);row++)
	{
		infile.read(record_n,35);
		int c=0;
		for(int col=(row*35);col<((row*35)+34);col++)
		{
			new_arr[col]=record_n[c];
			c++;
		}
	}
	infile.close();
		
	for(int c=0;c<34;c++)
	{
		new_arr[pos+c]=record[c];
	}
	
	cout<<endl<<endl<<"                        Username changed Successfully"<<endl;
	
	ofstream outfile;
	outfile.open("L20_1113.txt",ios::out);
	int c=0;
	for (int row=0;row<(file_len/35);row++)
	{
		for(int col=(row*35);col<((row*35)+34);col++)
		{
			outfile.put(new_arr[col]);
			c++;
		}
		outfile<<endl;
	}
	outfile.close();
	Sleep(2000);
	LOGIN();
	
}

int nm_check()
{
	char temp_rec[35];
	long temp_pos;
	int temp_len=len;
	ifstream infile;
	infile.open("L20_1113.txt",ios::in);
	int len_pass;
	int len_u_name;
	do
	{
		temp_pos=infile.tellg();
		infile.read(temp_rec,35);
		len_u_name=int((temp_rec[30]-48)*10)+(int(temp_rec[31]-48));
		if (temp_len==len_u_name)
		{
			short check=0;
			for (int c=0;c<len;c++)
			{
				if (name[c]!=temp_rec[c])
				check++;
			}
			if (check==0)
			{
				infile.close();
				return 1;
			}
		}			
	}while(!infile.eof());
	infile.close();
	return 0;
}

void SIGNUP()
{
	system("cls");		
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<endl<<endl;
	cout<<"                                ";
	cout<<"SECURE ENCLAVE";
	cout<<endl<<endl<<endl<<"               ------------------------------------------------";
	cout<<endl<<endl;
	cout<<"                  ";
	SetConsoleTextAttribute(Color, 2);
	cout<<"SIGN UP";
	cout<<"           ";
	SetConsoleTextAttribute(Color, 4);
	cout<<"LOGIN           RECOVERY"<<endl;
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<"               ------------------------------------------------";
	
	char ch = getch();
	if (ch==77)
	{
		LOGIN();		
	}
	else if ( ch==13 )
	{
		new_user();
	}
	else if ( ch==27)
	{ 
		Sleep(2000);
		exit(1);
	}
	else
	SIGNUP();	
}

void LOGIN()
{
	system("cls");
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<endl<<endl;
	cout<<"                                ";
	cout<<"SECURE ENCLAVE";
	cout<<endl<<endl<<endl<<"               ------------------------------------------------";
	cout<<endl<<endl;
	cout<<"                  ";
	SetConsoleTextAttribute(Color, 4);
	cout<<"SIGN UP";
	cout<<"           ";
	SetConsoleTextAttribute(Color, 2);
	cout<<"LOGIN ";
	SetConsoleTextAttribute(Color, 4);
	cout<<"          RECOVERY"<<endl;
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<"               ------------------------------------------------";
	
	char ch = getch();
	if (ch==77)
	{
		RECOVERY();		
	}
	else if (ch==75)
	{
		SIGNUP();
	}
	else if ( ch==13 )
	{
		recov_opt=0;
		login();
	}
	else if ( ch==27)
	{ 
		Sleep(2000);
		exit(1);
	}
	else
	LOGIN();
}

void RECOVERY()
{
	system("cls");
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<endl<<endl;
	cout<<"                                ";
	cout<<"SECURE ENCLAVE";
	cout<<endl<<endl<<endl<<"               ------------------------------------------------";
	cout<<endl<<endl;
	cout<<"                  ";
	SetConsoleTextAttribute(Color, 4);
	cout<<"SIGN UP           LOGIN ";
	SetConsoleTextAttribute(Color, 2);
	cout<<"          RECOVERY"<<endl;
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<"               ------------------------------------------------";
	
	char ch = getch();
	if (ch==75)
	{
		LOGIN();
	}
	else if ( ch==13 )
	{
		RECOV_OPT1();
	}
	else if ( ch==27)
	{ 
		Sleep(2000);
		exit(1);
	}
	else
	RECOVERY();
}

void RECOV_OPT1()
{
	system("cls");
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<endl<<endl;
	cout<<"                                ";
	cout<<"SECURE ENCLAVE";
	cout<<endl<<endl<<"               ------------------------------------------------"<<endl<<endl<<endl;
	cout<<"                               ";
	cout<<"RECOVERY OPTIONS";
	cout<<endl<<endl<<endl;
	cout<<"                  ";
	SetConsoleTextAttribute(Color, 2);
	cout<<"RECOVER USERNAME";
	SetConsoleTextAttribute(Color, 4);
	cout<<"         RECOVER PASSSWORD"<<endl;
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<"               ------------------------------------------------";
	
	char ch = getch();
	if (ch==77)
	{
		RECOV_OPT2();
	}
	else if ( ch==13 )
	{
		recov_opt=1;
		login();
	}
	else if ( ch==27)
	{ 
		Sleep(2000);
		exit(1);
	}
	else
	RECOV_OPT1();
}

void RECOV_OPT2()
{
	system("cls");
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<endl<<endl;
	cout<<"                                ";
	cout<<"SECURE ENCLAVE";
	cout<<endl<<endl<<"               ------------------------------------------------"<<endl<<endl<<endl;
	cout<<"                               ";
	cout<<"RECOVERY OPTIONS";
	cout<<endl<<endl<<endl;
	cout<<"                  ";
	SetConsoleTextAttribute(Color, 4);
	cout<<"RECOVER USERNAME";
	SetConsoleTextAttribute(Color, 2);
	cout<<"         RECOVER PASSSWORD"<<endl;
	SetConsoleTextAttribute(Color, 9);
	cout<<endl<<"               ------------------------------------------------";
	
	char ch = getch();
	if (ch==75)
	{
		RECOV_OPT1();
	}
	else if ( ch==13 )
	{
		recov_opt=2;
		login();
	}
	else if ( ch==27)
	{ 
		Sleep(2000);
		exit(1);
	}
	else
	RECOV_OPT2();
}
