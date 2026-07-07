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

// Function to check palindrome
bool isPalindrome(ListNode* head) {

    // Step 1: Find the middle
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    ListNode* prev = NULL;
    ListNode* curr = slow;
    ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Step 3: Compare both halves
    ListNode* left = head;
    ListNode* right = prev;

    while (right != NULL) {

        if (left->val != right->val) {
            return false;
        }

        left = left->next;
        right = right->next;
    }

    return true;
}

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        cout << "Empty Linked List" << endl;
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

    if (isPalindrome(head))
        cout << "Palindrome Linked List" << endl;
    else
        cout << "Not a Palindrome Linked List" << endl;

    return 0;
}