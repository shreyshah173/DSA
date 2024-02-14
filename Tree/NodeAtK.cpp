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
        right = NULL;
    }
};

void printSubtree(Node* root,int k){
    if(root == NULL || k<0){
        return ;
    }
    if(k==0){
        cout<<root->data<<endl;
        return ;
    }
    printSubtree(root->left,k-1);
    printSubtree(root->right,k-1);
}

int printNode(Node* root,Node* target,int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printSubtree(root,k);
        return 0;
    }

    int dl = printNode(root->left,target,k);
    if(dl!=-1){
        if(dl+1 == k){
            cout<<root->data;
        }
        else{
            printSubtree(root->right,k-2-dl);
        }
        return 1+dl;
    }
    int dr = printNode(root->right,target,k);
    if(dr!=-1){
        if(dr+1 == k){
            cout<<root->data;
        }
        else{
            printSubtree(root->left,k-2-dr);
        }
        return 1+dr;
    }

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    printNode(root, root->left,1);
}