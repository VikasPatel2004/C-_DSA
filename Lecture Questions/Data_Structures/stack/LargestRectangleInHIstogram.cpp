#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left(n);
        vector<int> right(n);

        stack<int> s;

        // Nearest Smaller to Left
        for(int i = 0; i < n; i++) {

            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if(s.empty()) {
                left[i] = -1;
            }
            else {
                left[i] = s.top();
            }

            s.push(i);
        }

        // Clear stack
        while(!s.empty()) {
            s.pop();
        }

        // Nearest Smaller to Right
        for(int i = n - 1; i >= 0; i--) {

            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if(s.empty()) {
                right[i] = n;
            }
            else {
                right[i] = s.top();
            }

            s.push(i);
        }

        int maxArea = 0;

        // Calculate Maximum Area
        for(int i = 0; i < n; i++) {

            int width = right[i] - left[i] - 1;

            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main() {

    int n;

    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> heights(n);

    cout << "Enter heights: ";

    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    Solution obj;

    int ans = obj.largestRectangleArea(heights);

    cout << "Largest Rectangle Area = " << ans << endl;

    return 0;
}