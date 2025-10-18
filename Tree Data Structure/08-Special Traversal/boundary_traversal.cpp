// Implementing boundary traversal of a binary tree
/* Boundary Traversal: In this traversal, we need to print the boundary nodes of the binary tree
   in an anti-clockwise direction starting from the root. The boundary includes the left boundary,
   all the leaf nodes, and the right boundary (in reverse order).
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

bool isLeaf(Node* node){
    return (node->left == NULL && node->right == NULL);
}

void addLeftBoundary(Node* root, vector<int>& res){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

void addLeaves(Node* root, vector<int>& res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left){
        addLeaves(root->left, res);
    }
    if(root->right){
        addLeaves(root->right, res);
    }
}

void addRightBoundary(Node* root, vector<int>& res){
    Node* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    // Add right boundary in reverse order
    for(int i = temp.size() - 1; i >= 0; i--){
        res.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(Node* root){
    vector<int> res;
    if(root == NULL) return res;

    if(!isLeaf(root)){
        res.push_back(root->data); // Add root if it's not a leaf
    }

    addLeftBoundary(root, res); // Add left boundary
    addLeaves(root, res);       // Add all leaf nodes
    addRightBoundary(root, res); // Add right boundary

    return res;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    vector<int> result = boundaryTraversal(root);
    cout<<"Boundary Traversal of the Binary Tree: ";
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}