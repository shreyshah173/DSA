#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<string,int> m;
    m["mango"] = 100;
    m.insert(make_pair("banana",140));
    m.insert(make_pair("apple",120));
    //print map
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
    //search
    auto it = m.find("apple");
    if(it!=m.end()){
        cout<<"price of apple is "<<m["apple"]<<endl;
    }
    //erase
    m.erase("apple");
    for (auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
}
