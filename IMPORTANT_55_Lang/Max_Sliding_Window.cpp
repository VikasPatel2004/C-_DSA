#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices of useful elements
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove smaller elements (they’ll never be needed)
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Add max element of current window to result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,3,-1,-3,5,3,6,7};
    int k1 = 3;
    vector<int> res1 = sol.maxSlidingWindow(nums1, k1);
    cout << "Output for Example 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    // Example 2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> res2 = sol.maxSlidingWindow(nums2, k2);
    cout << "Output for Example 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}