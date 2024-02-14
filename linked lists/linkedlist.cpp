#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next =NULL;
    }
};
void insertAthead(node* &head,int val){
    node* n =new node(val);     
    n->next=head;
    head = n;
}
void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if(head == NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n; 
}
bool check(node* head , int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true; 
        }
        temp=temp->next;
    }
    return false;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    // cout<<"NULL"<< endl;
    cout<<endl;
}
void deletion(node* &head,int val){
    node* temp = head;
    if(temp->data==val){
        head = temp->next;
        return;
    }
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
void deleteAthead(node* &head){
    node* todelete = head;
    head=head->next;
    delete todelete;
}
node* reverse(node* &head){
    node* currptr = head;
    node* prevptr = NULL;
    node* nextptr ;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}
node* Reverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newHead=Reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}
node* Kreverse(node* &head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next=Kreverse(nextptr,k);    
    }
    return prevptr;
}
void insertion(node* &head,int val,int val2){
    node* n = new node(val);
    // if(head==NULL){
    //     head=n;
    //     return;
    // }
    node* temp = head;
    node* temp2;
    while(temp->data!=val2){
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=n;
    n->next=temp2;
}

void makeCycle(node* &head,int pos){
    node* temp=head;
    node* startNode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

bool detectcycle(node* &head){
    node* slow=head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow){
            cout<<"Cycle Detected"<<endl;
            return true;
        }

    }
    return false;
}

void removeCycle(node* & head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(slow->next==fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
    cout<<"Cycle Removed"<<endl;
}

//MAIN FUNCTION

int main(){
    node* head=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertAthead(head,x);
    }
    display(head);
    return 0;
}