#include <iostream>
#include <vector>
#include <climits>   // for INT_MIN
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int maxsum = INT_MIN;

        // Normal index-based loop
        for (int i = 0; i < nums.size(); i++) {
            currsum += nums[i];
            maxsum = max(maxsum, currsum);
            if (currsum < 0) {
                currsum = 0;
            }
        }

        return maxsum;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Subarray Sum = " << sol.maxSubArray(nums) << endl;

    return 0;
}