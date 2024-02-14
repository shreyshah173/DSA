#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n = new node(val);
    node* temp = head;
    do{
        temp = temp->next;
    }while(temp->next !=head);
    temp->next = n;
    n->next = head;
    head = n;
    
    return ;
}

void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if (head == NULL){
        head = n;
        n->next = head;
        return;
    }
    node* temp = head;
    do{
        temp = temp->next;
    }while(temp->next != head);
    temp->next = n;
    n->next = head;
    return ;
}

void display(node* &head){
    node* temp = head;
    do{
        cout<<temp->data;
        cout<<endl;
        temp =temp->next;
    }while(temp != head);
}

void DeleteByPos(node* &head , int k){
    node* temp = head;
    int count = 2;
    while(count<k){
        // cout<<temp->data;
        temp = temp->next;
        count++;
    }
    // cout<<endl<<temp->data;
    node* del = temp->next;
    temp->next=temp->next->next;
    delete del;

}

void deleteAtHead(node* &head){
    node* temp = head;
    do{
        temp =temp->next;
    }while(temp->next != head);
    
    node* temp1 = head;
    temp->next = temp->next->next;
    head->next = NULL;
    head = temp->next;
    delete temp1;

}

int main(){
    node* h1 = NULL;
    insertAtTail(h1,1);
    insertAtTail(h1,2);
    insertAtTail(h1,3);
    insertAtTail(h1,4);
    insertAtTail(h1,5);
    insertAtTail(h1,6);
    insertAtHead(h1,0);
    // display(h1);
    // DeleteByPos(h1,3);
    deleteAtHead(h1);
    display(h1);

}