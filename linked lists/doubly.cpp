#include <iostream>
using namespace std;

class node{
    public :
    int data;
    node* prev;
    node* next;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head = n;
}

void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        n->prev=head;
        return ;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void Delete(node* &head,int pos){
    node* temp=head;
    if(pos==1){
        node* deleted = head;
        head=head->next;
        head->prev=NULL;
        delete deleted;
        return;
    }
    int count =1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    node* todelete = temp;
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete todelete;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head=NULL;
    node* head2=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int n;
        cin>>n;
        insertAtHead(head,n);
    }
    for(int i=0;i<n;i++){
        int n;
        cin>>n;
        insertAtHead(head2,n);
    }
    for(int i=0;i<n;i++){
        int 
    }
//     insertAtTail(head,5);
//     insertAtTail(head,6);
//     insertAtTail(head,7);
//     insertAtTail(head,8);
//     insertAtTail(head,9);
//     insertAtHead(head,4);
//     insertAtHead(head,3);
//     insertAtHead(head,2);
//     insertAtHead(head,1);
//     display(head);
//     Delete(head,5);
//     display(head);
}