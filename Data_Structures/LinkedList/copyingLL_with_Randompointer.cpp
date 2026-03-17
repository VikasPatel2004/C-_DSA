#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        // Create the head copy and store mapping
        Node* newHead = new Node(head->val);
        m[head] = newHead;

        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        // First pass: copy all nodes and build next pointers
        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Second pass: assign random pointers
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL) {
            newTemp->random = m[oldTemp->random];  // Corrected
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

// Helper function to print list (for testing)
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node val: " << temp->val;
        if (temp->random) {
            cout << ", Random points to: " << temp->random->val;
        } else {
            cout << ", Random points to: NULL";
        }
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Build a sample list: 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    // Assign random pointers
    n1->random = n3; // 1's random -> 3
    n2->random = n1; // 2's random -> 1
    n3->random = n2; // 3's random -> 2

    cout << "Original list:" << endl;
    printList(n1);

    Solution sol;
    Node* copiedHead = sol.copyRandomList(n1);

    cout << "\nCopied list:" << endl;
    printList(copiedHead);

    return 0;
}