#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    char arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int count =0;
    for(int i=0;i<N;i++){
        if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u'){
            count++;
        }
    }
    cout<<count;
}