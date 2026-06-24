#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Move prev to node before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* reversePrev = nullptr;
        ListNode* reverseCurr = curr;

        // Step 2: Reverse sublist
        for (int i = left; i <= right; i++) {
            ListNode* next = reverseCurr->next;
            reverseCurr->next = reversePrev;
            reversePrev = reverseCurr;
            reverseCurr = next;
        }

        // Step 3: Connect back
        prev->next = reversePrev;
        curr->next = reverseCurr;

        return dummy.next;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create linked list from array
ListNode* createList(int arr[], int n) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int i = 0; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return dummy->next;
}

int main() {
    int arr[] = {1,2,3,4,5};
    ListNode* head = createList(arr, 5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.reverseBetween(head, 2, 4);

    cout << "After reversing from 2 to 4: ";
    printList(head);  // Expected: 1 -> 4 -> 3 -> 2 -> 5

    return 0;
}
