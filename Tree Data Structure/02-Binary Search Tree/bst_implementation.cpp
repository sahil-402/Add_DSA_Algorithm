/* Binary Search Tree Implementation in C++ : Binary Search Tree (BST) is a node-based binary tree data structure
   where each node has at most two children referred to as the left child and the right child.
   For each node, all elements in the left subtree are less than the node, and all elements
   in the right subtree are greater than the node.
*/

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

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(Node* root, int val){
    if(root == NULL){
        return false;
    }
    if(root->data == val){
        return true;
    }
    if(val < root->data){
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout<<"Inorder Traversal of the BST: ";
    inorder(root);
    cout<<endl;

    int key = 40;
    if(search(root, key)){
        cout<<key<<" found in the BST."<<endl;
    } else {
        cout<<key<<" not found in the BST."<<endl;
    }

    key = 90;
    if(search(root, key)){
        cout<<key<<" found in the BST."<<endl;
    } else {
        cout<<key<<" not found in the BST."<<endl;
    }

    return 0;
}