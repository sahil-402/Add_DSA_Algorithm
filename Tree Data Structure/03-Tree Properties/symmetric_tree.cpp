// Check if a binary tree is symmetric around its center

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

bool isMirror(Node* leftSubtree, Node* rightSubtree){
    if(leftSubtree == NULL && rightSubtree == NULL){
        return true; // Both subtrees are empty
    }
    if(leftSubtree == NULL || rightSubtree == NULL){
        return false; // One subtree is empty, the other is not
    }
    // Check if the current nodes are equal and recurse for children in mirrored fashion
    return (leftSubtree->data == rightSubtree->data) &&
           isMirror(leftSubtree->left, rightSubtree->right) &&
           isMirror(leftSubtree->right, rightSubtree->left);
}

bool isSymmetric(Node* root){
    if(root == NULL){
        return true; // An empty tree is symmetric
    }
    return isMirror(root->left, root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if(isSymmetric(root)){
        cout<<"The tree is symmetric."<<endl;
    } else {
        cout<<"The tree is NOT symmetric."<<endl;
    }

    return 0;
}