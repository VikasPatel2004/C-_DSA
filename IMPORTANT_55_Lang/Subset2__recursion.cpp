#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    void solve(int idx,
               vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Base Case
        if(idx >= nums.size()) {

            ans.push_back(current);
            return;
        }

        // TAKE current element
        current.push_back(nums[idx]);

        solve(idx + 1,
              nums,
              current,
              ans);

        current.pop_back();

        // NOT TAKE current element

        while(idx + 1 < nums.size() &&
              nums[idx + 1] == nums[idx]) {

            idx++;
        }

        solve(idx + 1,
              nums,
              current,
              ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),
             nums.end());

        vector<vector<int>> ans;
        vector<int> current;

        solve(0,
              nums,
              current,
              ans);

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> ans =
        s.subsetsWithDup(nums);

    cout << "Subsets are:\n";

    for(auto subset : ans) {

        cout << "[ ";

        for(int num : subset) {
            cout << num << " ";
        }

        cout << "]\n";
    }

    return 0;
}