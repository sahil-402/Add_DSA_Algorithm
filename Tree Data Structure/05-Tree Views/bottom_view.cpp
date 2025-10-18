// Demonstrates the bottom view of a binary tree

/* Bottom View : This means that we need to print the nodes that are visible when the tree is viewed from the bottom.
   The bottom view contains all nodes that are the last nodes at their respective horizontal distances from the root. */

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

void bottomView(Node* root){
    if(root == NULL) return;

    // Map to store the last node at each horizontal distance
    map<int, int> hdNodeMap;
    // Queue to perform level order traversal
    queue<pair<Node*, int>> q; // Pair of node and its horizontal distance

    q.push({root, 0}); // Root has horizontal distance 0

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        Node* currentNode = front.first;
        int hd = front.second;

        // Update the map with the current node for this horizontal distance
        hdNodeMap[hd] = currentNode->data;

        // Enqueue left and right children with updated horizontal distances
        if(currentNode->left != NULL){
            q.push({currentNode->left, hd - 1});
        }
        if(currentNode->right != NULL){
            q.push({currentNode->right, hd + 1});
        }
    }

    // Print the bottom view from the map
    for(auto it : hdNodeMap){
        cout<<it.second<<" ";
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->right = new Node(7);
    root->left->right->right->right = new Node(8);

    cout<<"Bottom View of the Binary Tree: ";
    bottomView(root);
    cout<<endl;

    return 0;
}
