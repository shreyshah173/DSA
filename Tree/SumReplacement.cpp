#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left =NULL;
        right=NULL;
    }
};

void sumReplace(Node* root){
    if(root==NULL){
        return ;
    }
    sumReplace(root->left);
    sumReplace(root->right);
    if(root->left != NULL){
        root->data += root->left->data;
    }
    if(root->right != NULL){
        root->data += root->right->data;
    }
}

int main(){
    Node* n = new Node(1);
    n->left = new Node(2);
    n->right= new Node(3);
    n->left->left = new Node(4);
    n->left->right = new Node(5);
    n->right->left= new Node(6);
    n->right->right= new Node(7);
    sumReplace(n);
    cout<<endl<<n->data;
    cout<<endl<<n->left->data ;
    cout<<endl<<n->right->data;
    cout<<endl<<n->left->left->data ;
    cout<<endl<<n->left->right->data ;
    cout<<endl<<n->right->left->data;
    cout<<endl<<n->right->right->data;
}