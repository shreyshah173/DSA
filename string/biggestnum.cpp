#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string s = "49872354144765466";
    sort(s.begin(),s.end(),greater<int>());
    cout<<s<<endl;
}