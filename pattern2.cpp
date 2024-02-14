//HollowRectangle
#include <iostream>
using namespace std;

int main(){
    int Row,Col;
    cin>>Row>>Col;
    for(int i=1;i<=Row;i++){
        for(int j=1;j<=Col;j++){
            if(i==1 || i==Row || j==1 || j==Col ){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}