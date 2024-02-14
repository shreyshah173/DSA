// flatten a binary tree 
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right= NULL;
    }
};

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int rh = height(root->right);
    int lh = height(root->right);
    return max(lh,rh) + 1;
}

void flatten(Node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return ;
    }
    if(root->left != NULL){
        flatten(root->left);

        Node* temp =root->right;
        root->right = root->left;
        root->left = NULL;
        Node* t =root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right =temp;
    }

    flatten(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    flatten(root);
    cout<<"Step1"<<endl;
    Node* temp = root;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->right;
    }
    return 0;

}