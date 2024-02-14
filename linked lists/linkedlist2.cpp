#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

int length(node* &head){
    node* temp = head;
    int counter = 0;
    while(temp!=NULL){
        temp=temp->next;
        counter++;
    }
    return counter;
}

void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head = n;
        return ;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next=n;

}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
// iterative reverse
node* Reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while (currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;

}       
// recursive reverse 
node* reverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}
// reverse k nodes # while getting a new node from k reverse you will also get changes in the head you give as an argument
node* KReverse(node* &head, int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr ;
    int count = 0;
    while (count < k && currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = KReverse(nextptr,k);
    }
    return prevptr;

}

bool detectCycle(node* &head){
    node* slowptr = head;
    node* fastptr = head;
    while(fastptr!=NULL && fastptr->next!=NULL){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (fastptr == slowptr){
            return true;
        }

    }
    return false;
}

void removeCycle(node* &head){
    node* slowptr = head;
    node* fastptr = head;
    while(slowptr!=fastptr){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    fastptr=head;
    while(slowptr->next!=fastptr->next){
        slowptr = slowptr->next;
        fastptr = fastptr->next;
    }
    slowptr->next = NULL;
}

void makeCycle(node* &head , int pos){
    node* temp = head;
    node* startNode;
    int count = 1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode = temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next = startNode;
}
// appends last k nodes to the starting 
void AppendLastK(node* &head,int k){
    node* temp = head;
    int count = 0;
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    count++; // length of the linkedlist 
    int counter = 1;
    node* temp2 = head;
    int dist = count-k;
    while (counter < dist && k>0){
        temp2 = temp2->next;
        counter++;
    }
    // cout<<temp2->data;
    // cout<<temp->data;
    temp->next = head;
    head = temp2->next;
    temp2->next = NULL;

}

void intersect(node* &head1,node* &head2, int k ){
    node* temp1 = head1;
    node* temp2 = head2;
    while(--k){
        temp1 = temp1->next;
    }
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }    
    temp2->next = temp1;
}

bool findIntersection(node* &head1 , node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    node* temp1 = head1;
    node* temp2 = head2;
    if(l1 >= l2){
        int diff = l1 - l2;
        while(diff){
            diff--;
            temp1=temp1->next;
        }
        while(temp1->next != temp2->next && l2){
            temp1 = temp1->next;
            temp2 = temp2->next;
            l2--;
        }
        if(temp1->next == temp2->next && temp1->next!=NULL){return true;}
    }
    else{
        int diff = abs(l1 - l2);
        while(diff){
            diff--;
            temp2=temp2->next;
        }
        while(temp1->next != temp2->next && l1){
            temp1 = temp1->next;
            temp2 = temp2->next;
            l1--;
        }
        if(temp1->next == temp2->next && temp1->next!=NULL){return true;}
    }
    return false;
}
// iterative merge
node* MergeTwoSorted(node* &head1,node* &head2){
    node* temp1 = head1;
    node* temp2 = head2;
    node* temp3 = NULL;

    while(temp1!=NULL && temp2!=NULL){
        int t1 = temp1->data;
        int t2 = temp2->data;

        if(t1 <= t2){
            insertAtTail(temp3,t1);
            temp1 = temp1->next;
            // cout<<t1<<endl;
        }
        else {
            insertAtTail(temp3,t2);
            temp2 = temp2->next;
            // cout<<t2<<endl;
        }
    }
    node* temp4 = temp3;
    while(temp4->next!=NULL){
        temp4=temp4->next;
    }
    if (temp1==NULL){
        temp4->next = temp2;
        // display(temp2);
    }
    if (temp2==NULL){
        temp4->next = temp1;
        // display(temp1);
    }
    // display(temp3);
    return temp3;
}

node* mergeTwoSorted(node* &head1, node* &head2){
    node* temp = NULL;
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    if(head1->data < head2->data){
        temp = head1;
        temp->next = mergeTwoSorted(head1->next,head2);
    }
    else{
        temp = head2;
        temp->next = mergeTwoSorted(head1,head2->next);
    }

    return temp;
}

node* evenafterodd(node* &head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node* odd = head;
    node* even= head->next;
    node* Fisrteven= even;
    while(odd->next!=NULL && even->next!=NULL ){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = Fisrteven;
    if(odd->next!=NULL){
        even->next = NULL;
    }
    return head;
}

int main(){
    node* h1 = NULL;
    node* h2 = NULL;
    insertAtTail(h1,101);
    insertAtTail(h1,104);
    insertAtTail(h1,105);
    insertAtTail(h1,106);
    insertAtTail(h1,302);
    insertAtTail(h1,303);
    insertAtTail(h2,103);
    insertAtTail(h2,202);
    insertAtTail(h2,204);
    insertAtTail(h2,205);
    // intersect(h1,h2,4);
    // int l = length(h1);
    // cout<<l;
    // node* l1 = reverse(h1);
    // display(l1);
    // node* l3 = KReverse(h1,2);
    // display(l3);
    // node* l4 = KReverse(h1,3);
    // display(l4);
    // cout<<endl;
    // display(h1);
    // makeCycle(h1,3);  // never display h1 after this it is a cycle 
    // display(h1);
    // cout<<detectCycle(h1)<<endl;
    // removeCycle(h1);
    // cout<<detectCycle(h1)<<endl;
    // AppendLastK(h1,3);
    // display(h1);
    // display(h2);
    // cout<<findIntersection(h1,h2);
    // node* h3 = mergeTwoSorted(h1,h2);
    node* n3 = evenafterodd(h1);
    display(n3);
}