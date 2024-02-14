#include <list>
#include <iostream>

using namespace std;

int main(){
    list<int> a;
    a.push_front(4);
    a.push_front(3);
    a.push_front(2);
    a.push_front(1);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    a.push_front(0);
    for (auto i : a){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<a.empty()<<endl;
    a.pop_back();
    a.pop_front();
    a.pop_front();
    for (auto i:a){
        cout<<i<<" ";
    }
}