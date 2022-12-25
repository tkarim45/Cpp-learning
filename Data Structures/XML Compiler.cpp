// #include<iostream>
// #include<string>
// #include<fstream>
// using namespace std;
// template <class t >
// class node
// {
// public:
//    node<t>*next;
//    t data;
//    node()
//    {
//        data=0;
//        next=nullptr;
//    }
//    node(t data , node<t>*next)
//    {
//        this->data=data;
//        this->next=next;
//    }
//    template<class U>
//    friend class linkedlist;
// };
// 
// template<class t>
// class linkedlist
// {
//    node<t>*head;
// public:
//    linkedlist()
//    {
//        head = nullptr;
//    }
//    void insertAtStart(t val)     //Function to Insert Data in Stack
//    {
//        node<t> *temp;
//        temp = new node<t>(val, nullptr);
//        if(head==nullptr)
//        {
//            head=temp;
//        }
//        else
//        {
//            temp->next=head;
//            head=temp;
//        }
//    }
//    bool isempty()   //Function to Check if the stack is empty or not
//    {
//        if (head == nullptr)
//        {
//            return true;
//        }
//        else
//            return false;
//    }
//    void DeleteAtStart()  //Function to delete the top most value in the stack
//    {
//        if (head != nullptr)
//        {
//            node<t>* tmp = head;
//            head = head->next;
//            delete tmp;
//        }
//    }
//    template<class U>
//    friend class Stack;
// };
// 
// template<class t>
// class Stack
// {
//    linkedlist<t>*temp;
// public:
//    Stack()     //Constructor
//    {
//        temp = new linkedlist<t>();
//    }
//    bool push(t c)  //Function to Push Values in Stack
//    {
//        temp->insertAtStart(c);   //Insert Function is Called
//        return true;
//    }
//    bool pop()  //Function to Pop Values from the top of the Stack
//    {
//        temp->DeleteAtStart();  //Delete Function is Called
//        return true;
//    }
//    bool isEmpty()  //Function if the Stack is Empty or not
//    {
//        if(!temp->isempty())
//        {
//            return true;
//        }
//        return false;
//    }
//    t top()  //Function to Return the Top most value in the stack
//    {
//        if(!temp->isempty())
//        {
//            return temp->head->data;
//        }
//        else
//            return 0;
//    }
// };
// int main()
// {
//    ifstream file("/Users/taimourabdulkarim/Documents/Clion/data1.txt");
//    string e;       //Storing Data line by line from the file in string e
//    int line = 1;   //Increment line to show on which line error occurred
//    Stack<char> st;
//    while (std::getline(file, e)) //loop to read data from file line by line
//    {
//        char flag;          //Variable to Store the Value On the top of the stack
//        int z = 0;          //Variable to check it doesn't print same error twice
//        int count_Quotation_1 = 0;  //check to count the number of quotations ""
//        int count_Quotation_2 = 0;  //check to count the number of quotations ''
//        int space = 0;              //check to count the space between name and attribute name
//        int n=int(e.size());        //Storing Size of string in n
//        bool check = false;         //Bool to end the main loop if error, if found on the line
//        for(int i=0; i <= n && !check; i++)  //loop to check the error on a single line
//        {
//            if(line == 1) //Condition will only run for the first line to check Prolong header
//            {
//                if (e[i] == '<')  //Condition if Opening Bracket '<' is Found then check if the next char is ? or not
//                {
//                    if(e[i + 1] == '?') //Checking if the Next Char is ? if yes then push ? in the stack if not then show error
//                    {
//                        st.push(e[i+1]);
//                    }
//                    else
//                    {
//                        goto b; //Goes to where the condition is to end the loop and read the next line
//                    }
//                }
//                else if (e[i] == '?')  //Checking the end of Prolong Header. If ? is found first then check whether the next char is closing bracket or not
//                {
//                    if(e[i + 1] == '>')  //If the next bracket is closing then pop the ? from the stack
//                    {
//                        flag = st.top();
//                        if (flag == e[i])  //Checking the top value of the stack
//                        {
//                            st.pop();
//                        }
//                        else   //if ? doesn't exist then end the loop and read the next line
//                        {
//                            goto b;
//                        }
//                    }
//                }
//                else if (e[i] == '>')  //Check if closing bracket is obtained first then check the previous char if ? exist or not
//                {
//                    if(e[i - 1] == '?'){} // If exist then do nothing
// 
//                    else //else show error and end the loop and move to the next line
//                    {
//                        goto b;
//                    }
//                }
//                else if(e[i] == '"') //Checking whether no. of Quotations are equal or not ""
//                {
//                    count_Quotation_1++;
//                }
//                else if(e[i] == 39) //Checking whether no. of Quotations are equal or not ''
//                {
//                    count_Quotation_2++;
//                }
//                else if (e[i] == '\0' && count_Quotation_1%2 == 0 && count_Quotation_2%2 == 0)  //Check at the end of line if Quotations marks are equal or not
//                {
//                    if(e[i-1] == '>' && e[i-2] == '?') //checking if closing bracket and ? exists before the end of line
//                    {
//                        line++;
//                    }
//                    else //If not then show error and end the loop and start reading the next line
//                    {
//                        b:
//                        cout<<"Error. Invalid Prolong Header on line: "<<line<<endl;
//                        line++;
//                        check = true;
//                    }
//                }
//                else if (e[i] == '\0' && count_Quotation_1%2 != 0 && count_Quotation_2%2 != 0) //Check at the end of line if Quotations marks are equal or not
//                {
//                    cout<<"Error. Quotation Mark not Set Properly on line: "<<line<<endl; //If not then show error and end the loop and start reading the next line
//                    line++;
//                    check = true;
//                }
//                else if (e[i] == '\0' && (count_Quotation_1%2 != 0 || count_Quotation_2%2 != 0)) //Check at the end of line if Quotations marks are equal or not
//                {
//                    cout<<"Error. Mis-Matched Quotation Mark on line: "<<line<<endl; //If not then show error and end the loop and start reading the next line
//                    line++;
//                    check = true;
//                }
// 
//            }
//            else  //Condition to check the rest of the lines
//            {
//                if (e[i] == '<')  //Checking if opening bracket is obtained if Yes then
//                {
//                    if(e[i+1] != '/') //Check if the next char is / or not. If it is not / then
//                    {
//                        //start pushing the name in the stack until closing bracket or space is not obtained
//                        int j = i+1;           //reading the name which is starts from i+1
//                        bool check1 = false;   //check to end the loop if opening bracket of / is obtained
//                        bool check2 = false;    //check to stop pushing values in stack is space is obtained
//                        while(e[j] != '>'  && !check1)  //loop will run until closing bracket is not found or opening bracket or / is found then show error
//                        {
//                            if(e[j] == 32) //check to see if space is found
//                            {
//                                check2 = true;
//                            }
//                            else if(e[j] == '<' || e[j] =='/') //check to see if opening bracket of / is found if yes then throw error
//                            {
//                                cout<<"Error. Invalid Tag on line: "<<line<<endl;
//                                line++;
//                                check1 = true;
//                                check = true;  //ends the loop and start reading the next line
//                            }
//                            else if(e[j] != 32 && !check2) //Condition to push values in stack until space is found
//                            {
//                                st.push(e[j]);
//                            }
//                            j++;
//                        }
//                    }
//                    else if(e[i+1] == '/') //Condition if / is found after opening bracket then start reading from the end of the line
//                    {
//                        int j = int(e.size()-2); //reading data from the end of line
//                        while(e[j] != '<')         //loop will run until opening bracket is not found
//                        {
//                            flag = st.top();  //comparing the top values from the stack. If equal then pop the name
//                            if (flag == e[j])
//                            {
//                                st.pop();
//                            }
//                            j--;
//                        }
//                    }
//                }
//                else if(e[i] == '>')  //If closing bracket is found then check whether opening bracket exists at the start of not
//                {
//                    int j = 0;
//                    if(e[j] != '<') //If not then move to next line and throw error;
//                    {
//                        goto a;
//                    }
//                    else  //If true then start reading data from the end of line
//                    {
//                        int k = int(e.size()-2);
//                        while(e[k] != '<')  //loop will run until opening bracket is found
//                        {
//                            if(e[k] == '>' || e[j] =='/')  //If closing bracket or / is found then throw error and move to next line
//                            {
//                                goto a;
//                            }
//                            k--;
//                        }
//                    }
//                }
//                else if(e[i] == '"')  //Counting Number of Quotations
//                {
//                    count_Quotation_1++;
//                    int j = i;
//                    bool check1 = false;
//                    while(e[j] != '<' && !check1) //checking if space exists between name and heading
//                    {
//                        if(e[j] == 32)
//                        {
//                            space++;
//                            check1 = true;
//                        }
//                        j--;
//                    }
//                    if(space == 0 && z == 0)  //checking if space exists between name and heading
//                    {
//                        cout<<"Error. name and Attribute name not defined properly on line: "<<line<<endl;
//                        z++;
//                    }
//                }
//                else if(e[i] == 39)  //Counting Number of Quotations
//                {
//                    count_Quotation_2++;
//                    int j = i;
//                    bool check1 = false;
//                    while(e[j] != '<' && !check1) //checking if space exists between name and heading
//                    {
//                        if(e[j] == 32)
//                        {
//                            space++;
//                            check1 = true;
//                        }
//                        j--;
//                    }
//                    if(space == 0 && z == 0) //checking if space exists between name and heading
//                    {
//                        cout<<"Error. name and Attribute name not defined properly on line: "<<line<<endl;
//                        z++;
//                    }
//                }
//                else if(e[i] == '\0' && count_Quotation_1%2 == 0 && count_Quotation_2%2 == 0) // check if the Quotation Marks are equal or not
//                {
//                    if(e[i-1] == '>') //Check if closing bracket exists before the end of line
//                    {
//                        line++;
//                    }
//                    else  //If not then throw error
//                    {
//                        a:
//                        cout<<"Error. Invalid Tag on line: "<<line<<endl;
//                        line++;
//                        check = true;
//                    }
//                }
//                else if (e[i] == '\0' && count_Quotation_1%2 != 0 && count_Quotation_2%2 != 0) // check if the Quotation Marks are equal or not
//                {
//                    cout<<"Error. Quotation Mark not Set Properly on line: "<<line<<endl;
//                    line++;
//                    check = true;
//                }
//                else if (e[i] == '\0' && (count_Quotation_1%2 != 0 || count_Quotation_2%2 != 0)) // check if the Quotation Marks are equal or not
//                {
//                    cout<<"Error. Mis-Matched Quotation Mark on line: "<<line<<endl;
//                    line++;
//                    check = true;
//                }
//            }
//        }
//    }
//    if(st.isEmpty())  //check if the stack is empty or not if not then throw error
//    {
//        cout<<"Error. / not set properly "<<endl;
//    }
// }