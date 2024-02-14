#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

void bfs(unordered_map<int ,list<int>> graph, unordered_map<int ,bool> &visited, vector<int> &ans, int node){
    queue<int> qu;
    qu.push(node);
    ans.push_back(node);
    visited[node]=1;
    while(!qu.empty()){
        int a = qu.front();
        qu.pop();
        for(auto i : graph[a]){
            if(!visited[i]){
                qu.push(i);
                visited[i]=1;
                ans.push_back(i);
            }
        }
    }
}

void dfs(unordered_map<int ,list<int>> graph, unordered_map<int ,bool> &visited, vector<int> &component, int node){
    component.push_back(node);
    visited[node]=1;
    for(auto i : graph[node]){
        if(!visited[i]){
            dfs(graph,visited,component,i);
        }
    }
}

bool BFScycle(unordered_map<int ,list<int>> graph,unordered_map<int ,bool> visited,int src){
    unordered_map<int ,int > parent;
    parent[src] =-1;
    visited[src] = 1;
    queue<int> qu;
    qu.push(src);
    while(!qu.empty()){
        int a = qu.front();
        qu.pop();
        for(auto i:graph[a]){
            if(visited[i] && i!=parent[a]){
                return true;
            }
            else if(!visited[i]){
                visited[i]=1;
                parent[i]=a;
                qu.push(i);
            }
        }
    }
    return false;
}

bool DFScycle(unordered_map<int ,list<int>> graph,unordered_map<int ,bool> visited,int src, int parent){
    visited[src]=1;
    for(auto i:graph[src]){
        if(!visited[i]){
            if(DFScycle(graph,visited,i,src)){
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
        unordered_map<int ,bool> visited;
        vector<int> ans;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                bfs(graph,visited,ans,i);
            }
        }
        return ans;
    }

    vector<vector<int>> DFS(int vertex){
        unordered_map<int ,bool> visited;
        vector<vector<int>> ans;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                vector<int> component;
                dfs(graph,visited,component,i);
                ans.push_back(component);
            }
        }
        return ans;
    }

    bool cyclicDetectionBFS(int vertex){
        unordered_map<int ,bool> visited;  
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                if(BFScycle(graph,visited,i)){
                    return 1;
                }
            }
        }
        return 0;
    }

    bool cyclicDetectionDFS(int vertex){
        unordered_map<int ,bool> visited;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                if(DFScycle(graph,visited,i,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};


int main(){
    graph g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,2);
    g.addEdge(4,3);
    g.addEdge(3,5);

    // vector<vector<int>> a = g.DFS(5);
    // for(int i=0;i<a.size();i++){
    //     for(int j=0;j<a[i].size();j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    bool a = g.cyclicDetectionDFS(4);
    cout<<a;

}