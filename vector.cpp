#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> v;
    v.push_back(1);
    v.push_back(50);
    v.push_back(10);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<endl;
    // }

    vector<int>::iterator it;
    for(it = v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }

    int n =v.size();
    cout<<n;
    cout<<endl;

    v.pop_back();
    for(auto element:v){
    cout<<element<<endl;
    }
    // for(it=v.begin();it!=v.end();it++){
    //     cout<<*it<<endl;
    // }
}