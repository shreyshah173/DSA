#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max_i= arr[0];
    for(int i=1;i<n;i++){
        max_i=max(max_i,arr[i]);
        cout<<max_i<<" ";
    }
    cout<<max_i;
}