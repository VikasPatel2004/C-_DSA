#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = target - first;

            if(m.find(second) != m.end()) {
                ans.push_back(m[second]);
                ans.push_back(i);
                break;
            }

            m[first] = i;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    cout << "Indices of the two numbers that add up to " << target << " are: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}