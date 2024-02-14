#include<iostream>
#include<algorithm>

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="RGgfgfGRFGWFgretfFfwefwef";
    
    // convert to lowercase
    for(int i=0;i<str.length();i++){
        if(str[i] >='a' && str[i]<='z'){
            str[i] -= 32;
        }
    }
    sort(str.begin(),str.end());
     
    cout<<str<<endl;
    // convert to uppercase
    for(int i=0;i<str.length();i++){
        if(str[i] >='A' && str[i]<='Z'){
            str[i] += 32;
        }
    }
    sort(str.begin(),str.end());
    cout<<str<<endl;


    string s = "fakjsdfhlak";
    transform(s.begin(),s.end(), s.begin(), ::toupper);
    cout<<s<<endl;
    transform(s.begin(),s.end(), s.begin(), ::tolower);
    cout<<s<<endl;
    return 0;
}