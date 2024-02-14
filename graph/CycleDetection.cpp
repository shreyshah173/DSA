#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

bool isCyclic(int src,unordered_map<int, bool> &visited,unordered_map<int ,list<int>> graph){
    unordered_map<int ,int> parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> qu;
    qu.push(src);
    while(!qu.empty()){
        int front = qu.front();
        qu.pop();

        for(auto neighbour : graph[front]){
            if(visited[neighbour] && neighbour != parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                qu.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return 0;
}

class graph{
    public:
    unordered_map<int , list<int>> graph;

    void addEdge(int u,int v){
        graph[u].push_front(v);
        graph[v].push_front(u);
    }

    void printGraph(){
        for(auto i:graph){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    bool CycleDetection(int vertex){
        unordered_map<int , bool > visited;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                bool ans = isCyclic(i ,visited, graph);
                if(ans){
                    return 1;
                }
            }
        }
        return false;
    }
};

int main(){
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    // g.addEdge(0, 1);
    // g.addEdge(3, 2);
    // Removed the edge (2, 3) to break the cycle
    g.addEdge(3, 4);


    bool a = g.CycleDetection(5);
    cout<<a;
}