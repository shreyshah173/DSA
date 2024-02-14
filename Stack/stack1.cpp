#include <iostream>
using namespace std;

#define n 100

class Stack{
    int* arr;
    int top;
    
    public:
    Stack(){
        arr = new int[n];
        top=-1;
    } 
    void push(int val){
        if(top==n-1){
            cout<<"Stack overflow"<<endl;
            return;
        }    
        top++;
        arr[top]= val;
    }
    void pop(){
        if(top == -1){
            cout<<"Stack UnderFlow"<<endl;
            return;
        }
        top--;
    }
    int Top(){
        if(top == -1){
            cout<<"Stack UnderFlow ";
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        return (top==-1);
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.Top()<<endl;
    cout<<s.empty()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    cout<<s.empty()<<endl;
}