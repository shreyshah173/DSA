#include <iostream>
using namespace std;

void fib(int n){
    int  a = 0;
    int b = 1;
    int nextTerm;

    for(int i=1;i<=n;i++){
        cout<<a<<endl;
        nextTerm =a+b;
        a=b;
        b=nextTerm;
    }
}

int main(){
    int n;
    cin>>n;
    fib(n);
    return 0;

}