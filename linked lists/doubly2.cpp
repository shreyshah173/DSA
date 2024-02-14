#include <iostream>
using namespace std;

class node{
    public :
    int data;
    node* next;
    node* previous;
    node(int val){
        data = val;
        next=NULL;
        previous=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node* newNode = new node(val);
    if(head==NULL){
        head = newNode;
        newNode->previous = head;
        return ;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->previous = temp;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head!=NULL){
        head->previous = n;
    }
    head = n;
}

void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }

}

void DeleteByValue(node* &head,int val){
    node* temp = head;
    while(temp->next->data != val && temp->next!=NULL){
        temp = temp->next;
    }
    if(temp->next->data == val && temp->next!=NULL){
        node* temp2 = temp->next;
        temp->next = temp->next->next;
        temp->next->previous = temp;
        delete temp2;
        return;
    }
    else{
        node* temp2 = temp->next;
        temp->next = NULL;
        delete temp2;
    }

}

void deleteByPos(node* &head,int pos){
    int count = 1;
    node* temp = head;
    while(count<pos && temp->next!=NULL){
        count++;
        temp =temp->next;
    }
    if(temp->next!=NULL){
        node* temp2 = temp;
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous; 
        delete temp2;
    }
    else{
        node* temp2 = temp;
        temp->previous->next = temp;
        delete temp2;
    }

}

void deleteAthead(node* &head){
    node* temp = head;
    temp->next->previous = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
}

int main(){
    node* h1 = NULL;
    insertAtTail(h1,1001);
    insertAtTail(h1,1002);
    insertAtTail(h1,1003);
    insertAtTail(h1,1004);
    insertAtHead(h1,1000);
    // display(h1);
    // DeleteByValue(h1,1003);
    // deleteByPos(h1 , 4);
    deleteAthead(h1);
    display(h1);

}