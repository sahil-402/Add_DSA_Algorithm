// Calculating the height of a binary tree in C++

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

int heightOfTree(Node* root){
    if(root == NULL){
        return 0; // Height of an empty tree is 0
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return max(leftHeight, rightHeight) + 1; // Height is max of left/right subtree heights plus 1 for the current node
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Height of the tree: "<<heightOfTree(root)<<endl;

    return 0;
}