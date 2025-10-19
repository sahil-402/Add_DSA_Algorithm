// Calculating the diameter of a binary tree in C++

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

int diameterOfTreeUtil(Node* root, int& diameter){
    if(root == NULL){
        return 0; // Height of an empty tree is 0
    }
    int leftHeight = diameterOfTreeUtil(root->left, diameter);
    int rightHeight = diameterOfTreeUtil(root->right, diameter);

    // Update the diameter if the path through the current node is larger
    diameter = max(diameter, leftHeight + rightHeight);

    return max(leftHeight, rightHeight) + 1; // Return height of the tree
}   

int diameterOfTree(Node* root){
    int diameter = 0;
    diameterOfTreeUtil(root, diameter);
    return diameter;
}