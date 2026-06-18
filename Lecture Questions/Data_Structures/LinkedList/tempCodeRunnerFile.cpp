#include <iostream>
using namespace std;

class Node {
public:
    int data;       // node ka data
    Node* next;     // pointer to next node

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
private:
    Node* head;     // head of list
    Node* tail;     // tail of list

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.printList();  // Output: 3 -> 2 -> 1 -> NULL

    return 0;
}