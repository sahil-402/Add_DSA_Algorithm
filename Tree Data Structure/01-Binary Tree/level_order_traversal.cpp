/*
Level Order Traversal of a Binary Tree: Level order traversal visits nodes level by level from left to right.
This implementation uses a queue to facilitate the breadth-first traversal.
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

void levelOrderTraversal(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        cout<<current->data<<" ";

        if(current->left != NULL){
            q.push(current->left);
        }
        if(current->right != NULL){
            q.push(current->right);
        }
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Level Order Traversal: ";
    levelOrderTraversal(root);
    cout<<endl;

    return 0;
}
