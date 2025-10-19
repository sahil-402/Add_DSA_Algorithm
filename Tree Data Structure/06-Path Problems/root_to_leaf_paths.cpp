// C++ program to print all root to leaf paths in a binary tree

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

void rootToLeafPathsUtil(Node* root, vector<int>& path){
    if(root == NULL){
        return;
    }

    // Add the current node to the path
    path.push_back(root->data);

    // If it's a leaf node, print the path
    if(root->left == NULL && root->right == NULL){
        for(int val : path){
            cout<<val<<" ";
        }
        cout<<endl;
    } else {
        // Recur for left and right subtrees
        rootToLeafPathsUtil(root->left, path);
        rootToLeafPathsUtil(root->right, path);
    }

    // Backtrack: remove the current node from the path
    path.pop_back();
}

void rootToLeafPaths(Node* root){
    vector<int> path;
    rootToLeafPathsUtil(root, path);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Root to Leaf Paths:"<<endl;
    rootToLeafPaths(root);

    return 0;
}

