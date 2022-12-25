//#include<iostream>
//#include<vector>
//#include<assert.h>
//using namespace std;
//
//template<class v>
//class HashItem
//{
//public:
//    int key;
//    v value;
//    HashItem* next;
//    HashItem()
//    {
//        key = 0;
//        next = nullptr;
//    }
//    HashItem(int k, v val)
//    {
//        key = k;
//        value = val;
//        next = nullptr;
//    }
//};
//
//template <class v>
//class HashMap
//{
//    vector<HashItem<v>> hashVector;
//    int currentElements;
//    int capacity;
//public:
//    HashMap()
//    {
//        hashVector.resize(10);
//        capacity = 10;
//        currentElements = 0;
//        for (int i = 0;i < capacity;i++)
//            hashVector.push_back(HashItem<v>());
//    }
//    HashMap(int const cap)
//    {
//        assert(cap > 1);
//        hashVector.resize(cap);
//        currentElements = 0;
//        capacity = cap;
//    }
//    void insert(int const key, v const value)
//    {
//        int x = key % capacity;
//        {
//            if (hashVector[x].next == nullptr)
//                hashVector[x].next = new HashItem<v>(key, value);
//            else
//            {
//                HashItem<v>* temp = hashVector[x].next;
//                while (temp != nullptr)
//                {
//                    if (temp->next == nullptr)
//                    {
//                        temp->next = new HashItem<v>(key, value);
//                        break;
//                    }
//                    temp = temp->next;
//                }
//            }
//        }
//    }
//    bool deleteKey(int const k) const
//    {
//        int x = k % capacity;
//        HashItem<v>* temp = hashVector[x].next;
//        while (temp != nullptr)
//        {
//            if (temp->next->key == k)
//            {
//                HashItem<v>* t = temp->next->next;
//                delete temp->next;
//                temp->next = nullptr;
//                temp->next = t;
//                return true;
//            }
//            temp = temp->next;
//        }
//        return false;
//    }
//    v* get(int const k) const
//    {
//        int x = k % capacity;
//        HashItem<v>* temp = hashVector[x].next;
//        while (temp != nullptr)
//        {
//            if (temp->next->key == k)
//            {
//                HashItem<v>* t = temp->next->next;
//                delete temp->next;
//                temp->next = nullptr;
//                temp->next = t;
//                return temp->next->value;
//            }
//            temp = temp->next;
//        }
//        return nullptr;
//    }
//    void print()
//    {
//        for (int i = 0;i < capacity;i++)
//        {
//            cout << i << ". ";
//            if (hashVector[i].next != nullptr)
//            {
//                HashItem<v>* temp = hashVector[i].next;
//                while (temp != nullptr)
//                {
//                    cout << temp->key << " ";
//                    temp = temp->next;
//                }
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//    ~HashMap()
//    {
//        for(int i = 0; i<hashVector.size();i++)
//        {
//            HashItem<v>* temp = hashVector[i].next;
//            HashItem<v>* prev = hashVector[i].next;
//            while(temp)
//            {
//                prev = temp;
//                temp = temp->next;
//                delete prev;
//            }
//        }
//        std::destroy(hashVector.begin(), hashVector.end());
//    }
//};
//
//int main()
//{
//    HashMap<int> h(11);
//    h.insert(10,2);
//    h.insert(11,2);
//    h.insert(12,2);
//    h.insert(17,2);
//    h.insert(18,2);
//    h.insert(20,2);
//    h.insert(21,2);
//    h.insert(22,2);
//    h.insert(32,2);
//    h.insert(44,2);
//    h.print();
//    h.deleteKey(21);
//    h.print();
//    return 0;
//}