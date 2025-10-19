// Construct a bst from a sorted array

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

Node* sortedArrayToBSTUtil(vector<int>& arr, int start, int end){
    if(start > end){
        return NULL;
    }

    int mid = start + (end - start) / 2;
    Node* newNode = new Node(arr[mid]);

    newNode->left = sortedArrayToBSTUtil(arr, start, mid - 1);
    newNode->right = sortedArrayToBSTUtil(arr, mid + 1, end);

    return newNode;
}

Node* sortedArrayToBST(vector<int>& arr){
    return sortedArrayToBSTUtil(arr, 0, arr.size() - 1);
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    vector<int> arr = {-10, -3, 0, 5, 9};
    Node* root = sortedArrayToBST(arr);

    cout<<"Inorder Traversal of the constructed BST: ";
    inorder(root);
    cout<<endl;

    return 0;
}