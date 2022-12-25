//#include<iostream>
//using namespace std;
//
//class PatientRecord
//{
//    int patient_id;
//    string patient_name;
//    string admission_date;
//    string disease_diagnosis;
//    string status;
//public:
//
//    PatientRecord()         //default constructor
//    {
//        patient_id = 0;
//        patient_name = "";
//        admission_date = "";
//        disease_diagnosis = "";
//        status = "";
//    }
//    PatientRecord(int patient_id, string patient_name, string admission_date, string disease_diagnosis, string status)     //Overloaded Constructor
//    {
//        this->patient_id = patient_id;
//        this->patient_name = patient_name;
//        this->admission_date = admission_date;
//        this->disease_diagnosis = disease_diagnosis;
//        this->status = status;
//    }
//    friend class TNode;
//    friend class HospitalData;
//};
//
//class TNode
//{
//    PatientRecord Patient_obj;
//    TNode* left_child;
//    TNode* right_child;
//public:
//    //default constructor
//    TNode():Patient_obj(0, "", "", "", "")
//    {
//        left_child = nullptr;
//        right_child = nullptr;
//    }
//    //Overloaded Constructor
//    TNode(int patient_id, string patient_name, string admission_date, string disease_diagnosis, string status, TNode* left_child = nullptr, TNode* right_child = nullptr)
//            :Patient_obj(patient_id, patient_name, admission_date, disease_diagnosis, status)
//    {
//        this->left_child = left_child;
//        this->right_child = right_child;
//    }
//    friend class HospitalData;
//};
//class HospitalData
//{
//    TNode* root;
//    int size;
//public:
//    HospitalData()  //default constructor
//    {
//        root = nullptr;
//        size = 0;
//    }
//    void Insert(int patient_id, string patient_name, string admission_date, string disease_diagnosis, string status)    //wrapper function for insert
//    {
//        Insert(patient_id, patient_name, admission_date, disease_diagnosis, status, root);
//    }
//    void Insert(int patient_id, string patient_name, string admission_date, string disease_diagnosis, string status, TNode*& node)  //Inserting data of new patient
//    {
//        if(node == nullptr)
//        {
//            node = new TNode(patient_id, patient_name, admission_date, disease_diagnosis, status);
//            size++;
//        }
//        else if(node->Patient_obj.patient_id == patient_id)     //check if the patient already exists
//        {
//            cout<<"Patient Already Exits "<<endl<<endl;
//            search(patient_id, 0);
//        }
//        else if(node->Patient_obj.patient_id < patient_id)
//        {
//            Insert(patient_id, patient_name, admission_date, disease_diagnosis, status, node->right_child);
//            if(get_level(patient_id) != 0)
//                leftRotate(node);       //rotating new patient to the root
//        }
//        else
//        {
//            Insert(patient_id, patient_name, admission_date, disease_diagnosis, status, node->left_child);
//            if(get_level(patient_id) != 0)
//                rightRotate(node);      //rotating new patient to the root
//        }
//    }
//    void rightRotate(TNode*& x)     //rotation function for node
//    {
//        TNode* orphan = x->left_child->right_child;
//        TNode* y = x->left_child;
//        y->right_child = x;
//        x->left_child = orphan;
//        x=y;
//    }
//    void leftRotate(TNode*& x)      //rotation function for node
//    {
//        TNode* orphan = x->right_child->left_child;
//        TNode* y = x->right_child;
//        y->left_child = x;
//        x->right_child = orphan;
//        x=y;
//    }
//    int get_level(int patient_id)       //wrapper function for get_level
//    {
//        return get_level(root, patient_id);
//    }
//    int get_level(TNode* node, int patient_id)      //wrapper function for get_level
//    {
//        return get_level(node, patient_id, 0);
//    }
//    int get_level(TNode* node, int patient_id, int level)     //function to return the level of the node
//    {
//        if (node == nullptr)
//            return 0;
//        if (node->Patient_obj.patient_id == patient_id)
//            return level;
//        int downlevel = get_level(node ->left_child, patient_id, level + 1);
//        if (downlevel != 0)
//            return downlevel;
//        downlevel = get_level(node->right_child, patient_id, level + 1);
//        return downlevel;
//    }
//    void search(int patient_id, int level_k)        //wrapper function for search
//    {
//        search(root, patient_id, level_k);
//    }
//    void search(TNode*& node, int patient_id,  int level_k)     //function to rotate the existing patient to level k
//    {
//        TNode* temp = searchroot(root, patient_id);
//        int level_of_node = get_level(patient_id);
//        int no_of_rotations = level_of_node - level_k;
//        if(node == nullptr)
//            return;
//        else
//        {
//            if(level_k > level_of_node)         //check if the level k is greater than the level of the node
//            {
//                cout<<"No Rotations "<<endl<<endl;
//                return;
//            }
//            else            //if not then move to root to level k
//            {
//                move_to_root(no_of_rotations, patient_id);
//            }
//        }
//    }
//    TNode* searchroot(TNode*& node, int patient_id)     //function to check if the patient already exists in the tree
//    {
//        if(node)
//        {
//            if(node->Patient_obj.patient_id == patient_id)
//                return node;
//            else if(node->Patient_obj.patient_id > patient_id)
//                return searchroot(node->left_child, patient_id);
//            else
//                return searchroot(node->right_child, patient_id);
//        }
//    }
//    void move_to_root(int& no_of_rotations, int Patient_id)     //wrapper function for move_to_root
//    {
//        move_to_root(root, no_of_rotations, Patient_id);
//    }
//    void move_to_root(TNode*& node, int& no_of_rotations, int patient_id) //function to rotate the found patient to level k
//    {
//        if(node)
//        {
//            if (node->Patient_obj.patient_id == patient_id)
//                return;
//            else if(node->Patient_obj.patient_id < patient_id)
//            {
//                move_to_root(node->right_child, no_of_rotations, patient_id);
//                if(no_of_rotations != 0)
//                {
//                    leftRotate(node);
//                    no_of_rotations--;
//                }
//            }
//            else
//            {
//                move_to_root(node->left_child, no_of_rotations, patient_id);
//                if(no_of_rotations != 0)
//                {
//                    rightRotate(node);
//                    no_of_rotations--;
//                }
//            }
//        }
//        return;
//    }
//    TNode* findMaximumKey(TNode* ptr)       //function to return predecessor
//    {
//        while (ptr->right_child != nullptr)
//        {
//            ptr = ptr->right_child;
//        }
//        return ptr;
//    }
//    void Remove(int patient_id)     //wrapper function for remove
//    {
//        Remove(root, patient_id);
//        size--;
//    }
//    void Remove(TNode*& node, int patient_id)       //function to remove a patient with the given id
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        if (patient_id < node->Patient_obj.patient_id)
//        {
//            Remove(node->left_child, patient_id);
//        }
//        else if (patient_id > node->Patient_obj.patient_id)
//        {
//            Remove(node->right_child, patient_id);
//        }
//        else
//        {
//            if (node->left_child == nullptr && node->right_child == nullptr)
//            {
//                delete node;
//                node = nullptr;
//            }
//            else if (node->left_child && node->right_child)
//            {
//                TNode* predecessor = findMaximumKey(node->left_child);
//                node->Patient_obj.patient_id = predecessor->Patient_obj.patient_id;
//                Remove(node->left_child, predecessor->Patient_obj.patient_id);
//            }
//            else
//            {
//                TNode* child;
//                if(node->left_child)
//                {
//                    child = node->left_child;
//                }
//                else
//                    child = node->right_child;
//
//                TNode* curr = node;
//                node = child;
//                delete curr;
//            }
//        }
//    }
//
//    void BSTtoArray(TNode *root, TNode* A[])    //function to convert bst into an array
//    {
//        static int pos = 0;
//        if(root == nullptr)
//            return;
//
//        BSTtoArray(root->left_child, A);
//        A[pos++] = root;
//        BSTtoArray(root->right_child, A);
//    }
//    TNode* split()      //function to split the tree with its median
//    {
//        TNode* temp[size];
//        BSTtoArray(root, temp);
//        search(temp[(size-1)/2]->Patient_obj.patient_id, 0);
//    }
//    void get_root()     //helper function to check the id at root
//    {
//        cout<<"Root: "<<root->Patient_obj.patient_id<<endl<<endl;
//    }
//    void PrintAll() //helper function to check if all the patient have been inserted in the tree
//    {
//        Inorder(root);
//    }
//    void Inorder(TNode* node) //printing data of patient in inorder
//    {
//        if(node)
//        {
//            Inorder(node->left_child);
//            visit(node->Patient_obj);
//            Inorder(node->right_child);
//        }
//    }
//    void visit(PatientRecord const& node)       //helper function for inorder to print patient data
//    {
//        cout<<"Patient ID: "<<node.patient_id<<endl;
//        cout<<"Patient Name: "<<node.patient_name<<endl;
//        cout<<"Patient Admission date: "<<node.admission_date<<endl;
//        cout<<"Patient Diseased Diagnosis: "<<node.disease_diagnosis<<endl;
//        cout<<"Patient Status: "<<node.status<<" "<<endl<<endl;
//    }
//    void PrintAdmitted()    //wrapper function for print admitted
//    {
//        PrintAdmitted(root);
//    }
//    void PrintAdmitted(TNode* node)     //function to print only those patients who are admitted
//    {
//        if(node)
//        {
//            PrintAdmitted(node->left_child);
//            if(node->Patient_obj.status == "admitted")
//                visit(node->Patient_obj);
//            PrintAdmitted(node->right_child);
//        }
//    }
//    bool Print(int patient_id)      //wrapper function for print
//    {
//        bool flag;
//        return Print(root, patient_id, flag);
//    }
//    bool Print(TNode* node, int patient_id, bool& flag)  //wrapper function to print the patient with the specific id
//    {
//        if(node)
//        {
//            Print(node->left_child, patient_id, flag);
//            if(node->Patient_obj.patient_id == patient_id)
//            {
//                visit(node->Patient_obj);
//                flag = true;
//            }
//            Print(node->right_child, patient_id, flag);
//        }
//        return flag;
//    }
//    void DestroyRecursive(TNode* node) //function to delete every node in tree
//    {
//        if (node)
//        {
//            DestroyRecursive(node->left_child);
//            DestroyRecursive(node->right_child);
//            delete node;
//        }
//    }
//    ~HospitalData() //destructor
//    {
//        DestroyRecursive(root);
//    }
//};
//int main()
//{
//    HospitalData H;
//    H.Insert(22, "Mohib", "12-05-2019", "flu", "not admitted");
//    H.Insert(1, "Taimour", "13-03-2021", "cold", "admitted");
//    H.Insert(4, "Minal", "14-05-2019", "flu", "not admitted");
//    H.Insert(3, "Mano", "15-05-2020", "Headache", "admitted");
//    H.Insert(10, "usmar", "16-03-2021", "cold", "admitted");
//    H.Insert(31, "mansoor", "17-05-2020", "Headache", "admitted");
//    H.Insert(7, "haider", "21-03-2021", "cold", "admitted");
//    H.Insert(12, "maryam", "27-05-2019", "flu", "not admitted");
//    H.Insert(32, "Aimen", "12-05-2020", "Headache", "admitted");
//    H.PrintAll();
//    cout<<"-------------------------------------------------"<<endl<<endl;
//    H.Remove(22);
//    H.Remove(1);
//    H.Remove(4);
//    H.Remove(3);
//    H.Remove(10);
//    H.Remove(31);
//    H.Remove(7);
//    H.Remove(12);
//    H.Remove(32);
//    H.PrintAll();
//    cout<<"-------------------------------------------------"<<endl<<endl;
//    H.PrintAdmitted();
//    cout<<"-------------------------------------------------"<<endl<<endl;
//    if(!H.Print(4))
//    {
//        cout<<"The Patient Doesnt Exist "<<endl<<endl;
//    }
//    cout<<"-------------------------------------------------"<<endl<<endl;
//    if(!H.Print(3))
//    {
//        cout<<"The Patient Doesnt Exist "<<endl<<endl;
//    }
//    cout<<"-------------------------------------------------"<<endl<<endl;
////    H.Insert(4, "Mohib", "12-05-2019", "flu", "not admitted");
////    H.PrintAll();
//    cout<<"-------------------------------------------------"<<endl<<endl;
//    cout<<H.get_level(31)<<endl<<endl;
//    cout<<H.get_level(3)<<endl<<endl;
//    cout<<H.get_level(4)<<endl<<endl;
//    cout<<"-------------------------------------------------"<<endl<<endl;
////    H.Insert(7, "usmar", "16-03-2021", "cold", "admitted");
////    H.get_root();
//    cout<<"-------------------------------------------------"<<endl<<endl;
//    H.search(12, 0);
////    H.get_root();
//    cout<<"-------------------------------------------------"<<endl<<endl;
//    H.split();
//    H.get_root();
//}