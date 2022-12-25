//#include <iostream>
//using namespace std;
//
//template<class type>
//class Node
//{
//public:
//    Node()
//    {
//        data = 0;
//        Next = nullptr;
//    };
//    Node(type val, Node<type>*nptr = nullptr)
//    {
//        data = val;
//        Next = nptr;
//    }
//    template<class T>
//    friend class List;
//
//private:
//    type data;
//    Node<type> * Next;
//};
//
//
//template<class type>
//class List
//{
//
//private:
//
//    Node<type> * Head;
//    Node<type> * Tail;
//
//public:
//    List()
//    {
//        Head = nullptr;
//        Tail = nullptr;
//    }
//    void insertAtStart(type val)
//    {
//        Head= new Node<type>(val, Head);
//        if (Tail == nullptr)
//            Tail = Head;
//    }
//    void insertAtEnd(type val)
//    {
//        if (Tail != nullptr)
//        {
//            Tail->Next = new Node<type>(val);
//            Tail = Tail->Next;
//        }
//        else
//            Head = Tail = new Node<type>(val);
//    }
//
//    bool search(type val )
//    {
//        Node<type> * tmp = Head;
//        while (tmp != nullptr && tmp->data != val)
//        {
//            if (tmp->data == val)
//            {
//                return true;
//            }
//            else
//            {
//                return false;
//            }
//            //tmp = tmp->next;
//        }
//        return false;
//    }
//    void print()
//    {
//        Node<type> * tmp;
//        for (tmp = Head; tmp != nullptr; tmp = tmp->Next)
//            cout << tmp->data << " ";
//        cout << endl;
//    }
//    bool isEmpty()
//    {
//        if (Head == 0)
//        {
//            return true;
//        }
//    }
//
//    void deleteAll(type val)
//    {
//
//        Node<type> * temp = Head;
//        Node<type> * deleter;
//        Node<type> * T;
//
//        while (temp->Next != nullptr)
//        {
//            T= temp->Next;
//            if (T->data== val)
//            {
//                deleter = temp->Next;
//                temp->Next= deleter->Next;
//                delete deleter;
//                deleter = nullptr;
//            }
//            temp= temp->Next;
//        }
//    }
//    void DeleteAtStart()
//    {
//
//        if (Head != nullptr)
//        {
//            Node<type> * tmp = Head;
//            if (Head == Tail)
//            {
//                Head = Tail = nullptr;
//            }
//            else
//                Head = Head->Next;
//            delete tmp;
//        }
//    }
//
//    ~List()
//    {
//        Node<type> * temp = Head;
//        while (Head != nullptr)
//        {
//            Head = Head->Next;
//            delete temp;
//            temp = Head;
//        }
//        Tail = nullptr;
//    }
//    void insertBefore(type t , type t2)
//    {
//        Node<type>* temp = Head;
//        while(temp->Next!=nullptr)
//        {
//            if(temp->Next->data==t2)
//            {
//                Node<type>* temp1 = new Node<type>(t, nullptr);
//                temp1->Next = temp->Next;
//                temp->Next = temp1;
//                temp = temp->Next->Next;
//            }
//            else
//                temp = temp->Next;
//        }
//
//    }
//
//
//
//
//
//};
//
//int main()
//{
//    List<int> myList;
//    myList.insertAtStart(2);
//    myList.insertAtStart(6);
//    myList.insertAtStart(7);
//    myList.insertAtEnd(9);
//    myList.insertAtEnd(7);
//    myList.insertAtEnd(8);
//    myList.insertAtStart(9);
//    myList.print();
//    myList.deleteAll(7);
//    myList.print();
//    myList.insertBefore(10, 6);
//    myList.print();
//    cout << "searching for 10 :";
//    cout << ((myList.search(10)) ? "Found " : "Not Found") << endl;
//    cout << "searching for 11 :";
//    cout << ((myList.search(11)) ? "Found " : "Not Found") << endl;
//    myList.DeleteAtStart();
//    myList.print();
//    return 0;
//}