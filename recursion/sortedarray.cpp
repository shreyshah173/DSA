// check whether a array is sorted or not 
#include <iostream>
using namespace std;

int check(int arr[]){
    for(int i=0;i<5;i++){
        if(arr[i]>arr[i+1]){
            cout<<"Not a sorted array";
            return 0;
        }
    }
    cout<<"Sorted array";
    return 0;
}

int main(){
    // int n ;
    // cin>>n;
    int arr[5]={1,2,3,45,56};
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    cout<<check(arr[]);
    return 0;
}

