#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>

using namespace std;

void bfs(unordered_map<int,list<int>> &graph,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> qu;
    qu.push(node);
    visited[node]=1;
    while(!qu.empty()){
        int fnode = qu.front(); 
        qu.pop();
        ans.push_back(fnode);

        for (auto i: graph[fnode]){
            if(!visited[i]){
                qu.push(i);
                visited[i]=1;
            }
        }
    }
}

void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &graph,vector<int> &component){
    component.push_back(node);
    visited[node]= 1;

    for(auto i:graph[node]){
        if(!visited[i]){
            dfs(i,visited,graph,component);
        }
    }
}

class graph{
    public:
    unordered_map<int,list<int>> graph;

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

        return ans;
    }
    
    vector<vector<int>> DFS(int vertex){
        vector<vector<int>> ans;
        unordered_map<int,bool> visited;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                vector<int> component;
                dfs(i,visited,graph,component);
                ans.push_back(component);
            }
        }
        return ans;
    }

};

int main(){
    graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(2,4);
    g.addEdge(1,4);
    g.addEdge(0,4);
    g.addEdge(5,6);
    g.addEdge(8,7);
    g.addEdge(5,8);
    g.addEdge(5,7);
    g.addEdge(9,10);
    g.addEdge(9,11);
    g.addEdge(9,12);
    g.addEdge(10,12);
    g.addEdge(10,12);

    g.printGraph();    
    // g is graph with unknown shape
    cout<<"BFS"<<endl;
    vector<int> b = g.BFS(5); 
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
    int count=0;
    cout<<endl;
    cout<<"DFS"<<endl;
    vector<vector<int>> a = g.DFS(12);
    for(int i=0;i<a.size();i++){
        // cout<<count<<" "<<endl;
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        // count++;
        cout<<endl;
    }
    cout<<a.size();
}