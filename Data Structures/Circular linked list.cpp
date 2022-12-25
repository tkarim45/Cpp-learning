//#include<iostream>
//using namespace std;
//
//
//template<class T>
//class node
//{
//    T data;
//    node<T>* next;
//public:
//    node()
//    {
//        data =0;
//        next = nullptr;
//    }
//    node(T data, node<T>* next = nullptr)
//    {
//        this->data = data;
//        this->next = next;
//    }
//    template<class U>friend class CLL;
//};
//
//template<class T>
//class CLL
//{
//    node<T>* tail;
//public:
//    CLL()
//    {
//        tail = nullptr;
//    }
//    void insertAtEnd(T data)
//    {
//        if (tail == nullptr)
//        {
//            tail = new node<T>(data);
//            tail->next = tail;
//        }
//        else
//        {
//            tail->next = new node<T>(data, tail->next);
//            tail = tail->next;
//        }
//    }
//    void insertAtStart(T data)
//    {
//        if (tail == nullptr)
//        {
//            tail = new node<T>(data);
//            tail->next = tail;
//        }
//        else
//        {
//            tail->next = new node<T>(data, tail->next);
//        }
//    }
//    void deleteAtStart()
//    {
//        if(tail == tail->next)
//        {
//            delete tail;
//        }
//        else
//        {
//            node<T>* temp = tail->next;
//            tail->next = tail->next->next;
//            delete temp;
//        }
//    }
//    void deleteAtEnd()
//    {
//        if(tail != nullptr)
//        {
//            if(tail->next != tail)
//            {
//                node<T>* temp = tail->next;
//                while(temp->next != tail)
//                {
//                    temp = temp->next;
//                }
//                temp->next = tail->next;
//                delete tail;
//                tail = temp;
//            }
//            else
//            {
//                delete tail;
//                tail = nullptr;
//            }
//        }
//    }
//    bool IsEmpty()
//    {
//        if(tail == nullptr)
//        {
//            return true;
//        }
//        return false;
//    }
//    void insertAfter (T const v1,T const v2)
//    {
//        node<T>*tmp=tail->next;
//        do
//        {
//            if(tmp->data==v1)
//            {
//                tmp->next=new node<T>(v2,tmp->next);
//            }
//            tmp=tmp->next;
//        }
//        while(tmp != tail);
//        if(tail->data==v1)
//        {
//            this->insertAtStart(v2);
//        }
//    }
//    void DeleteAfter(T const v1)
//    {
//        node<T>* temp = new node<T>(v1);
//        for(temp=tail->next;temp->data!=v1 ; temp=temp->next)
//        {
//
//        }
//        node<T> *temp2=temp->next;
//        temp->next=temp2->next;
//        delete temp2;
//    }
//    void reverse()
//    {
//        if(tail&&tail->next!=tail)
//        {
//            node<T> *temp_head=tail->next;
//            node<T> *temp=tail->next->next;
//            node<T> *temp1;
//            while(temp!=tail)
//            {
//                insertAtStart(temp->data);
//                temp1=temp;
//                temp=temp->next;
//                temp_head->next=temp;
//                delete temp1;
//            }
//            insertAtStart(tail->data);
//            this->deleteAtEnd();
//        }
//    }
//    void ChangeTail()
//    {
//        int n=0;
//        cout<<"please enter the value of N: "<<endl; cin>>n;
//        for(int i=0;i<n;i++)
//        {
//            tail=tail->next;
//        }
//    }
//
//    void print()
//    {
//        node<T>* temp;
//        for(temp = tail->next; temp!= tail; temp = temp->next)
//        {
//            cout<<temp->data<<" ";
//        }
//        cout<<tail->data<<" "<<endl;
//    }
//    ~CLL()
//    {
//        node<T>* temp = tail->next;
//        node<T>* temp1;
//        do
//        {
//            temp1 = temp->next;
//            delete temp;
//            temp = temp1;
//        }
//        while(temp!=tail);
//        delete tail;
//    }
//};
//
//
//
//int main()
//{
//    CLL<int> L1;
//    L1.insertAtStart(7);
//    L1.insertAtStart(9);
//    L1.insertAtEnd(10);
//    L1.insertAtEnd(2);
//    L1.print();
//    L1.insertAfter(2, 1);
//    L1.print();
//    L1.deleteAtStart();
//    L1.deleteAtEnd();
//    L1.DeleteAfter(10);
//    L1.print();
//    L1.reverse();
//    L1.print();
//    cout<<L1.IsEmpty()<<endl;
//    L1.insertAfter(7, 4);
//    L1.print();
////    L1.ChangeTail();
//    return 0;
//}