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

int Count(Node* &node){
    int count = 1;
    if(node->left!=NULL){
        count += Count(node->left);
    }
    if(node->right!=NULL){
        count += Count(node->right);
    }
    return count;
}


int main(){
    Node* n = new Node(1);
    n->left = new Node(2);
    n->right= new Node(3);
    n->left->left = new Node(4);
    n->left->right = new Node(5);
    n->right->left= new Node(6);
    n->right->right= new Node(7);
    int a = Count(n);
    cout<<a;
}