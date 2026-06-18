#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        deque<int> dq;

        // First window
        for(int i = 0; i < k; i++) {

            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Store first window maximum
        res.push_back(nums[dq.front()]);

        // Remaining windows
        for(int i = k; i < nums.size(); i++) {

            // Remove elements outside window
            while(!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }

            // Remove smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Store current window maximum
            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

int main() {

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    Solution obj;

    vector<int> ans = obj.maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}