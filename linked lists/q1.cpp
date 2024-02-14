#include <iostream>
using namespace std;

class node {
    public : 
    int data;
    node* next;
    node(int val){
        data = val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;   
}

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

node* merge(node* &head1,node* &head2){
    node* dummyNode=new node(-1);
    node* p1=head1;
    node* p2=head2;
    node* p3=dummyNode;
    while(p1!=NULL && p2!=NULL){
        if(p1->data>p2->data){
            p3->next=p2;
            p2=p2->next;
        }
        else{
            p3->next=p1;
            p1=p1->next;
        }
        p3=p3->next;
    }
    while(p1==NULL && p2!=NULL){
        p3->next=p2;
        p3=p3->next;
        p2=p2->next;
    }
    while(p2==NULL && p1!=NULL){
        p3->next=p1;
        p3=p3->next;
        p1=p1->next;
    }
    display( dummyNode->next);
}

int main(){
    node* head1=NULL;
    insertAtTail(head1,5);
    insertAtTail(head1,10);
    insertAtTail(head1,15);
    node* head2=NULL;
    insertAtTail(head2,2);
    insertAtTail(head2,3);
    insertAtTail(head2,20);
    display(head1);
    display(head2);
    merge(head1,head2);
}