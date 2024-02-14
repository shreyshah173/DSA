#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<int,string> a;
    a[0] = "Start-> ";
    a[3] = "is";
    a[1] = "Shrey";
    a[2] = "Shah";
    a[4] = "at";
    a[5] = "home";
    for(auto i:a){
        cout<<i.first<<" ";
    }
}