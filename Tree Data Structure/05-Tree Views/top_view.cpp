// Demonatrates how to print the top view of a binary tree

/* Top View : This means that we need to print the nodes that are visible when the tree is viewed from the top.
   The top view contains all nodes that are the first nodes at their respective horizontal distances from the root. */

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

void topView(Node* root){
    if(root == NULL) return;

    // Map to store the first node at each horizontal distance
    map<int, int> hdNodeMap;
    // Queue to perform level order traversal
    queue<pair<Node*, int>> q; // Pair of node and its horizontal distance

    q.push({root, 0}); // Root has horizontal distance 0

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        Node* currentNode = front.first;
        int hd = front.second;

        // If this horizontal distance is not already present in the map, add it
        if(hdNodeMap.find(hd) == hdNodeMap.end()){
            hdNodeMap[hd] = currentNode->data;
        }

        // Enqueue left and right children with updated horizontal distances
        if(currentNode->left != NULL){
            q.push({currentNode->left, hd - 1});
        }
        if(currentNode->right != NULL){
            q.push({currentNode->right, hd + 1});
        }
    }

    // Print the top view from the map
    for(auto it : hdNodeMap){
        cout<<it.second<<" ";
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    cout<<"Top View of the Binary Tree: ";
    topView(root);
    cout<<endl;

    return 0;
}

