#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[idx] = nums1[i];
                idx--;
                i--;
            } else {
                nums1[idx] = nums2[j];
                idx--;
                j--;
            }
        }
        while (j >= 0) {
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // nums1 has extra space
    int m = 3; // number of valid elements in nums1
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}