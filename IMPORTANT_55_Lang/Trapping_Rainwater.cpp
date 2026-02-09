 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Output for Example 1: " << sol.trap(height1) << endl; // Expected: 6

    // Example 2
    vector<int> height2 = {4,2,0,3,2,5};
    cout << "Output for Example 2: " << sol.trap(height2) << endl; // Expected: 9

    return 0;
}   