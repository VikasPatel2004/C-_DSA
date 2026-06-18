#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {

    }

    void push(int x) {

        if(q1.empty()) {
            q1.push(x);
        }
        else {

            while(!q1.empty()) {
                int y = q1.front();
                q1.pop();
                q2.push(y);
            }

            q1.push(x);

            while(!q2.empty()) {
                int z = q2.front();
                q2.pop();
                q1.push(z);
            }
        }
    }

    int pop() {

        int ans = q1.front();
        q1.pop();

        return ans;
    }

    int top() {

        return q1.front();
    }

    bool empty() {

        return q1.empty();
    }
};

int main() {

    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    cout << "Popped: " << st.pop() << endl;

    cout << "Top after pop: " << st.top() << endl;

    if(st.empty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}