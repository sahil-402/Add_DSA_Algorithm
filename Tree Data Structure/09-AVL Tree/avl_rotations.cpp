// Implementing AVL Tree with insertion and rotations

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
        height = 1; // New node is initially added at leaf
    }
};

int getHeight(Node* node){
    if(node == NULL) return 0;
    return node->height;
}

int getBalanceFactor(Node* node){
    if(node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

Node* leftRightRotate(Node* node){
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

Node* rightLeftRotate(Node* node){
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

Node* insert(Node* node, int val){
    // Perform the normal BST insertion
    if(node == NULL){
        return new Node(val);
    }
    if(val < node->data){
        node->left = insert(node->left, val);
    } else if(val > node->data){
        node->right = insert(node->right, val);
    } else {
        // Duplicate keys are not allowed in the AVL tree
        return node;
    }

    // Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor of this ancestor node to check whether it became unbalanced
    int balance = getBalanceFactor(node);

    // If the node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if(balance > 1 && val < node->left->data){
        return rightRotate(node);
    }

    // Right Right Case
    if(balance < -1 && val > node->right->data){
        return leftRotate(node);
    }

    // Left Right Case
    if(balance > 1 && val > node->left->data){
        return leftRightRotate(node);
    }

    // Right Left Case
    if(balance < -1 && val < node->right->data){
        return rightLeftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

void preOrder(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main(){
    Node* root = NULL;

    // Constructing AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Preorder traversal of the constructed AVL tree
    cout<<"Preorder traversal of the AVL tree is: ";
    preOrder(root);
    cout<<endl;

    return 0;
}

