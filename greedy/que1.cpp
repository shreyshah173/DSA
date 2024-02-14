#include <bits/stdc++.h>
using namespace std;

int find(int Arr[], int value, int n){
    for(int i=0;i<n;i++){
        if(Arr[i]==value){
            Arr[i]=0;
            return i;
        }
    }
}

int main(){
    int x[] = {100,100,100,700,100,100};
    int y[] =  {98,100,100,700,100,100};
    int X = 99,Y=100,Q=100000;
    int Total[6],T[6];
    for(int i=0;i<6;i++){
        Total[i]=x[i]*X + y[i]*Y; 
        T[i]=Total[i];
    }
    sort(T,T+6);
    int count = 0;
    for(int i=0;i<n;i++){
        if(Q>=T[i]){
            Q=Q-T[i];
            int index = find(Total,T[i],6);
            cout<<index+1<<" ";
            count++;
        }
    }
    cout<<endl<<count;
}