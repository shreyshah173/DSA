#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

using namespace std;

void bfs(unordered_map<int ,list<int>> graph , unordered_map<int ,bool> &visited,vector<int> &ans , int node){
    queue<int> qu;
    qu.push(node);
    visited[node] = 1;
    while(!qu.empty()){
        int a = qu.front();
        qu.pop();
        ans.push_back(a);
        for(auto i:graph[a]){
            if(!visited[i]){
                qu.push(i);
                visited[i] = 1;
            }
        }
    }
}

void dfs(unordered_map<int ,list<int>> graph , unordered_map<int ,bool> &visited,vector<int> &component , int node){
    component.push_back(node);
    visited[node] = 1;
    for(auto i:graph[node]){
        if(!visited[i]){
            dfs(graph,visited,component,i);
        }
    }
}

bool isCyclic(int src,unordered_map<int,bool> &visited,unordered_map<int,list<int>> graph){
    unordered_map<int , int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> qu;
    qu.push(src);
    while(!qu.empty()){
        int front = qu.front();
        qu.pop();

        for(auto neighbour:graph[front]){
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

bool isCyclicDFS(int src,unordered_map<int,bool> &visited,unordered_map<int,list<int>> graph,int parent){
    visited[src]=1;
    for(auto i:graph[src]){
        if(!visited[i]){
            if(isCyclicDFS(i,visited,graph,src)){
                return true;
            }
        }
        else{
            if(i!=parent){
                return true;
            }
        }
    }
    return false;
}

class graph{
    public:
    unordered_map<int ,list<int>> graph;

    void addEdge(int u,int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
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

    vector<int> BFS(int vertex){
        vector<int> ans;
        unordered_map<int ,bool> visited;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                bfs(graph,visited,ans,i);
            }
        }
    }

    vector<vector<int>> DFS(int vertex){
        vector<vector<int>> ans;
        unordered_map<int ,bool> visited;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                vector<int> component;
                // dfs
                ans.push_back(component);
            }
        }
        return ans;
    }

    bool CycleDetectionBFS(int vertex){
        unordered_map<int ,bool > visited;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                if(isCyclic(i,visited,graph)){
                    return 1;
                }
            }
        }
        return 0;
    }

    bool CycleDetection(int vertex){
        unordered_map<int ,bool> visited;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                if(isCyclicDFS(i,visited,graph,-1)){
                    return true;
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


    bool a = g.CycleDetection(4);
    cout<<a;
}