#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0); // Dummy node
        ListNode* current = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {

            int val1 = 0;
            int val2 = 0; // Reset every iteration

            if (l1 != NULL)
                val1 = l1->val;

            if (l2 != NULL)
                val2 = l2->val;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;
        }

        return dummy->next;
    }
};

// Function to create a linked list
ListNode* createList(int arr[], int n) {

    if (n == 0)
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Function to print a linked list
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    // Number 342 (stored as 2 -> 4 -> 3)
    int arr1[] = {2, 4, 3};

    // Number 465 (stored as 5 -> 6 -> 4)
    int arr2[] = {5, 6, 4};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    ListNode* l1 = createList(arr1, n1);
    ListNode* l2 = createList(arr2, n2);

    Solution obj;
    ListNode* ans = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(ans);

    return 0;
}