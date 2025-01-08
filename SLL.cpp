#include <iostream>
using namespace std;

// Defining a Node
struct Node {
    int data;
    Node* link;
};

class SLL {
    Node* front;
    Node* rear;

public:
    SLL() {
        front = rear = NULL;
    }

    void insertbegin();
    void insertend();
    void deletebegin();
    void deleteend();
    void display();
};

void SLL::insertbegin() {
    Node* temp = new Node();
    int e;
    cout << "Enter the integer value: ";
    cin >> e;

    temp->data = e;
    temp->link = NULL;

    if (front == NULL) {
        front = rear = temp;
    } else {
        temp->link = front;
        front = temp;
    }
}

void SLL::insertend() {
    Node* temp = new Node();
    int e;
    cout << "Enter the integer value: ";
    cin >> e;

    temp->data = e;
    temp->link = NULL;

    if (front == NULL) {
        front = rear = temp;
    } else {
        rear->link = temp;
        rear = temp;
    }
}

void SLL::deletebegin() {
    if (front == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = front;
    cout << "Element deleted: " << front->data << endl;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->link;
    }

    delete temp; // Freeing the node
}

void SLL::deleteend() {
    if (front == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    cout << "Element deleted: " << rear->data << endl;

    if (front == rear) {
        delete rear;
        front = rear = NULL;
    } else {
        Node* temp = front;
        while (temp->link != rear) {
            temp = temp->link;
        }
        temp->link = NULL;
        delete rear;
        rear = temp;
    }
}

void SLL::display() {
    if (front == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = front;
    cout << "Single Linked List elements are: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

int main() {
    SLL obj;
    int ch;

    while (1) {
        cout << "Operations on Single Linked List: " << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Delete from beginning" << endl;
        cout << "4. Delete from end" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            obj.insertbegin();
            break;
        case 2:
            obj.insertend();
            break;
        case 3:
            obj.deletebegin();
            break;
        case 4:
            obj.deleteend();
            break;
        case 5:
            obj.display();
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
