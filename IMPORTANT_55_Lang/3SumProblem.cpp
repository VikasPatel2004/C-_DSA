#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());  // sort array

        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

            int j = i + 1, k = n - 1;
            while (j < k) {
                int sumTriplet = nums[i] + nums[j] + nums[k];
                if (sumTriplet == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    // skip duplicates for j and k
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++; k--;
                } else if (sumTriplet < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> ans = sol.threeSum(nums);

    cout << "Triplets that sum to 0 are:\n";
    for (auto triplet : ans) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}