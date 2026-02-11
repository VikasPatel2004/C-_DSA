#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]); // sentinel 0 at the end
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> heights1 = {2,1,5,6,2,3};
    cout << "Input: [2,1,5,6,2,3]\n";
    cout << "Largest Rectangle Area = " << sol.largestRectangleArea(heights1) << "\n\n";

    // Example 2
    vector<int> heights2 = {2,4};
    cout << "Input: [2,4]\n";
    cout << "Largest Rectangle Area = " << sol.largestRectangleArea(heights2) << "\n";

    return 0;
}