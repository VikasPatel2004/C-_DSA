#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {

    int st = 0;
    int end = nums.size() - 1;

    while(st <= end) {

        int mid = st + (end - st) / 2;

        if(target == nums[mid]) {
            return mid;
        }

        // Left half sorted
        else if(nums[st] <= nums[mid]) {

            if(nums[st] <= target && target <= nums[mid]) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        // Right half sorted
        else {

            if(target >= nums[mid] && target <= nums[end]) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    vector<int> nums = {4,5,6,7,0,1,2};

    int target = 0;

    int ans = search(nums, target);

    cout << "Index = " << ans << endl;

    return 0;
}