#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            // Opening brackets
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }

            // Closing brackets
            else {

                // If stack is empty
                if (st.empty()) {
                    return false;
                }

                // Matching conditions
                if ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Stack should be empty at the end
        return st.empty();
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter brackets string: ";
    cin >> s;

    if (obj.isValid(s)) {
        cout << "Valid Parentheses" << endl;
    }
    else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}