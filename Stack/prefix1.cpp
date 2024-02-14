#include <iostream>
#include <stack>
#include <math.h>
#include <string>
using namespace std;

int prefixEvaluation(string s){
    stack<int> st;
    for(int i=s.length()-1 ;i>=0;i--){
        if(s[i]<='9' && s[i]>='0'){
            st.push(s[i]-'0');
        }
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (s[i]){
                case '+':
                    st.push(op1 + op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
                default :
                    cout<<"Error";
                    break;
            }
        }
    }
return st.top();
}

int main(){
    string s ="+-27*8/42";
    cout<<prefixEvaluation("-+7*45+20");
}