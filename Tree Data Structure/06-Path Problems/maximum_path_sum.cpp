// Calculating the maximum path sum in a binary tree

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

int maxPathSumUtil(Node* root, int& maxSum){
    if(root == NULL){
        return 0;
    }

    // Recursively get the maximum path sum of left and right subtrees
    int leftSum = max(0, maxPathSumUtil(root->left, maxSum)); // Ignore negative sums
    int rightSum = max(0, maxPathSumUtil(root->right, maxSum)); // Ignore negative sums

    // Update the maximum path sum if the path through the current node is larger
    maxSum = max(maxSum, leftSum + rightSum + root->data);

    // Return the maximum path sum including the current node
    return root->data + max(leftSum, rightSum);
}

int maxPathSum(Node* root){
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    return maxSum;
}

int main(){
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout<<"Maximum Path Sum: "<<maxPathSum(root)<<endl;

    return 0;
}

