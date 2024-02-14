#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int find(float value, float Arr[], int n){
    for(int i=0;i<n;i++){
        if(Arr[i]==value){
            Arr[i]++;
            return i;
        }
    }
}

void total(int duration[], int Entertainment[], int n, int t){
    int d[n],E[n];
    float R[n],S[n];    
    for(int i=0;i<n;i++){
        d[i]=duration[i];
        E[i]=Entertainment[i];
        R[i]=(float)E[i]/d[i];
        S[i]=R[i];
    }
    sort(S,S+n);
    int c=0;
    for(int i=0;i<n;i++){
        float v = S[n-1-i];
        int index = find(v,R,n);
        if(t>=d[index]){
            c=c+E[index];
            t = t - d[index];
            cout<<index+1<<" ";
            if(index==0){
                cout<<"Avengers"<<endl;
            }
            else if(index==1){
                cout<<"Thor"<<endl;
            }
            else if(index==2){
                cout<<"Captain America"<<endl;
            }
            else if(index==3){
                cout<<"Iron Man"<<endl;
            }
            else{
                cout<<"Hulk"<<endl;
            }
            continue;
        }
    }
    cout<<endl<<c;

}

int main(){
    int duration[] = {2,1,4,3,2};
    int Entertainment[] = {10,8,9,15,5};
    int n = 5,t=8;
    total(duration, Entertainment, n, t);
    return 0;
}