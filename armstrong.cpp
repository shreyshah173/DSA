#include<iostream>         // problem in vs code the code is correct 
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;

    int sum = 0;
    int b ;
    b =n;
    while(n>0){
        int l = n%10;
        sum += pow(l,3);
        n/=10;
    }
    cout<<sum; //153 not satisfy
    if(sum == b){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}