// Implementing vertical order traversal of a binary tree

/* Vertical Order Traversal: In this traversal, nodes are printed column by column,
   from leftmost column to rightmost column. Nodes in the same column are printed
   from top to bottom. This can be achieved by using a map to store nodes at each
   horizontal distance from the root, and performing a level order traversal to
   populate the map.
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

void verticalOrderTraversal(Node* root){
    if(root == NULL) return;

    // Map to store nodes at each horizontal distance
    map<int, vector<int>> hdNodeMap;
    // Queue to perform level order traversal
    queue<pair<Node*, int>> q; // Pair of node and its horizontal distance

    q.push({root, 0}); // Root has horizontal distance 0

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        Node* currentNode = front.first;
        int hd = front.second;

        // Store the current node in the map for this horizontal distance
        hdNodeMap[hd].push_back(currentNode->data);

        // Enqueue left and right children with updated horizontal distances
        if(currentNode->left != NULL){
            q.push({currentNode->left, hd - 1});
        }
        if(currentNode->right != NULL){
            q.push({currentNode->right, hd + 1});
        }
    }

    // Print the vertical order from the map
    for(auto it : hdNodeMap){
        for(int val : it.second){
            cout<<val<<" ";
        }
        cout<<endl; // New line for each vertical level
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

    cout<<"Vertical Order Traversal of the Binary Tree:"<<endl;
    verticalOrderTraversal(root);

    return 0;
}
