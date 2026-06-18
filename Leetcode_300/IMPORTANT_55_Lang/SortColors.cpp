#include <iostream>
#include <vector>
#include <algorithm> // for swap

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int high = nums.size() - 1, low = 0, mid = 0;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original array: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    sol.sortColors(nums);

    cout << "Sorted array:   ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    return 0;
}