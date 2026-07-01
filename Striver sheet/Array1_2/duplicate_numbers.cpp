#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {

    // Phase 1: Detect the cycle
    int slow = nums[0];
    int fast = nums[0];

    // Using do-while because initially
    // slow and fast are equal
    do {

        slow = nums[slow];          // Move one step
        fast = nums[nums[fast]];    // Move two steps

    } while(slow != fast);

    // Phase 2: Find the entrance of the cycle
    slow = nums[0];

    while(slow != fast) {

        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int duplicate = findDuplicate(nums);

    cout << "Duplicate Number = " << duplicate << endl;

    return 0;
}