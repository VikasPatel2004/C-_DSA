#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value of the next node
        node->val = node->next->val;

        // Delete the next node
        ListNode* temp = node->next;
        node->next = temp->next;
        delete temp;
    }
};

// Function to insert at the end
void insert(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = nullptr;

    insert(head, 4);
    insert(head, 5);
    insert(head, 1);
    insert(head, 9);

    cout << "Original List: ";
    printList(head);

    // Delete node with value 5
    ListNode* node = head->next;

    Solution obj;
    obj.deleteNode(node);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}