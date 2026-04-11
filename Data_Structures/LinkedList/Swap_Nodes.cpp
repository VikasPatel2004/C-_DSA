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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* prev = nullptr;

        while (first != nullptr && second != nullptr) {
            ListNode* third = second->next;
            second->next = first;

            if (prev != nullptr) {
                prev->next = second;
            } else {
                head = second; // update head after first swap
            }

            prev = first;
            first->next = third; // connect the swapped pair to the rest
            first = third;

            if (third != nullptr) {
                second = third->next;
            } else {
                second = nullptr;
            }
        }
        return head;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    head = sol.swapPairs(head);

    // Output should be: 2 1 4 3
    printList(head);

    return 0;
}