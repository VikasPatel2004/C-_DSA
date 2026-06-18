#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 0);
        stack<int> s;

        // Traverse 2*n times for circular array
        for (int i = 2 * n - 1; i >= 0; i--) {

            while (!s.empty() && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }

            ans[i % n] = s.empty() ? -1 : nums[s.top()];

            s.push(i % n);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 2, 1};

    vector<int> result = obj.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}