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

// Function to reverse nodes in groups of k
ListNode* reverseKGroup(ListNode* head, int k) {

    if (head == NULL) {
        return NULL;
    }

    ListNode* temp = head;
    int count = 0;

    // Check if at least k nodes exist
    while (count < k) {
        if (temp == NULL) {
            return head;      // Less than k nodes, do not reverse
        }
        temp = temp->next;
        count++;
    }

    // Recursively reverse the remaining linked list
    ListNode* prev = reverseKGroup(temp, k);

    // Reverse current group
    temp = head;
    count = 0;

    while (count < k) {

        ListNode* next = temp->next;

        temp->next = prev;

        prev = temp;

        temp = next;

        count++;
    }

    return prev;
}

// Function to print linked list
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

    cout << "Enter value of k: ";
    cin >> k;

    if (n == 0) {
        return 0;
    }

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

    head = reverseKGroup(head, k);

    cout << "\nLinked List after reversing in groups of " << k << ":\n";
    printList(head);

    return 0;
}