#include<iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    cout<<"NOW"<<endl;
    int max_arr = arr[0];
    if(arr[0]>arr[1]){
        cout<<max_arr<<endl;
    }
    for(int i=1;i<N;i++){
        if(arr[i]>arr[i+1]){
            if(arr[i]>max_arr){
                cout<<arr[i]<<endl;
            }
        }
        max_arr = max(max_arr,arr[i]);
    }
}