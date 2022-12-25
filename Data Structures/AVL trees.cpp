//#include<iostream>
//using namespace std;
//
//template<typename k,typename v>
//class TNode
//{
//public:
//    k key;
//    v value;
//    k height;
//    TNode<k, v>* leftChild;
//    TNode<k, v>* rightChild;
//    TNode()
//    {
//        this->key = 0;
//        this->value = 0;
//        height = 0;
//        this->leftChild = nullptr;
//        this->rightChild = nullptr;
//    }
//    TNode(k key,v value,TNode<k, v>* leftChild=nullptr, TNode<k, v>* rightChild=nullptr)
//    {
//        this->key = key;
//        this->value = value;
//        height = 0;
//        this->leftChild = leftChild;
//        this->rightChild = rightChild;
//    }
//
//    template<typename g, typename h>
//    friend class BST;
//};
//
//template<typename k, typename v>
//class BST
//{
//protected:
//    TNode<k,v> *root;
//public:
//    BST()
//    {
//        root = nullptr;
//    }
//    v* search(TNode<k, v>* r, k key)
//    {
//        if (r == nullptr)
//        {
//            return nullptr;
//        }
//        else if (r->key == key)
//        {
//            return &r->value;
//        }
//        else if (r->key > key)
//        {
//            return search(r->leftChild, key);
//        }
//        else
//        {
//            return search(r->rightChild, key);
//        }
//    }
//    v* search(k key)
//    {
//        return search(root, key);
//    }
//
//    void insertRec(k key,v value,TNode <k,v>*& node)
//    {
//        if (node == nullptr)
//        {
//            node = new TNode<k,v>(key,value);
//        }
//        else if (node->key > key)
//            insertRec(key,value,node->leftChild);
//
//        else
//            insertRec(key,value, node->rightChild);
//    }
//
//    void insertRec(k key,v value)
//    {
//        insertRec(key,value,root);
//    }
//
//    void Print()
//    {
//        InOrder(root);
//    }
//
//    void InOrder(TNode<k,v>* t)
//    {
//        if (t)
//        {
//            InOrder(t->leftChild);
//            visit(t);
//            InOrder(t->rightChild);
//        }
//    }
//
//    void visit(TNode<k,v>* t)
//    {
//        cout << t->key <<" ";
//    }
//
//    void insert(k key, v value)
//    {
//        TNode<k, v>* node = root;
//        if (node == nullptr)
//        {
//            root= new TNode<k, v>(key, value);
//            return;
//        }
//        while (node != nullptr)
//        {
//            if (node->key > key)
//            {
//                if (node->leftChild)
//                    node = node->leftChild;
//                else
//                {
//                    node->leftChild = new TNode<k, v>(key, value);
//                    return;
//                }
//            }
//            else
//            {
//                if (node->rightChild)
//                    node = node->rightChild;
//                else
//                {
//                    node->rightChild = new TNode<k, v>(key, value);
//                    return;
//                }
//            }
//        }
//    }
//
//    int length(TNode<k, v>* t, int& count)
//    {
//        if (t)
//        {
//            length(t->leftChild, count);
//
//            count++;
//
//            length(t->rightChild, count);
//        }
//        return count;
//    }
//    int length()
//    {
//        int count = 0;
//        return length(root, count);
//    }
//
//    void printAllAncestors(k key)
//    {
//        TNode<k, v>* node = root;
//        if (node != nullptr)
//        {
//            while (node->key != key)
//            {
//                if (node->key > key)
//                {
//                    cout << node->key << " ";
//                    node = node->leftChild;
//                }
//                else
//                {
//                    cout << node->key << " ";
//                    node = node->rightChild;
//                }
//            }
//        }
//    }
//    void deleteR(k d)
//    {
//        deleteR(d, root);
//    }
//    void deleteR(k d, TNode<k, v> *& node)
//    {
//
//        if (node)
//        {
//            if (d > node->key)
//                deleteR(d, node->rightChild);
//            else if (d < node->key)
//                deleteR(d, node->leftChild);
//            else
//                deleteNode(node);
//        }
//    }
//    k getPredecessor(TNode<k, v>*n)
//    {
//        while (n->rightChild != nullptr)
//            n = n->rightChild;
//        return n->key;
//
//    }
//    void deleteNode(TNode <k, v> *& node)
//    {
//
//        TNode <k, v> * temp = node;
//
//        if (node->leftChild == nullptr)
//        {
//            node = node->rightChild;
//            delete temp;
//        }
//        else if(node->rightChild == nullptr)
//        {
//            node = node->leftChild;
//            delete temp;
//        }
//        else
//        {
//            k d = getPredecessor(node->leftChild);
//            node->key = d;
//            deleteR(d, node->leftChild);
//        }
//
//    }
//    template<typename g, typename h>
//    friend class AVL;
//
//};
//
//
//template<typename k, typename v>
//class AVL: public BST<k, v>
//{
//public:
//    AVL()
//    {
//        BST<k, v>();
//    }
//    void Insert(TNode<k, v>* & t, int x)
//    {
//        if (t == nullptr)
//            t = new TNode<k, v>(x, 0, nullptr, nullptr );
//        else if (x < t->key)
//            Insert(t->leftChild, x);
//        else if (t->key < x)
//            Insert(t->rightChild, x);
//
//        balance(t);
//    }
//    void Insert(k data)
//    {
//        Insert(BST<k, v>::root, data);
//    }
//    void balance(TNode<k, v>*& ptr)
//    {
//        if (ptr == nullptr)
//            return;
//        if (height(ptr->leftChild) - height(ptr->rightChild) > 1)
//            if (height(ptr->leftChild->leftChild) >= height(ptr->leftChild->rightChild))
//                rightRotate(ptr);
//            else
//                doubleLeftRightRotation(ptr);
//        else if (height(ptr->rightChild) - height(ptr->leftChild) > 1)
//            if (height(ptr->rightChild->rightChild) >= height(ptr->rightChild->leftChild))
//                leftRotate(ptr);
//            else
//                doubleRightLeftRotation(ptr);
//        ptr->height = max(height(ptr->leftChild), height(ptr->rightChild)) + 1;
//    }
//    void rightRotate(TNode<k, v> *& x)
//    {
//        TNode<k, v> * orphan = x->leftChild->rightChild;
//        TNode<k, v> * y = x->leftChild;
//        y->rightChild = x;
//        x->leftChild = orphan;
//        x->height = height(x); // update nodes'
//        y->height = height(y); // height values
//        x=y;
//    }
//    void leftRotate(TNode<k, v> *& x)
//    {
//        TNode<k, v> * orphan = x->rightChild->leftChild;
//        TNode<k, v> * y = x->rightChild;
//        y->leftChild = x;
//        x->rightChild = orphan;
//        x->height = height(x); // update nodes'
//        y->height = height(y); // height values
//        x=y;
//    }
//    void doubleLeftRightRotation(TNode<k, v>*&X)
//    {
//        leftRotate (X->leftChild );
//        rightRotate(X);
//    }
//    void doubleRightLeftRotation(TNode<k, v>*&X)
//    {
//        rightRotate (X->rightChild);
//        leftRotate(X);
//    }
//    int height()
//    {
//        return height(BST<k, v>::root);
//    }
//    int height(TNode<k, v> *node)
//    {
//        int h = 0;
//        if (node != nullptr)
//        {
//            int l_height = height(node->leftChild);
//            int r_height = height(node->rightChild);
//            int max_height = max(l_height, r_height);
//            h = max_height + 1;
//        }
//        return h;
//    }
//    void inorderPrintKeys()
//    {
//        BST<k, v>::Print();
//    }
//    v* Search(TNode<k, v>* r, k key)
//    {
//        if (r == nullptr)
//        {
//            return nullptr;
//        }
//        else if (r->key == key)
//        {
//            return &r->value;
//        }
//        else if (r->key > key)
//        {
//            return Search(r->leftChild, key);
//        }
//        else
//        {
//            return Search(r->rightChild, key);
//        }
//    }
//    v* Search(k key)
//    {
//        return Search(BST<k, v>::root, key);
//    }
//
//};
//
//int main()
//{
//
//    BST<int, int> tree; //the key and value both are of type int
//    tree.insert(500, 500);
//    tree.insertRec(1000, 1000);
//    tree.insert(1, 1);
//    tree.insert(600, 600);
//    tree.insertRec(700, 700);
//    tree.insert(10, 10);
//    tree.insert(30, 30);
//    tree.insertRec(9000, 9000);
//    tree.insert(50000, 50000);
//    tree.insertRec(20, 20);
//    cout << "Printing keys using iterative inorder traversal: ";
//
//    tree.Print();
//    cout << endl;
//
//
//    cout<< endl << "Tree Length: " << tree.length() << endl << endl;
//
//    int* val = tree.search(1);
//    if (val != nullptr)
//    {
//        cout << "1 found" << endl;
//    }
//
//    val = tree.search(123);
//    if (val == nullptr)
//    {
//        cout << "123 not found" << endl;
//    }
//
//    cout << endl << "Printing the keys of ancestor: "<<" ";
//    tree.printAllAncestors(20);
//    cout<<endl<<endl;
//
//    tree.deleteR(500);
//    tree.Print();
//    cout << endl<<endl;
//
//
//    AVL<int, int> tree1;
//    for (int i = 1; i <= 100; i++)
//        tree1.Insert(i);
//
//    for (int i = -1; i >= -100; i--)
//        tree1.Insert(i);
//
//    for (int i = 150; i > 100; i--)
//        tree1.Insert(i);
//
//    for (int i = -150; i < -100; i++)
//        tree1.Insert(i);
//
//
//    tree1.inorderPrintKeys();
//    cout << endl << endl;
//    cout <<"Tree Height: "<< tree1.height() << endl;
//
//    int* val1 = tree1.Search(-100);
//    if (val1 != nullptr)
//    {
//        cout <<"Key= -100 found"<< endl;
//    }
//
//    val1 = tree1.Search(-151);
//    if (val1 == nullptr)
//    {
//        cout <<"Key= -151 not found"<< endl;
//    }
//}