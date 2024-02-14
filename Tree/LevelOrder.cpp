#include <iostream>
#include <queue>
using namespace std;

class Node{
    public :
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(Node* root){
    if(root==NULL){
        return ;
    }
    queue<Node*> qu;
    qu.push(root);
    qu.push(NULL);
    while(!qu.empty()){
        Node* node = qu.front();
        qu.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left !=NULL){
                qu.push(node->left);
            }
            if(node->right !=NULL){
                qu.push(node->right);
            }
        }
        else if(!qu.empty()){
            qu.push(NULL);
        }
    }
}

int SumAtK(Node* root,int k){
    if(root==NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main(){
    Node* n = new Node(1);
    n->left = new Node(2);
    n->right= new Node(3);
    n->left->left = new Node(4);
    n->left->right = new Node(5);
    n->right->left= new Node(6);
    n->right->right= new Node(7);
    printLevelOrder(n);

    // int a =SumAtK(n,2);
    // cout<<a<<endl;
    
}
