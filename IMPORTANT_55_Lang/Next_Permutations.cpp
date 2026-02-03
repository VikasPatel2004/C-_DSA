#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int piv = -1, n = nums.size();
        
        // Step 1: Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                piv = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse whole array
        if (piv == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find element greater than pivot from right
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[piv]) {
                swap(nums[i], nums[piv]);
                break;
            }
        }

        // Step 4: Reverse suffix after pivot
        int i = piv + 1, j = n - 1;
        while (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3};
    sol.nextPermutation(nums1);
    cout << "Next permutation of [1,2,3]: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {3, 2, 1};
    sol.nextPermutation(nums2);
    cout << "Next permutation of [3,2,1]: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {1, 1, 5};
    sol.nextPermutation(nums3);
    cout << "Next permutation of [1,1,5]: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;

    vector<int> nums4 = {1, 3, 2};
    sol.nextPermutation(nums4);
    cout << "Next permutation of [1,3,2]: ";
    for (int x : nums4) cout << x << " ";
    cout << endl;

    return 0;
}