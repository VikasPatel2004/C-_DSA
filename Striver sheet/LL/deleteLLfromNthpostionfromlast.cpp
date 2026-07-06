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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;

        // Find size
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Delete head node
        if (count == n) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        // Reach the previous node
        ListNode* temp1 = head;
        for (int i = 0; i < count - n - 1; i++) {
            temp1 = temp1->next;
        }

        // Delete node
        ListNode* del = temp1->next;
        temp1->next = del->next;
        delete del;

        return head;
    }
};

// Function to insert at end
void insert(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Function to print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = nullptr;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.removeNthFromEnd(head, 2);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}