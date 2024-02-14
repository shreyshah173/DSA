#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

void dfs(unordered_map<int,bool> &visited,unordered_map<int , list<int>> graph,int node,vector<int> &component){
    component.push_back(node);
    visited[node] = 1;
    for(auto i : graph[node]){
        if(!visited[i]){
            dfs(visited,graph,i,component);
        }
    }
}
void bfs(unordered_map<int,bool> &visited,unordered_map<int , list<int>> graph,int node,vector<int> &ans){
    queue<int> qu;
    qu.push(node);
    ans.push_back(node);
    visited[node] =1;
    while (!qu.empty()){
        int a = qu.front();
        qu.pop();
        for(auto i : graph[a]){
            if(!visited[i]){
                qu.push(i);
                ans.push_back(i);
                visited[i]=1;
            }
        }
    }
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
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    vector<int> BFS(int vertex){
        unordered_map<int , bool > visited;
        vector<int> ans;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                // bfs(visited,graph,i,ans);
                bfs(visited,graph,i,ans);

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
                dfs(visited,graph,i,component);
                ans.push_back(component);
            }
        }
        return ans;
    }
};

int main(){
    graph g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,0);
    g.addEdge(5,4);
    g.addEdge(3,4);
    g.addEdge(2,4);

    g.printGraph();
    // vector<int> a = g.BFS(5);
    // for(int i=0;i<a.size();i++){
    //     cout<<a[i]<<" ";
    // }
    vector<vector<int>> a = g.DFS(5);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}