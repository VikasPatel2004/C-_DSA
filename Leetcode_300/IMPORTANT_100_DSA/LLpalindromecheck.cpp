#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Compare halves
        ListNode* left = head;
        ListNode* right = prev;
        while (right != NULL) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

// Helper: create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper: print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1: Palindrome [1,2,2,1]
    vector<int> vals1 = {1,2,2,1};
    ListNode* head1 = createList(vals1);
    cout << "List: "; printList(head1);
    cout << "Is Palindrome? " << (sol.isPalindrome(head1) ? "true" : "false") << endl;

    // Example 2: Not Palindrome [1,2]
    vector<int> vals2 = {1,2};
    ListNode* head2 = createList(vals2);
    cout << "List: "; printList(head2);
    cout << "Is Palindrome? " << (sol.isPalindrome(head2) ? "true" : "false") << endl;

    return 0;
}
