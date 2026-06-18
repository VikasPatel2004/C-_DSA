#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {

        // Move all elements from s1 to s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into s1
        s1.push(x);

        // Move everything back to s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {

        int ans = s1.top();
        s1.pop();

        return ans;
    }
    
    int peek() {

        return s1.top();
    }
    
    bool empty() {

        return s1.empty();
    }
};

int main() {

    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;

    cout << "Popped element: " << q.pop() << endl;

    cout << "Front after pop: " << q.peek() << endl;

    if(q.empty()) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}