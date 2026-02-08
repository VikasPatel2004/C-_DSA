#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    // Phase 1: Detect cycle
    int slow = nums[0];
    int fast = nums[0];
    do {
        slow = nums[slow];          // move one step
        fast = nums[nums[fast]];    // move two steps
    } while (slow != fast);

    // Phase 2: Find cycle entrance
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << "Duplicate number: " << findDuplicate(nums) << endl;
    return 0;
}