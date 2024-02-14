//using array
#include <iostream>
using namespace std;
#define n 20
class queue{
    int* arr;
    int front;
    int back;
    public:
    queue(){
        arr=new int[n];
        front =-1;
        back=-1;
    }

    void enqueue(int x){
        if(back==n-1){
            cout<<"Queue Overflow"<<endl;
        }
        back++;
        arr[back]=x;
        if(front==-1){
            front=0;
        }
    }

    void dequeue(){
        if(front ==-1 || front>back){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        front++;
        
    }

    int peek(){
        if(front==-1 || front>back){
            cout<<"No element in queue"<<endl;
            return -1;
        }
        cout<<arr[front]<<endl;
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
    q.enqueue(1);                                  
    q.enqueue(2);                                  
    q.enqueue(3);                                  
    q.peek();                                  
    q.dequeue();                                  
    q.peek();                                  
    q.dequeue();                                  
    q.peek();                                  
    q.dequeue();                                  
    q.peek();                                  
}                                  