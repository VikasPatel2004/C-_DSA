#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:

    stack<long long> st;
    long long minval;

    MinStack() {

    }

    void push(int val) {

        if(st.empty()) {
            st.push(val);
            minval = val;
        }

        else if(val < minval) {

            // store encoded value
            st.push(2LL * val - minval);

            // update minimum
            minval = val;
        }

        else {
            st.push(val);
        }
    }

    void pop() {

        if(st.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        // encoded value found
        if(st.top() < minval) {

            // restore previous minimum
            minval = 2 * minval - st.top();
        }

        st.pop();
    }

    int top() {

        if(st.empty()) {
            return -1;
        }

        // encoded value means current min is actual top
        if(st.top() < minval) {
            return minval;
        }

        return st.top();
    }

    int getMin() {

        if(st.empty()) {
            return -1;
        }

        return minval;
    }
};

int main() {

    MinStack s;

    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << "Top Element: " << s.top() << endl;
    cout << "Minimum Element: " << s.getMin() << endl;

    s.pop();

    cout << "\nAfter Pop:\n";

    cout << "Top Element: " << s.top() << endl;
    cout << "Minimum Element: " << s.getMin() << endl;

    return 0;
}