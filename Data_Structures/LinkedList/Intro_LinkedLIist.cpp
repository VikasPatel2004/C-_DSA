#include <iostream> 
using namespace std ;

class Node{      // ye hamne class banai hai ki node me kya hoga
    public:
    int data;    // ye node ka data hai
    Node* next;  // ye node ka pointer hai jo memory store karega

    Node(int val){
        data=val;  // jo value hame dalni hai wo dalwaenge
        next=NULL;    
    }

};

 class List{    // ye ham class bana rahe hai ki linked list me kya hoga
    Node* head;  // ye dono private me honge 
    Node* tail;

    List(){
        head = tail = NULL;
    }
    void Push_front(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
    }

 }

int main (){

}