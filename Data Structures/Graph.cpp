//#include<iostream>
//#include<vector>
//#include<fstream>
//#include<list>
//using namespace std;
//class Graph
//{
//    vector<list<int>> adj;
//public:
//    void Read_File(string F)
//    {
//        ifstream MyFile;
//        MyFile.open(F, ios::in);
//        if(!MyFile)
//        {
//            cout<<"File not Found "<<endl;
//        }
//        else
//        {
//            int temp, vertix, edge;
//            MyFile>>temp;
//
//            adj.resize(temp);
//            while(!MyFile.eof())
//            {
//                MyFile>>vertix>>edge;
//                adj[vertix-1].push_back(edge);
//                adj[edge-1].push_back(vertix);
//            }
//            MyFile.close();
//        }
//    }
//    void Print()
//    {
//        list<int>::iterator j;
//        for(int i=0; i<adj.size();i++)
//        {
//            cout<<i+1<<". ";
//            for(j = adj[i].begin(); j!=adj[i].end(); j++)
//            {
//                cout<<*j<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//    }
//    void Degree()
//    {
//        list<int>::iterator j;
//        for(int i=0; i<adj.size();i++)
//        {
//            cout<<i<<". ";
//            int temp = 0;
//            for(j = adj[i].begin(); j!=adj[i].end(); j++)
//            {
//                temp++;
//            }
//            cout<<temp<<endl;
//        }
//    }
//    void Print_neighbours(const int key)
//    {
//        list<int>::iterator j;
//        cout<<"Neighbours of "<<key<<": ";
//        for(j = adj[key-1].begin(); j!=adj[key-1].end(); j++)
//        {
//            cout<<*j<<" ";
//        }
//        cout<<endl;
//    }5
//    void DFS_Help(int key, bool visited[])
//    {
//        visited[key] = true;
//        cout<<key<<" ";
//
//        list<int>::iterator i;
//        for(i=adj[key].begin(); i!=adj[key].end();++i)
//        {
//            if(!visited[*i])
//                DFS_Help(*i, visited);
//        }
//
//    }
//    void DFS(int key)
//    {
//        bool *visited = new bool[adj.size()];
//        for(int i=0;i<adj.size();i++)
//            visited[i] = false;
//
//        DFS_Help(key, visited);
//    }
//    ~Graph()
//    {
//        adj.clear();
//    }
//
//};
//
//int main()
//{
//    string file = "/Users/taimourabdulkarim/Documents/Clion/graph.txt";
//    Graph G;
//    G.Read_File(file);
//    G.Print();
//    G.Degree();
//    G.Print_neighbours(2);
//    //G.DFS(2);
//}