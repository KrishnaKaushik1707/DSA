#include <iostream>
using namespace std;

// Defining a Node
struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DLL {
    Node* front;
    Node* rear;

public:
    DLL() {
        front = rear = NULL;
    }

    void insertbegin();
    void insertend();
    void deletebegin();
    void deleteend();
    void display();
};

void DLL::insertbegin() {
    Node* temp = new Node();
    int e;
    cout << "Enter the integer value: ";
    cin >> e;

    temp->data = e;
    temp->next = NULL;
    temp->prev = NULL;

    if (front == NULL) {
        front = rear = temp;
    } else {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
}

void DLL::insertend() {
    Node* temp = new Node();
    int e;
    cout << "Enter the integer value: ";
    cin >> e;

    temp->data = e;
    temp->next = NULL;
    temp->prev = NULL;

    if (front == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
}

void DLL::deletebegin() {
    if (front == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = front;
    cout << "Element deleted is: " << front->data << endl;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }

    delete temp;
}

void DLL::deleteend() {
    if (front == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = rear;
    cout << "Element deleted is: " << rear->data << endl;

    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }

    delete temp;
}

void DLL::display() {
    if (front == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = front;
    cout << "Doubly Linked List elements are: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    DLL obj;
    int ch;

    while (1) {
        cout << "\nOperations on Doubly Linked List: " << endl;
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
