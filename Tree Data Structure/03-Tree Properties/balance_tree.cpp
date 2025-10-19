// Checking if a binary tree is balanced or not

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

bool isBalancedUtil(Node* root, int& height){
    if(root == NULL){
        height = 0;
        return true; // An empty tree is balanced
    }

    int leftHeight = 0, rightHeight = 0;

    // Check if left subtree is balanced
    bool leftBalanced = isBalancedUtil(root->left, leftHeight);
    // Check if right subtree is balanced
    bool rightBalanced = isBalancedUtil(root->right, rightHeight);

    // Current node's height
    height = max(leftHeight, rightHeight) + 1;

    // A tree is balanced if both subtrees are balanced and the height difference is at most 1
    return leftBalanced && rightBalanced && abs(leftHeight - rightHeight) <= 1;
}

bool isBalanced(Node* root){
    int height = 0;
    return isBalancedUtil(root, height);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // Uncomment the next line to make the tree unbalanced
    // root->left->left->left = new Node(6);

    if(isBalanced(root)){
        cout<<"The tree is balanced."<<endl;
    } else {
        cout<<"The tree is NOT balanced."<<endl;
    }

    return 0;
}