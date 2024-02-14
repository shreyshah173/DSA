#include <list>
#include <iostream>
using namespace std;

int main(){
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_front(0);
    l.push_front(-1);
    l.push_front(-2);
    for(auto i:l){
        cout<<i<<" ";
    }   
    cout<<endl;
    l.pop_back();
    l.pop_front();
    for(auto i:l){
        cout<<i<<" ";
    }   
    cout<<endl;
    cout<<l.size();
    cout<<endl;
    cout<<l.empty();
}