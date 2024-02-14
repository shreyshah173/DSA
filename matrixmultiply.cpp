#include <iostream>
using namespace std;

int main(){
    int m1,m2,n1,n2;
    
    cin>>m1>>m2;
    int A[m1][m2];
    for(int i=0;i<m1;i++){
        for(int j=0;j<m2;j++){
            cin>>A[i][j];
        }
    }

    cin>>n1>>n2;
    int B[n1][n2];
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cin>>B[i][j];
        }
    }

    if(m2==n1){
        cout<<"multiplication possible";
    }
    else{
        cout<<"Not possible to multiply ";
    }

    cout<<endl;

    int mul[m1][n2];
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            mul[i][j]=0;
            for(int k=0;k<m2;k++){
                mul[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            cout<<mul[i][j] << " ";
        }
        cout<<endl;
    }
    
    return 0;
}
