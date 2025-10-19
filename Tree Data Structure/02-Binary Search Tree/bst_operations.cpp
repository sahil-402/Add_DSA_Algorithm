// Binary Search Tree Basic Operations: 
// This implements the basic operation i.e., insertion and deletion in a Binary Search Tree (BST).

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

// Helper function to find the node with minimum value in a given BST
Node* minValueNode(Node* node){
    Node* current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int val){
    if(root == NULL){
        return root;
    }
    if(val < root->data){
        root->left = deleteNode(root->left, val);
    } else if(val > root->data){
        root->right = deleteNode(root->right, val);
    } else {
        // Node with only one child or no child
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
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

    cout<<"Inorder Traversal of the given tree: ";
    inorder(root);
    cout<<endl;

    cout<<"Delete 20\n";
    root = deleteNode(root, 20);
    cout<<"Inorder Traversal after deleting 20: ";
    inorder(root);
    cout<<endl;

    cout<<"Delete 30\n";
    root = deleteNode(root, 30);
    cout<<"Inorder Traversal after deleting 30: ";
    inorder(root);
    cout<<endl;

    cout<<"Delete 50\n";
    root = deleteNode(root, 50);
    cout<<"Inorder Traversal after deleting 50: ";
    inorder(root);
    cout<<endl;

    return 0;
}

