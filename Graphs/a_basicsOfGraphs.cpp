#include<bits/stdc++.h>
using namespace std;

template <typename T>                // For making it generic graph , we can make it int or char or any

class Graph{
 public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction){

        adj[u].push_back(v);
        if(direction == 0)
            adj[v].push_back(u);
    }

    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<< j <<" , ";

            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the no. of Nodes: ";
    cin>>n;
    int m;
    cout<<"Enter the no. of Edges: ";
    cin>>m;

    Graph<int> g;                        /// Generic graph if we want char  then:   Graph<char> g

    for(int i=0; i< m; i++){
        int u , v;
        cin>> u >> v;
        // Creating an undirected Graph
        g.addEdge(u , v, 0);
    }
    // Printing the graph
    g.printAdjList();
}