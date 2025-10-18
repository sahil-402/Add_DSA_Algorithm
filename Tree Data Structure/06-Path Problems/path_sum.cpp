// Path Sum in a Binary Tree
/* Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up
   all the values along the path equals the given sum.
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

bool hasPathSum(Node* root, int sum){
    if(root == NULL){
        return (sum == 0);
    }

    // Subtract the current node's value from the sum
    sum -= root->data;

    // If it's a leaf node, check if the remaining sum is zero
    if(root->left == NULL && root->right == NULL){
        return (sum == 0);
    }

    // Recur for left and right subtrees
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);

    int sum = 22;
    if(hasPathSum(root, sum)){
        cout<<"There is a root-to-leaf path with sum "<<sum<<endl;
    } else {
        cout<<"There is NO root-to-leaf path with sum "<<sum<<endl;
    }

    return 0;
}
