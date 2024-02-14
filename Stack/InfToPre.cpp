#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int prec(char a){
    if(a=='^'){
        return 3;
    }
    else if(a=='*' || a=='/'){
        return 2;
    }
    else if(a=='+' || a=='-'){
        return 1;
    }
    else{   
        return -1;
    }
}

string InfToPre(string a){
    reverse(a.begin(),a.end());

    stack<char> st;
    string res="";

    for(int i=0;i<a.length();i++){
        if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z')){
            res+=a[i];
        }
        else if(a[i]==')'){
            st.push(a[i]);
        }
        else if(a[i]=='('){
            while(!st.empty() && st.top()!=')'){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(a[i])){
                res+=st.top();
                st.pop();
            }
            st.push(a[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }       
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    cout<<InfToPre("(a-b/c)*(a/k-l)");
}