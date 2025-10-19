// Least Common Ancestor in a Binary Tree in C++

/* Least Common Ancestor (LCA) of two nodes p and q in a binary tree is defined as the lowest node
   that has both p and q as descendants (where we allow a node to be a descendant of itself). */

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
    if(root->data == p || root->data == q){
        return root;
    }

    Node* leftLCA = lowestCommonAncestor(root->left, p, q);
    Node* rightLCA = lowestCommonAncestor(root->right, p, q);

    if(leftLCA && rightLCA){
        return root; // If both sides return non-null, this is the LCA
    }
    return (leftLCA != NULL) ? leftLCA : rightLCA; // Return non-null child
}

int main(){
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    int p = 5, q = 1;
    Node* lca = lowestCommonAncestor(root, p, q);
    if(lca != NULL){
        cout<<"Lowest Common Ancestor of "<<p<<" and "<<q<<" is: "<<lca->data<<endl;
    } else {
        cout<<"Lowest Common Ancestor not found."<<endl;
    }

    return 0;
}