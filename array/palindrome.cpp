#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool flag =0;
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[n-i-1]){
            flag=1;
            cout<<"No"<<endl;
            break;
        }
    }
    if(flag ==0){
        cout<<"yes"<<endl;
    }
}