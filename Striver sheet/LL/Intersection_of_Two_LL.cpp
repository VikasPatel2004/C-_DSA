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

// Function to find intersection node
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    ListNode* p = headA;
    ListNode* q = headB;

    while (p != q) {

        if (p == NULL) {
            p = headB;
        }
        else {
            p = p->next;
        }

        if (q == NULL) {
            q = headA;
        }
        else {
            q = q->next;
        }
    }

    return p;
}

int main() {

    // Common Part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    ListNode* ans = getIntersectionNode(headA, headB);

    if (ans != NULL) {
        cout << "Intersection Node = " << ans->val << endl;
    }
    else {
        cout << "No Intersection" << endl;
    }

    return 0;
}