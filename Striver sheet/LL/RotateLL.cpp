#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to rotate the linked list
ListNode* rotateRight(ListNode* head, int k) {

    // Base Case
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    // Find length and last node
    ListNode* tail = head;
    int len = 1;

    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    // Reduce unnecessary rotations
    k = k % len;

    if (k == 0) {
        return head;
    }

    // Make the linked list circular
    tail->next = head;

    // Find the new tail
    ListNode* newTail = head;

    for (int i = 1; i < len - k; i++) {
        newTail = newTail->next;
    }

    // New head
    ListNode* newHead = newTail->next;

    // Break the circular list
    newTail->next = NULL;

    return newHead;
}

// Function to print the linked list
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    int n, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        return 0;
    }

    cout << "Enter value of k: ";
    cin >> k;

    cout << "Enter node values: ";

    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    cout << "\nOriginal Linked List:\n";
    printList(head);

    head = rotateRight(head, k);

    cout << "\nLinked List after rotating by " << k << " positions:\n";
    printList(head);

    return 0;
}