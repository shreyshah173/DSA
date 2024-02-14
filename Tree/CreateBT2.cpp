#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int search(int inOrder[] , int start , int end , int curr){
    for(int i=start;i<=end;i++){
        if(inOrder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* binaryTree(int postOrder[] , int inOrder[] , int start , int end, int length){
    static int idx = length -1;
    if(start > end){
        return NULL;
    }
    int val = postOrder[idx];
    idx--;
    Node* curr = new Node(val);
    if(start==end){
        return curr;
    }
    int pos = search(inOrder , start , end , val);
    curr->right = binaryTree(postOrder,inOrder,pos+1,end ,idx);
    curr->left = binaryTree(postOrder,inOrder,start , pos-1 , idx);
    return curr;
}

int main(){
    int n =5;
    int postOrder[] = {4,2,5,3,1};
    int inOrder[] = {4,2,1,5,3};
    Node* n1 = binaryTree(postOrder,inOrder,0,4,5);
    cout<<n1->data<<endl;
    cout<<n1->left->data<<endl;
    cout<<n1->right->data<<endl;
    cout<<n1->left->left->data<<endl;
    cout<<n1->right->right->data<<endl;
    return 0;
}