#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }
        Node* curr = head;
        while (curr != NULL) {
            if (curr->child != NULL) {
                // flatten the child node
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // find the tail
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // attach tail with next pointer
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

// Helper function to print the flattened list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example setup for testing
int main() {
    // Create nodes
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    // Link main list: 1 - 2 - 3 - 4 - 5 - 6
    head->next = node2; node2->prev = head;
    node2->next = node3; node3->prev = node2;
    node3->next = node4; node4->prev = node3;
    node4->next = node5; node5->prev = node4;
    node5->next = node6; node6->prev = node5;

    // Add child list: node3 -> child -> 7 - 8
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    node7->next = node8; node8->prev = node7;
    node3->child = node7;

    Solution sol;
    Node* flattened = sol.flatten(head);

    cout << "Flattened list: ";
    printList(flattened);

    return 0;
}
