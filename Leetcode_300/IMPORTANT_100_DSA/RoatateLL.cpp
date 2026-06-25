#include <iostream>
#include <vector>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr || k == 0)
            return head;

        int len = 1;
        ListNode* tail = head;

        // Find length and last node
        while(tail->next){
            tail = tail->next;
            len++;
        }

        k = k % len;

        if(k == 0)
            return head;

        // Make circular list
        tail->next = head;

        int steps = len - k;

        ListNode* newTail = head;

        // Move to new tail
        for(int i = 1; i < steps; i++){
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};

// Create Linked List
ListNode* createList(vector<int> arr) {

    if(arr.size() == 0)
        return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print Linked List
void printList(ListNode* head) {

    while(head != nullptr) {
        cout << head->val;

        if(head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    vector<int> arr = {1,2,3,4,5};

    ListNode* head = createList(arr);

    cout << "Original List:\n";
    printList(head);

    Solution obj;

    head = obj.rotateRight(head, 2);

    cout << "After Rotation:\n";
    printList(head);

    return 0;
}