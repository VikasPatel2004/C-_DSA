#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = next = NULL;
    }
};
 
 class doublyList {
    Node* head;
    Node* tail;

    public:
    doublyList(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front(){
        if(head == NULL){
            cout << "your DLL is empty";
        }
        else{
            Node* temp = head;
            head = head->next;
            if(head!=NULL){
                head->prev = NULL;
            }
            temp->next = NULL;
            delete temp;


        }


    }
    void pop_back(){
        if(head == NULL){
            cout << "the DLL is empty";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail!=NULL){
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;

    }
    void printList(){
        Node* temp = head;
        while(temp!=NULL){
            cout <<temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
 };
int main(){
    doublyList ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_back(1);
    ll.pop_front();
    ll.pop_back();
    ll.printList();

}