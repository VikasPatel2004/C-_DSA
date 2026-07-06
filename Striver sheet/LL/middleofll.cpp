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

// Function to find the middle node
ListNode* middleNode(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    // Fast moves 2 steps, Slow moves 1 step
    while(fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to print the linked list
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
        return 0;
    }

    cout << "Enter node values: ";

    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* tail = head;

    for(int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    cout << "\nLinked List: ";
    printList(head);

    ListNode* middle = middleNode(head);

    cout << "Middle Node = " << middle->val << endl;

    return 0;
}