//#include<iostream>
//#include<string>
//using namespace std;
//template<class T>
//class Node
//{
//    T Key;
//    Node<T>* Next;
//    Node<T>* Prev;
//public:
//    Node()
//    {
//        Key = 0;
//        Next = nullptr;
//        Prev = nullptr;
//    }
//    Node(T Key, Node<T>* Prev,  Node<T>* Next )
//    {
//        this->Key = Key;
//        this->Next = Next;
//        this->Prev = Prev;
//    }
//    template<class U>
//    friend class List;
//};
//
//template<class T >
//class List
//{
//    Node<T>* Head;
//    Node<T>* Tail;
//public:
//    List()
//    {
//        Head = new Node<T>("0",nullptr, nullptr);
//        Tail = new Node<T>("0", Head, nullptr);
//        Head->Next = Tail;
//    }
//    void insertAtStart(T Key)
//    {
//        Node<T>* temp = new Node<T>(Key, nullptr, nullptr);
//        if(Head->Next == nullptr)
//        {
//            temp->Next = Tail;
//            Tail->Prev = temp;
//            temp->Prev=Head;
//            Head->Next = temp;
//        }
//        else
//        {
//            temp->Next = Head->Next;
//            temp->Next->Prev = temp;
//            temp->Prev=Head;
//            Head->Next=temp;
//        }
//    }
//    void InsertAtEnd(T Key)
//    {
//        Node<T>* temp = new Node<T>(Key, nullptr, nullptr);
//        if(Head->Next == nullptr)
//        {
//            temp->Next = Tail;
//            Tail->Prev = temp;
//            temp->Prev=Head;
//            Head->Next = temp;
//        }
//        else
//        {
//            temp->Prev = Tail->Prev;
//            temp->Prev->Next = temp;
//            temp->Next=Tail;
//            Tail->Prev=temp;
//
//        }
//    }
//    void print()
//    {
//        Node<T> * tmp;
//        for (tmp = Head->Next; tmp != Tail; tmp = tmp->Next)
//        {
//            cout << tmp->Key << " ";
//        }
//        cout << endl;
//    }
//    bool search(T const v)
//    {
//        Node<T> * tmp;
//        bool flag=false;
//        for (tmp = Head->Next; tmp != Tail; tmp = tmp->Next)
//        {
//            if(v == tmp->Key)
//            {
//                flag = true;
//            }
//        }
//        return flag;
//    }
//    int Size()
//    {
//        int size=-1;
//        Node<T>* temp;
//        for(temp = Head->Next; temp != Tail; temp = temp->Next)
//        {
//            size++;
//        }
//        return size;
//    }
//    void addNodeAfter(Node<T> * ptr, T const v)
//    {
//        Node<T>* temp=new Node<T> (v,nullptr,nullptr);
//        temp->Next=ptr->Next;
//        ptr->Next->Prev=temp;
//        ptr->Next=temp;
//        temp->Prev=ptr;
//    }
//    void insertAtMiddle(T const Key)
//    {
//        int ss =Size();
//        Node<T>* temp = Head->Next;
//        for(int i=0; i<ss/2; i++, temp=temp->Next)
//        {
//
//        }
//        addNodeAfter(temp, Key);
//    }
//
//    ~List()
//    {
//        Node<T> * temp = Head;
//        while (Head != Tail)
//        {
//            Head = Head->Next;
//            delete temp;
//            temp = Head;
//        }
//    }
//
//
//};
//int main()
//{
//    List<string> myList;
//    myList.InsertAtEnd("A");
//    myList.InsertAtEnd("F");
//    myList.insertAtStart("N");
//    myList.insertAtStart("U");
//    myList.insertAtMiddle("T");
//    myList.print();
//    return 0;
//}
