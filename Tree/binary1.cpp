// balanced height binary tree 
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

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh) + 1;
}

bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    if(isBalanced(root->left)== false){
        return false;
    }
    if(isBalanced(root->right)== false){
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
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

    cout<<isBalanced(n);
}