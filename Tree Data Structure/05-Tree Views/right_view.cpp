// Demonstrate the right view of a binary tree

/* Right View : This means that we need to print the nodes that are visible when the tree is viewed from the right side.
   The right view contains all nodes that are the last nodes at their respective levels. */

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

void rightViewUtil(Node* root, int level, int& maxLevel){
    if(root == NULL){
        return;
    }
    // If this is the first node of its level
    if(level > maxLevel){
        cout<<root->data<<" ";
        maxLevel = level;
    }
    // Recur for right and left subtrees
    rightViewUtil(root->right, level + 1, maxLevel);
    rightViewUtil(root->left, level + 1, maxLevel);
}

void rightView(Node* root){
    int maxLevel = 0;
    rightViewUtil(root, 1, maxLevel);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    cout<<"Right View of the Binary Tree: ";
    rightView(root);
    cout<<endl;

    return 0;
}
