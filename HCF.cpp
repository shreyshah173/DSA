#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int rem = a%b;
        a=b;
        b=rem;
    }
    return a;
}

int main(){
    int x,y;
    cin>>x>>y;
    cout<<gcd(x,y);

    return 0;
}