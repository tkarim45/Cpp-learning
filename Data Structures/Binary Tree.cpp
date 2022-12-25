//#include<iostream>
//using namespace std;
//template<class T>
//class Node
//{
//public:
//    T data;
//    Node<T>* left;
//    Node<T>* right;
//    Node()  //default constructor
//    {
//        data = 0;
//        left = nullptr;
//        right = nullptr;
//    }
//    Node(T data = 0, Node<T>* left = nullptr, Node<T>* right = nullptr)   //overloaded constructor
//    {
//        this->data = data;
//        this->left = left;
//        this->right = right;
//    }
//
//    template<class t> friend class BST;
//};
//
//template<class T>
//class BST
//{
//public:
//    Node<T>* root;
//    BST()
//    {
//        root = nullptr;
//    }
//    void InsertR(T data, Node<T>*& node)  //insertion recursively
//    {
//        if(node == nullptr)
//        {
//            node = new Node<T>(data);
//        }
//        else if(node->data > data)
//        {
//            InsertR(data, node->left);
//        }
//        else
//            InsertR(data, node->right);
//
//    }
//    void InsertR(T data) //Wrapper Function
//    {
//        InsertR(data, root);
//    }
//    void print()
//    {
//        Inorder(root);
//    }
//    void Inorder(Node<T>* node)    //Inorder Printing
//    {
//        if(node)
//        {
//            Inorder(node->left);
//            visit(node);
//            Inorder(node->right);
//        }
//    }
//    void visit(Node<T>* node)  //helper function for inorder printing
//    {
//        cout<<node->data<<" ";
//    }
//    void InsertI(const T data)  //insertion iteratively
//    {
//        Node<T> *ptr;
//        Node<T> *ptr_parent;
//
//        if(root == nullptr)
//        {
//            Node<T> *newNode = new Node<T>(data);
//            root = newNode;
//        }
//        else
//        {
//            ptr = root;
//            while(ptr != nullptr)
//            {
//                if(data < ptr->data)
//                {
//                    ptr_parent = ptr;
//                    ptr = ptr -> left;
//                }
//                else
//                {
//                    ptr_parent = ptr;
//                    ptr = ptr -> right;
//                }
//            }
//            Node<T> *newNode = new Node<T>(data);
//            if(data < ptr_parent->data)
//                ptr_parent -> left = newNode;
//            else
//                ptr_parent -> right = newNode;
//        }
//    }
//    BST<T>(const BST<T>& other)   //copy constructor
//    {
//        copy(this->root, other.root);
//
//    }
//    void copy(Node<T>* &copy_to, const Node<T>* copy_from) const  //helper function to copy tree
//    {
//        if(copy_from == nullptr)
//        {
//            copy_to = nullptr;
//        }
//        else
//        {
//            copy_to = new Node<T>(0);
//            copy_to->data = copy_from->data;
//            copy(copy_to->left, copy_from->left);
//            copy(copy_to->right, copy_from->right);
//        }
//    }
//    int getLeafCount(Node<T>* node)    // returns no of leaf nodes
//    {
//        if(node == nullptr)
//            return 0;
//        if(node->left == nullptr && node->right == nullptr)
//            return 1;
//        else
//            return getLeafCount(node->left)+getLeafCount(node->right);
//    }
//    int getLeafCount()  //wrapper function
//    {
//        return getLeafCount(root);
//    }
//    int height(Node<T>* node)   //returns height of current node
//    {
//        if (node == nullptr)
//            return 0;
//        else
//        {
//            int left_height = height(node->left);
//            int right_height = height(node->right);
//
//            if (left_height > right_height)
//            {
//                return (left_height + 1);
//            }
//            else
//            {
//                return (right_height + 1);
//            }
//        }
//    }
//    void printLevelOrder()   //wrapper function
//    {
//        printLevelOrder(root);
//    }
//    void printLevelOrder(Node<T>* root)  //printing nodes level by level
//    {
//        int h = height(root);
//        int i;
//        for (i = 1; i <= h; i++)
//            printCurrentLevel(root, i);
//    }
//    void printCurrentLevel(Node<T>* root, int level)   //helper function to printing nodes level by level
//    {
//        if (root == nullptr)
//            return;
//        if (level == 1)
//            cout << root->data << " ";
//        else if (level > 1)
//        {
//            printCurrentLevel(root->left, level - 1);
//            printCurrentLevel(root->right, level - 1);
//        }
//    }
//    void DestroyRecursive(Node<T>* node)  //deletion of nodes recursively
//    {
//        if (node)
//        {
//            DestroyRecursive(node->left);
//            DestroyRecursive(node->right);
//            delete node;
//        }
//    }
//
//    ~BST()  //destructor
//    {
//        DestroyRecursive(root);
//        cout<<"Destructor Called "<<endl;
//    }
//};
//template<class T>
//bool IsEqual(Node<T>* root1, Node<T>* root2)        //function to check if the trees are equal or not
//{
//    if (root1 == nullptr && root2 == nullptr)
//        return true;
//    else if (root1 != nullptr && root2 == nullptr)
//        return false;
//    else if (root1 == nullptr && root2 != nullptr)
//        return false;
//    else
//    {
//        if (root1->data == root2->data && IsEqual(root1->left, root2->left)&& IsEqual(root1->right, root2->right))
//            return true;
//        else
//            return false;
//    }
//}
//template<class T>
//bool IsEqual(BST<T> B1, BST<T> B2)     //wrapper function
//{
//    return IsEqual(B1.root, B2.root);
//}
//int main()
//{
//    BST<int> B;
//    B.InsertR(69);
//    B.InsertR(250);
//    B.InsertR(8);
//    B.InsertR(67);
//    B.InsertR(96);
//    B.print();
//    cout<<endl;
//
//    BST<int> B1 = B;
//    B1.print();
//    cout<<endl;
//    cout<<"The number of Leafs are: "<<B1.getLeafCount()<<endl;
//    cout << "Level Order traversal of binary tree is: "; B1.printLevelOrder();
//    cout<<endl;
//
//
//    if(IsEqual(B1, B))
//        cout << "Both tree are identical."<<endl;
//    else
//        cout << "Trees are not identical."<<endl;
//
//}