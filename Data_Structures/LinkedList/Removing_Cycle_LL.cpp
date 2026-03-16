#include <iostream>
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        // Step 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        // Step 2: If no cycle, return NULL
        if (!isCycle) {
            return NULL;
        }

        // Step 3: Find the start of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {
    // Create nodes
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Link nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Uncomment below line to create a cycle
    node4->next = node2; // cycle back to node2

    Solution solution;
    ListNode* cycleStart = solution.detectCycle(node1);

    if (cycleStart != NULL) {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Note: Memory cleanup is skipped here because of the cycle.
    // In real applications, you'd need careful handling to avoid leaks.

    return 0;
}