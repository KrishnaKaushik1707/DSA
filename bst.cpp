#include <iostream>
using namespace std;

// Define a node structure
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

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        // Create a new node if root is null
        return new Node(value);
    }

    // Recursively insert into the left or right subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// In-order traversal of BST (prints sorted values)
void Display(Node* root) {
    if (root != nullptr) {
        Display(root->left);  // Visit left subtree
        cout << root->data << " ";    // Visit root node
        Display(root->right); // Visit right subtree
    }
}

// Function to search for a value in the BST
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false; // Value not found
    }
    if (root->data == value) {
        return true; // Value found
    }

    // Search in left or right subtree
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node* root = nullptr; // Initialize root
    int ch, value;

    while (1) {
        cout << "\nOperations on BST: " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            cout << "Value inserted successfully!" << endl;
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value)) {
                cout << "Value found in the tree!" << endl;
            } else {
                cout << "Value not found." << endl;
            }
            break;

        case 3:
            cout << "Tree (In-order Traversal): ";
            Display(root);
            cout << endl;
            break;

        case 4:
            cout << "Exiting program..." << endl;
            return 0;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }
}

