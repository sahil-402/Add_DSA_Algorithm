// Implement zigzag traversal of a binary tree

/* Zig Zag Traversal: It is also known as spiral order traversal. In this traversal, the nodes of the binary tree
   are printed in a zigzag manner, i.e., the first level is printed from left to right, the second level
   from right to left, the third level from left to right, and so on.  This can be achieved using two stacks to store the nodes of the
   current level and the next level, and a boolean flag to indicate the direction of traversal at each level. */
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

void zigzagTraversal(Node* root){
    if(root == NULL) return;

    stack<Node*> currentLevel;
    stack<Node*> nextLevel;
    bool leftToRight = true;

    currentLevel.push(root);

    while(!currentLevel.empty()){
        Node* currentNode = currentLevel.top();
        currentLevel.pop();

        if(currentNode){
            cout<<currentNode->data<<" ";

            // Store nodes of next level in nextLevel stack
            if(leftToRight){
                if(currentNode->left) nextLevel.push(currentNode->left);
                if(currentNode->right) nextLevel.push(currentNode->right);
            } else {
                if(currentNode->right) nextLevel.push(currentNode->right);
                if(currentNode->left) nextLevel.push(currentNode->left);
            }
        }

        // If current level is finished, swap stacks and change traversal direction
        if(currentLevel.empty()){
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"Zigzag Traversal of the Binary Tree: ";
    zigzagTraversal(root);
    cout<<endl;

    return 0;
}