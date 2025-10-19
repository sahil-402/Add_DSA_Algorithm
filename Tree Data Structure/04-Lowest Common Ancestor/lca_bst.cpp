// Least common Ancestor in a Binary Search Tree in C++

/* In a Binary Search Tree (BST), the Lowest Common Ancestor (LCA) of two nodes p and q is defined as the lowest node
   that has both p and q as descendants (where we allow a node to be a descendant of itself). 
   The properties of BST help in efficiently finding the LCA.
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

Node* lowestCommonAncestor(Node* root, int p, int q){
    if(root == NULL){
        return NULL;
    }

    // If both p and q are smaller than root, then LCA lies in left subtree
    if(p < root->data && q < root->data){
        return lowestCommonAncestor(root->left, p, q);
    }
    // If both p and q are greater than root, then LCA lies in right subtree
    if(p > root->data && q > root->data){
        return lowestCommonAncestor(root->right, p, q);
    }
    // If we reach here, then root is the LCA
    return root;
}

int main(){
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    int p = 2, q = 8;
    Node* lca = lowestCommonAncestor(root, p, q);
    if(lca != NULL){
        cout<<"Lowest Common Ancestor of "<<p<<" and "<<q<<" is: "<<lca->data<<endl;
    } else {
        cout<<"Lowest Common Ancestor not found."<<endl;
    }

    return 0;
}