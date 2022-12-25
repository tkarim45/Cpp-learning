#include<iostream>
#include<windows.h>
using namespace std;
void countword(char arr[])
{
	system("cls");
	int word=0;
    for (int i=0;arr[i]!='\0';i++)
    {
        if (arr[i]==' ')
        word++;    
    }
    cout << "Number of Words are: "<<word+1<<endl;
}
void countalphabets(char arr[])
{
	system("cls");
	int alphabets=0;
    for (int i=0;arr[i]!='\0';i++)
    {
        if ((arr[i]>='a' && arr[i]<='z') || (arr[i]>='A' && arr[i]<='Z'))
        alphabets++;    
    }
    cout << "Number of Alphabets are: "<<alphabets<<endl;
}
void countsentence(char arr[])
{
	system("cls");
	int sentence=0;
    for (int i=0;arr[i]!='\0';i++)
    {
        if (arr[i]=='.')
        sentence++;    
    }
    cout << "Number of Sentences are: "<<sentence<<endl;
}
void countfreqvowel(char arr[])
{
	system("cls");
	int va=0,ve=0,vi=0,vo=0,vu=0,vA=0,vE=0,vI=0,vO=0,vU=0;
	for (int i=0;arr[i]!='\0';i++)
    {
    	if(arr[i]=='a')	     { va++;  }
		else if(arr[i]=='e') { ve++;  }
		else if(arr[i]=='i') { vi++;  }  
		else if(arr[i]=='o') { vo++;  }
		else if(arr[i]=='u') { vu++;  }
		else if(arr[i]=='A') { vA++;  }
		else if(arr[i]=='E') { vE++;  }
		else if(arr[i]=='I') { vI++;  }
		else if(arr[i]=='O') { vO++;  }
		else if(arr[i]=='U') { vU++;  }	
	}
	cout << "Fequency of Vowel a is: "<<va<<endl;
	cout << "Fequency of Vowel e is: "<<ve<<endl;
	cout << "Fequency of Vowel i is: "<<vi<<endl;
	cout << "Fequency of Vowel o is: "<<vo<<endl;
	cout << "Fequency of Vowel u is: "<<vu<<endl;
	cout << "Fequency of Vowel A is: "<<vA<<endl;
	cout << "Fequency of Vowel E is: "<<vE<<endl;
	cout << "Fequency of Vowel I is: "<<vI<<endl;
	cout << "Fequency of Vowel O is: "<<vO<<endl;
	cout << "Fequency of Vowel U is: "<<vU<<endl;	
}
void countfreqcomp(char arr[])
{
	system("cls");
	int comp=0;
    for (int i=0;arr[i]!='\0';i++)
    {
        if (arr[i]=='c' && arr[i+1]=='o' && arr[i+2]=='m' && arr[i+3]=='p' && arr[i+4]=='u' && arr[i+5]=='t' && arr[i+6]=='e' && arr[i+7]=='r')
        comp++;    
    }
    cout << "Frequency of Word 'computer' is : "<<comp<<endl;
}
int main()
{
    char arr[] = "computer science (sometimes called computation science or computing science, but not to be confused with computational science or software engineering) is the study of processes that interact with data and that can be represented as data in the form of programs.It enables the use of algorithms to manipulate, store, and communicate digital information. A computer scientist studies the theory of computationand the practice of designing software systems. Its fields can be divided into theoreticaland practical disciplines. Computational complexity theory is highly abstract, while computer graphics emphasizes real-world applications. Programming language theory considers approaches to the description of computational processes, while computer programming itself involves the use of programming languagesand complex systems. Human–computer interaction considers the challenges in making computers useful, usable, and accessible.";
    
    int choice;
    do
    {
    	cout<<"1. Count Number of Words\n";
        cout<<"2. Count Number of Alphabets\n";
        cout<<"3. Count Number of Sentences\n";
        cout<<"4. Count Frequency of each Vowel\n";
        cout<<"5. Count Frequency of Word 'computer'\n";
        cout<<"6. Exit\n\n";
        cout<<"Enter your choice: "; cin>>choice;
        cout<<endl;
        
        switch(choice)
        {
            case 1:
                countword(arr);
                Sleep(2000);
                system("cls");
                break;
            case 2:
                countalphabets(arr);
                Sleep(2000);
                system("cls");
                break;
            case 3:
                countsentence(arr);
                Sleep(2000);
                system("cls");
             	break;
            case 4:
  		        countfreqvowel(arr);
  		        Sleep(5000);
                system("cls");
		     	break;
		    case 5:
		    	countfreqcomp(arr);
		    	Sleep(2000);
                system("cls");
		    	break;
        }     
	}while(choice!=6);  
   return 0;
}
