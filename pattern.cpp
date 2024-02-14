//Rectangle
#include <iostream>
using namespace std;

int main(){
    int Row,Col;
    cin>>Row;
    cin>>Col;
    for(int i=1;i<=Row;i++){
        for(int j=1;j<=Col;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}