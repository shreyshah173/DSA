#include <iostream>
#include <vector>

// total number ways in a coin change problem

using namespace std;

void printVector(vector<int> vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n = 6;
    vector<int> a ={1};
    for(int i=0;i<n;i++){
        a.push_back(0);
    }
    printVector(a);
    vector<int> coins = {1,2,3};
    for(auto coin : coins){
        for(int i=0;i<a.size();i++){
            if(i-coin >= 0){
                a[i]+=a[i-coin];
            }
        }
        printVector(a);
    }
    cout<<a.back();
    return 0;
}