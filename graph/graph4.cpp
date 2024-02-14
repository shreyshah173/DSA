// not space efficient 
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(0);
    }
    vector<vector<int>> adj;
    for(int i=0;i<n;i++){
        adj.push_back(v);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a][b]=1;
    }

}