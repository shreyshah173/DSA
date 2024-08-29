#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N = 1e+5;
vector<int> parent(N);
vector<int> sz(N);

void make_set(int v){
    parent[v]=v;
    sz[v]=1;
}

int find_set(int v){
    if (v==parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

int main(){
    for(int i=0;i<N;i++){
        make_set(i);
    }

    int n,m;
    cin>>n>>m;

    // vector<vector<int>> adj(n);
    bool cycle=false;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u = find_set(u);
        v = find_set(v);
        // adj.push_back({u,v});
        if(u==v){
            cycle=true;
        }
        else{
            union_sets(u,v);
        }
    }
    cout<<cycle<<endl;
}