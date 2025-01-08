#include <iostream>
using namespace std;

// Define a structure for tree nodes
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert nodes recursively
Node* createTree() {
    int data;
    cout << "Enter node value (-1 for no node): ";
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    Node* root = new Node(data);
    cout << "Enter left child of " << data << ":\n";
    root->left = createTree();

    cout << "Enter right child of " << data << ":\n";
    root->right = createTree();

    return root;
}

// Preorder traversal: root -> left -> right
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Inorder traversal: left -> root -> right
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Postorder traversal: left -> right -> root
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Main function
int main() {
    cout << "Build your binary tree:\n";
    Node* root = createTree();

    cout << "\nTree Traversals:\n";

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}

