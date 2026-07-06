#include <iostream>
using namespace std;

// Definition for singly linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {

    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;

    while(curr != NULL) {

        next = curr->next;    // Store next node

        curr->next = prev;    // Reverse the link

        prev = curr;          // Move prev one step ahead

        curr = next;          // Move curr one step ahead
    }

    return prev;
}

// Function to print linked list
void printList(ListNode* head) {

    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if(n == 0) {
        cout << "Linked List is empty." << endl;
        return 0;
    }

    int x;

    cout << "Enter node values: ";

    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for(int i = 1; i < n; i++) {

        cin >> x;

        temp->next = new ListNode(x);

        temp = temp->next;
    }

    cout << "\nOriginal Linked List:\n";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed Linked List:\n";
    printList(head);

    return 0;
}