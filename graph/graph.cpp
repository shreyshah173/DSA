#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph{
    public:
    unordered_map<int , list<int>> adj;

    void addEdge(int u,int v, bool direction){
        // if direction 
        // == 0 -> undirected
        // == 1 -> directed
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }
    
    void printAdjList(){
        for (auto i:adj){
            cout<< i.first << "->";
            for(auto j:i.second){
                cout << j << ", ";
            }
            cout<<endl; 
        }
    }
};

int main(){
    int n=5; //no. of nodes
    int m=6; //no. of edges

    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printAdjList();
}