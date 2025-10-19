// C++ program to construct a binary tree from inorder and preorder traversals

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

Node* buildTreeUtil(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int& preIndex, unordered_map<int, int>& inMap){
    if(inStart > inEnd){
        return NULL;
    }

    // Pick current node from Preorder traversal using preIndex and increment preIndex
    int currVal = preorder[preIndex++];
    Node* newNode = new Node(currVal);

    // If this node has no children then return
    if(inStart == inEnd){
        return newNode;
    }

    // Find the index of this node in Inorder traversal
    int inIndex = inMap[currVal];

    // Using index in Inorder traversal, construct left and right subtrees
    newNode->left = buildTreeUtil(inorder, preorder, inStart, inIndex - 1, preIndex, inMap);
    newNode->right = buildTreeUtil(inorder, preorder, inIndex + 1, inEnd, preIndex, inMap);

    return newNode;
}

Node* buildTree(vector<int>& inorder, vector<int>& preorder){
    int n = inorder.size();
    int preIndex = 0;
    unordered_map<int, int> inMap;

    // Store the index of each value in Inorder traversal for quick lookup
    for(int i = 0; i < n; i++){
        inMap[inorder[i]] = i;
    }

    return buildTreeUtil(inorder, preorder, 0, n - 1, preIndex, inMap);
}   

void postorder(Node* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};

    Node* root = buildTree(inorder, preorder);

    cout<<"Postorder Traversal of the constructed tree: ";
    postorder(root);
    cout<<endl;

    return 0;
}

