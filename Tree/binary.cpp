#include<iostream>
using namespace std;

struct node{
    int data;
    struct  node* right;
    struct  node* left;

    node(int val){
        data =val;
        left =NULL;
        right=NULL;
    }
};

void PreOrder(struct node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<",";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<",";
    InOrder(root->right);
}

void PostOrder(struct node* root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<",";
}
int main(){
    struct node* root = new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PostOrder(root);
}