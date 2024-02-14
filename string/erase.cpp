#include <iostream>
using namespace std;

int main(){
    string str="ShreyShahShah";
    str.erase(5,4);
    cout<<str<<endl;
    cout<< str.find("Shah")<<endl;
    str.insert(5,"shahshrey");
    cout<<str<<endl;
    string s1="nincoomp";
    for(int i=0;i<s1.length();i++){
        cout<<s1[i]<<endl;
    }
    
    return 0;
}