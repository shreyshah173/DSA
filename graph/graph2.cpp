#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

template <typename T>

class graph {
    public :
        unordered_map<T , list<T>> adj;

        void addEdge(T u,T v,bool dir){  // direction 0 -> undirected grapgh
            adj[u].push_back(v);
            if(!dir){
                adj[v].push_back(u);
            }
        }

        void printGraph(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<",";   
                }
                cout<<endl;
            }
        }
};

int main(){
    graph<char> g;
    // g.addEdge(0,1,0);  // if  graph<int> g;
    // g.addEdge(0,4,0);
    // g.addEdge(1,2,0);
    // g.addEdge(1,3,0);
    // g.addEdge(1,4,0);
    // g.addEdge(2,3,0);
    // g.addEdge(3,4,0);
    g.addEdge('a','b',0);
    g.addEdge('a','d',0);
    g.addEdge('b','c',0);
    g.addEdge('b','d',0);
    g.addEdge('c','d',0);
    g.addEdge('d','e',0);
    g.printGraph();
}