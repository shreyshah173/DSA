#include <iostream>
using namespace std;
#define n 100

class queue{
    int *arr;
    int front;
    int back;
    public:
    queue(){
        arr = new int[n];
        front =-1;
        back=-1;
    }
    void push(int x){
        if(back == n-1){
            cout<<"Stack overflow"<<endl;
            return ;
        }
        back++;
        arr[back]=x;
        if(front==-1){
            front++;
        }
    }
    void pop(){
        if(front>back || front==-1){
            cout<<"Stack Empty"<<endl;
            return ;
        }
        front++;
    }
    int peek(){
        if(front==-1 || front>back){
            cout<<endl<<"Stack Empty ";
            return -1;
        }
        cout<<endl;
        return arr[front];  
    }
    bool empty(){
        if(front==-1 || front>back){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;                                  
    q.push(1);                                  
    q.push(2);                                  
    q.push(3);                                  
    cout<<q.peek();                                  
    q.pop();                                  
    cout<<q.peek();                                  
    q.pop();                                  
    cout<<q.peek();                                  
    q.pop();                                  
    cout<<q.peek();                                  
}