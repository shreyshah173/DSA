#include <iostream>
using namespace std;

class node{
    public: 
    int data;
    node* next;
    node(int val){
        data = val;
        next=NULL;
    }
};

class queue{
    node* back;
    node* front;
    public:
    queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
        node* n =new node(x);
        if(front==NULL){
            front=n;
            back=n;
        }
        back->next=n;
        back=n;
    }

    void pop(){
        if(front==NULL){
            return ;
        }
        node* todelete = front;
        front=front->next;
        delete todelete;
    }

    bool empty(){
        if(front==NULL){
            return 1;
        }
        return 0;
    }

    int top(){
        if(front==NULL){
            cout<<"empty";
            return -1;
        }
        return front->data;
    }
};

int main(){
    queue q;
    q.push(10);
    q.push(20);
    q.pop();
    cout<<q.top();
    cout<<endl<<q.empty();

    return 0;
}