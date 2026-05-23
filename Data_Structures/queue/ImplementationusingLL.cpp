#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    public:

    Node* head;
    Node* tail;

    Queue(){
        head = tail = NULL;
    }

    void push(int data){
        Node* newNode = new Node(data);
        if(empty()){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;

        }

    }

    void pop(){
        if(empty()){
            cout << "Nothing to pop here";
        }
        else{
            Node*temp = head;
            head = head->next;
            delete temp;
        }
    }
    int front(){
        return head->data;
    }
    bool empty(){
        return head == NULL;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(3);
    q.push(6);
    q.push(8);
    q.push(9);
    q.pop();
    
    while(!q.empty()){
        cout<< q.front() << " ";
        q.pop();

    }
    cout << endl;
    return 0 ;

};