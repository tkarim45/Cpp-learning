//#include <iostream>
//#include <string>
//using namespace std;
//
//template <class T>
//class queue
//{
//    T *arr;
//    int capacity;
//    int front;
//    int rear;
//    int count;
//    static const int SIZE = 10;
//public:
//    queue(int size = SIZE)
//    {
//        arr = new T[size];
//        capacity = size;
//        front = 0;
//        rear = -1;
//        count = 0;
//    }
//    void dequeue()
//    {
//        if (isEmpty())
//        {
//            cout << "Underflow\nProgram Terminated\n";
//            exit(-1);
//        }
//        front = (front + 1) % capacity;
//        count--;
//    }
//    void enqueue(T x)
//    {
//        if (isFull())
//        {
//            cout << "Overflow\nProgram Terminated\n";
//            exit(-1);
//        }
//        rear = (rear + 1) % capacity;
//        arr[rear] = x;
//        count++;
//    }
//    T Front()
//    {
//        if (isEmpty())
//        {
//            cout << "UnderFlow\nProgram Terminated\n";
//            exit(-1);
//        }
//        return arr[front];
//    }
//    int size()
//    {
//        return count;
//    }
//    bool isEmpty()
//    {
//        return (size() == 0);
//    }
//    bool isFull()
//    {
//        return (size() == capacity);
//    }
//};
//int main()
//{
//    queue<string> q(4);
//
//    q.enqueue("a");
//    q.enqueue("b");
//    q.enqueue("c");
//    cout << "The front element is " << q.Front() << endl;
//    q.dequeue();
//    q.enqueue("d");
//    cout << "The queue size is " << q.size() << endl;
//    q.dequeue();
//    q.dequeue();
//    q.dequeue();
//    if (q.isEmpty())
//    {
//        cout << "The queue is empty\n";
//    }
//    else
//    {
//        cout << "The queue is not empty\n";
//    }
//
//}