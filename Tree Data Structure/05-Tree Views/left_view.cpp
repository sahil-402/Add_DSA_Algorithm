// Demonstates how to print the left view of a binary tree

/* Left View : This means that we need to print the nodes that are visible when the tree is viewed from the left side.
   The left view contains all nodes that are the first nodes at their respective levels. */

#include<bits/stdc++.h>
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

void leftViewUtil(Node* root, int level, int& maxLevel){
    if(root == NULL){
        return;
    }
    // If this is the first node of its level
    if(level > maxLevel){
        cout<<root->data<<" ";
        maxLevel = level;
    }
    // Recur for left and right subtrees
    leftViewUtil(root->left, level + 1, maxLevel);
    leftViewUtil(root->right, level + 1, maxLevel);
}   

void leftView(Node* root){
    int maxLevel = 0;
    leftViewUtil(root, 1, maxLevel);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    cout<<"Left View of the Binary Tree: ";
    leftView(root);
    cout<<endl;

    return 0;
}