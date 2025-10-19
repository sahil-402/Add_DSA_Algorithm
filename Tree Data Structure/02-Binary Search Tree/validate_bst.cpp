/* Validating a Binary Search Tree (BST): 
 A BST is valid if for every node, all values in the left subtree are less than the node's value and all 
 values in the right subtree are greater than the node's value. */

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

bool validateBSTUtil(Node* node, long long minVal, long long maxVal){
    if(node == NULL) return true;

    if(node->data <= minVal || node->data >= maxVal){
        return false;
    }

    return validateBSTUtil(node->left, minVal, node->data) &&
           validateBSTUtil(node->right, node->data, maxVal);
}

bool validateBST(Node* root){
    return validateBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    if(validateBST(root)){
        cout<<"The tree is a valid Binary Search Tree."<<endl;
    } else {
        cout<<"The tree is NOT a valid Binary Search Tree."<<endl;
    }

    return 0;
}
