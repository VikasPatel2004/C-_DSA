#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
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
                Node* childHead = flatten(curr->child);
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;

                // find the tail of the child list
                Node* tail = childHead;
                while (tail->next != NULL) {
                    tail = tail->next;
                }

                // attach tail with next pointer
                if (next != NULL) {
                    tail->next = next;
                    next->prev = tail;   // ✅ correct linkage
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

// Helper function to print flattened list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->val;
        if (curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Example: build a small multilevel doubly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Add child list to node 3
    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->prev = head->next->next->child;

    // Flatten
    Solution sol;
    Node* flatHead = sol.flatten(head);

    // Print flattened list
    printList(flatHead);

    return 0;
}