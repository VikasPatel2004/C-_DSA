#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
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

// Helper: create a cycle at given position (pos = index where tail connects)
void createCycle(ListNode* head, int pos) {
    if (pos < 0) return;
    ListNode* tail = head;
    ListNode* cycleNode = nullptr;
    int index = 0;
    while (tail->next != nullptr) {
        if (index == pos) cycleNode = tail;
        tail = tail->next;
        index++;
    }
    if (cycleNode) tail->next = cycleNode;
}

int main() {
    Solution sol;

    // Example 1: No cycle
    vector<int> vals1 = {3,2,0,-4};
    ListNode* head1 = createList(vals1);
    cout << "Has Cycle? " << (sol.hasCycle(head1) ? "true" : "false") << endl;

    // Example 2: With cycle (tail connects to node at index 1)
    vector<int> vals2 = {3,2,0,-4};
    ListNode* head2 = createList(vals2);
    createCycle(head2, 1); // cycle at node with value 2
    cout << "Has Cycle? " << (sol.hasCycle(head2) ? "true" : "false") << endl;

    return 0;
}
