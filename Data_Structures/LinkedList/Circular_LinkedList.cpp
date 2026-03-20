#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Traverse and display
void traverse() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}

// Insert at beginning
void insertAtBeginning(int data) {
    Node* newNode = new Node{data, nullptr};
    if (!head) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Insert at end
void insertAtEnd(int data) {
    Node* newNode = new Node{data, nullptr};
    if (!head) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

// Insert at position
void insertAtPosition(int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    Node* newNode = new Node{data, nullptr};
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != head) temp = temp->next;
    Node* toDelete = head;
    temp->next = head->next;
    head = head->next;
    delete toDelete;
}

// Delete from end
void deleteFromEnd() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != head) temp = temp->next;
    Node* toDelete = temp->next;
    temp->next = head;
    delete toDelete;
}

// Delete from position
void deleteFromPosition(int pos) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (pos == 1) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    if (toDelete == head) {
        cout << "Invalid position.\n";
        return;
    }
    temp->next = toDelete->next;
    delete toDelete;
}

// Search element
void search(int key) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Element " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Element " << key << " not found.\n";
}

// Demo
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    traverse();

    insertAtBeginning(5);
    traverse();

    insertAtPosition(15, 3);
    traverse();

    deleteFromBeginning();
    traverse();

    deleteFromEnd();
    traverse();

    deleteFromPosition(2);
    traverse();

    search(20);
    search(100);

    return 0;
}