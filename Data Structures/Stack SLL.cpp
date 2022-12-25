//#include<iostream>
//using namespace std;
//
//class StackNode
//{
//public:
//    int data;
//    StackNode *next;
//    StackNode()
//    {
//        this->data = 0;
//        this->next = nullptr;
//    }
//    StackNode(int data, StackNode *next = nullptr)
//    {
//        this->data = data;
//        this->next = next;
//    }
//    friend class Stack;
//};
//class Stack
//{
//    StackNode *top;
//public:
//    void push(int data)
//    {
//        if (top == nullptr)
//        {
//            top = new StackNode(data);
//            return;
//        }
//        StackNode *s = new StackNode(data);
//        s->next = top;
//        top = s;
//    }
//    StackNode* pop()
//    {
//        StackNode *s = top;
//        top = top->next;
//        return s;
//    }
//    void display()
//    {
//        StackNode *s = top;
//        while (s != nullptr)
//        {
//            cout << s->data << " ";
//            s = s->next;
//        }
//        cout << endl;
//    }
//    void reverse()
//    {
//        StackNode *prev, *cur, *succ;
//        cur = prev = top;
//        cur = cur->next;
//        prev->next = nullptr;
//        while (cur != nullptr)
//        {
//            succ = cur->next;
//            cur->next = prev;
//            prev = cur;
//            cur = succ;
//        }
//        top = prev;
//    }
//};
//int main()
//{
//    Stack *s = new Stack();
//    s->push(1);
//    s->push(2);
//    s->push(3);
//    s->push(4);
//    s->push(5);
//    s->push(6);
//    s->push(7);
//    s->push(8);
//    s->push(9);
//
//    cout << "Original Stack" << endl;;
//    s->display();
//    cout << endl;
//
//    s->reverse();
//
//    cout << "Reversed Stack" << endl;
//    s->display();
//}
