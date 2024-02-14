#include <iostream>
using namespace std;

int main(){
    string str = "ShreyShah";
    string str2= str.substr(5,4);
    cout<<str2<<endl;

    string str3 = "786";
    int s = stoi(str3); // string to int
    cout<<s*2<<endl;
    int s1 = 123;
    cout<<to_string(s1) + "4 "<<endl;
    return 0;
}