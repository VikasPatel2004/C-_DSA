#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]); // push opening character
            } else { // closing condition
                if (st.empty()) {
                    return false; // nothing to pop
                }
                if ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter a string with brackets: ";
    cin >> s;

    if (sol.isValid(s)) {
        cout << "Valid parentheses string ✅" << endl;
    } else {
        cout << "Invalid parentheses string ❌" << endl;
    }

    return 0;
}
