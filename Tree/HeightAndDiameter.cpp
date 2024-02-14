#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data =val;
        left=NULL;
        right=NULL;
    }
};

int calcHeight(Node* &root){
    if(root==NULL){
        return 0;
    }
    int l = calcHeight(root->left);
    int r = calcHeight(root->right);
    return max(l,r) +1;
}

int diameter(Node* &root){
    if(root==NULL){
        return 0;
    }
    int c = calcHeight(root->left) + calcHeight(root->right) + 1;
    int l = diameter(root->left);
    int r = diameter(root->right);

    return max(c,max(l,r));
}

int main(){
    Node* n = new Node(1);
    n->left = new Node(2);
    n->right= new Node(3);
    n->left->left = new Node(4);
    n->left->right = new Node(5);
    n->right->left= new Node(6);
    n->right->right= new Node(7);
    // cout<<calcHeight(n);
    cout<<diameter(n);
}