//#include<iostream>
//#include<cmath>
//using namespace std;
//class Term
//{
//    float Coefficient;
//    int Exponent;
//    Term* Next;
//public:
//    friend class Polynomial;
//    Term()                       //Constructor
//    {
//        Exponent = 0;
//        Coefficient = 0;
//        Next = nullptr;
//    }
//    Term(float Coefficient, int Exponent, Term* Next = nullptr)    //Overloaded Constructor
//    {
//        this->Coefficient = Coefficient;
//        this->Exponent = Exponent;
//        this->Next = Next;
//    }
//};
//class Polynomial
//{
//    int Size;
//    Term* Head;
//    Term* Tail;
//public:
//    Polynomial()        //Constructor
//    {
//        Size = 0;
//        Head = Tail = nullptr;
//    }
//    Polynomial(const Polynomial &P)   //Copy Constructor
//    {
//        Tail = P.Tail;
//        this->Size = P.Size;
//        Term* temp1 = P.Head;
//        Term* temp2 = this->Head = new Term;
//            while(temp1 != nullptr)
//            {
//                temp2->Coefficient = temp1->Coefficient;
//                temp2->Exponent = temp1->Exponent;
//
//                if (temp1->Next != nullptr)
//                {
//                    temp2 = temp2->Next = new Term;
//
//                }
//                temp1 = temp1->Next;
//            }
//
//    }
//    static void SortingPolynomial(Polynomial& P)    //Sorting Function which is called in Insert Function
//    {
//        int flag;
//        float flag1;
//        for(Term* temp1=P.Head; temp1 != nullptr; temp1 = temp1->Next)    //Bubble Sort Algorithm
//        {
//            for(Term *temp2 = temp1->Next; temp2 != nullptr; temp2 = temp2->Next)
//            {
//                if(temp1->Exponent < temp2->Exponent)
//                {
//                    flag = temp1->Exponent;
//                    flag1 = temp1->Coefficient;
//                    temp1->Exponent = temp2->Exponent;
//                    temp1->Coefficient = temp2->Coefficient;
//                    temp2->Exponent = flag;
//                    temp2->Coefficient = flag1;
//                }
//            }
//        }
//    }
//    static void Simplification(Polynomial& P)   //Simplification Function which is called in Insert Function
//    {
//        for(Term* temp = P.Head; temp->Next != nullptr; )
//        {
//            if (temp->Exponent == temp->Next->Exponent)
//            {
//                temp->Coefficient = temp->Coefficient + temp->Next->Coefficient;
//                Term* temp1 = temp->Next;
//                temp->Next = temp->Next->Next;
//                delete temp1;
//            }
//            else
//            {
//                temp = temp->Next;
//            }
//        }
//
//    }
//    void Insert()              //Taking Number Of Terms from the User
//    {
//        int size;
//        cout<<"Enter the Number of Terms of Polynomial: "; cin>>size;
//        Size = size;
//        float Coeff;
//        int Expo;
//        for(int i=0; i<size; i++)     //Loop for Making a Single Linked List
//        {
//            a:
//            cout << "Enter Coefficient: "; cin >> Coeff;
//            if(Coeff == 0)
//            {
//                cout<<"Wrong Input. Coefficient can not be Zero "<<endl;
//                goto a;
//            }
//            cout << "Enter Exponent: "; cin >> Expo;
//            if(Expo < 0)
//            {
//                cout<<"Wrong Input. Coefficient can not be Zero "<<endl;
//                goto a;
//            }
//            Head = new Term(Coeff, Expo, Head);
//            if(Tail == nullptr)
//            {
//                Tail = Head;
//            }
//        }
//        Polynomial::SortingPolynomial(*this);   // Called the Sorting Function
//        Polynomial::Simplification(*this);      // Called the Simplification Function
//    }
//    Polynomial* AddPolynomial(float Coeff, int Expo, Polynomial* P)  // Forming a Polynomial by taking Coeff and Expo as Arguments
//    {
//        if (P->Tail != nullptr)       //Inserting Terms at the End of Polynomial
//        {
//            Tail->Next = new Term(Coeff, Expo);
//            Tail = Tail->Next;
//        }
//        else
//        {
//            Head = Tail = new Term(Coeff, Expo);
//        }
//        return P;
//    }
//    Polynomial operator + (Polynomial& p)  // " + " Operator Overloading
//    {
//        Term* a = this->Head;
//        Term* b = p.Head;
//        auto* Result = new Polynomial();
//        while(a != nullptr && b != nullptr)
//        {
//            if(a->Exponent > b->Exponent)
//            {
//                Result->AddPolynomial(a->Coefficient, a->Exponent, Result);
//                a = a->Next;
//            }
//            else if(a->Exponent < b->Exponent)
//            {
//                Result->AddPolynomial(b->Coefficient, b->Exponent, Result);
//                b = b->Next;
//            }
//            else if(a->Exponent == b->Exponent)
//            {
//                Result->AddPolynomial(b->Coefficient + a->Coefficient, b->Exponent, Result);
//                a = a->Next;
//                b = b->Next;
//            }
//        }
//        while(a != nullptr)
//        {
//            Result->AddPolynomial(a->Coefficient, a->Exponent, Result);
//            a = a->Next;
//        }
//        while(b != nullptr)
//        {
//            Result->AddPolynomial(b->Coefficient, b->Exponent, Result);
//            b = b->Next;
//        }
//        return *Result;
//    }
//    Polynomial operator * (Polynomial& p)   // " * " Operator Overloading
//    {
//        float Coeff;
//        int Expo;
//        Term* a = this->Head;
//        Term* b = p.Head;
//        auto* Result = new Polynomial();
//        if(a == nullptr && b == nullptr)
//        {
//            return *Result;
//        }
//        else if(a == nullptr)
//        {
//            return p;
//        }
//        else if(b== nullptr)
//        {
//            return *this;
//        }
//        else
//        {
//            while (a != nullptr)
//            {
//                while (b != nullptr)
//                {
//                    Coeff = a->Coefficient * b->Coefficient;
//                    Expo = a->Exponent + b->Exponent;
//                    Result->AddPolynomial(Coeff, Expo, Result);
//                    b = b->Next;
//                }
//                b = p.Head;
//                a = a->Next;
//            }
//        }
//        SortingPolynomial(*Result);
//        Simplification(*Result);
//        return *Result;
//    }
//    double Evaluation()   //Evaluating the Value n and returning the result
//    {
//        double num, x, sum=0;
//        cout<<"Enter the Value of n: "; cin>>num;
//        Term* temp;
//        for(temp = Head; temp != nullptr; temp = temp->Next)
//        {
//            x = pow(num, temp->Exponent);
//            sum = sum + (temp->Coefficient * x);
//        }
//        return sum;
//    }
//    void Print()   //Print function to Output the Terms in Polynomial
//    {
//        Term* temp;
//        int i;
//        char sign = '+';
//        for(temp=Head, i=0; temp != nullptr; temp = temp->Next,i++)
//        {
//            if(i == 0 )   //Doesn't Print the Plus sign for the first term of the Polynomial
//            {
//                cout << temp->Coefficient << "n^" << temp->Exponent;
//            }
//            else if(temp->Coefficient > 0 && temp->Exponent > 0)
//            {
//                cout << sign << temp->Coefficient << "n^" << temp->Exponent;
//            }
//            else if(temp->Coefficient < 0 && temp->Exponent > 0)
//            {
//                cout << temp->Coefficient << "n^" << temp->Exponent;
//            }
//            else if(temp->Exponent <= 0)
//            {
//                cout << sign << temp->Coefficient;
//            }
//        }
//        cout<<endl;
//    }
//    ~Polynomial()   //Destructor
//    {
//        Term * temp = Head;
//        while (temp != nullptr)
//        {
//            Head = temp->Next;
//            delete temp;
//            temp = Head;
//        }
//        Tail = nullptr;
//    }
//};
//int main()
//{
//    Polynomial P1;
//    P1.Insert();
//    cout<<"Enter Polynomial: ";
//    P1.Print();
//    Polynomial P2;
//    P2.Insert();
//    cout<<"Enter Polynomial: ";
//    P2.Print();
//    Polynomial P3(P1 + P2);
//    cout<<"The Addition of Polynomial is: ";
//    P3.Print();
//    Polynomial P4(P1 * P2);
//    cout<<"The Multiplication of Polynomial is: ";
//    P4.Print();
//    double Eval = P4.Evaluation();
//    cout<<"Evaluated Polynomial "<<Eval<<endl;
//}