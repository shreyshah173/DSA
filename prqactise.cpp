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

void InsertATHead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    head=n; 
}

void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head = n;
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void DeleteAtEnd(node* &head){
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=NULL;
    delete todelete;
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head=NULL;
    // node* head2=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);    
    InsertATHead(head,4);
    // cout<<check(head,2);
    // cout<<check(head,5);
    cout<<endl;
    // deletion(head,2);   
    DeleteAtEnd(head);
    // insertAtTail(head,2);
    // insertAtTail(head,3);
    display(head);
}    

