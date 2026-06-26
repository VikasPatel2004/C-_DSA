#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int>> &M, int n) {

    stack<int> st;

    // Step 1: Push all people into stack
    for(int i = 0; i < n; i++) {
        st.push(i);
    }

    // Step 2: Find the potential celebrity
    while(st.size() > 1) {

        int A = st.top();
        st.pop();

        int B = st.top();
        st.pop();

        if(M[A][B] == 1) {
            // A knows B
            // A cannot be celebrity
            st.push(B);
        }
        else {
            // A doesn't know B
            // B cannot be celebrity
            st.push(A);
        }
    }

    // Step 3: Candidate
    int candidate = st.top();

    // Step 4: Verify Row
    for(int j = 0; j < n; j++) {

        if(M[candidate][j] == 1) {
            return -1;
        }
    }

    // Step 5: Verify Column
    for(int i = 0; i < n; i++) {

        if(i != candidate && M[i][candidate] == 0) {
            return -1;
        }
    }

    return candidate;
}

int main() {

    vector<vector<int>> M = {
        {0,1,1},
        {0,0,0},
        {0,1,0}
    };

    int n = M.size();

    cout << "Celebrity Index = "
         << celebrity(M, n);

    return 0;
}