#include <iostream>
#include <vector>
using namespace std;

// Function to search target in rotated sorted array
int rotatedBinarySearch(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Check if left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Right half must be sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1; // Target not found
}


int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 1;
    int result = rotatedBinarySearch(nums, target);

    cout << "Index of target: " << result << endl;
    return 0;
}
