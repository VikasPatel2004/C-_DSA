#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find maximum consecutive 1's
int findMaxConsecutiveOnes(vector<int>& nums) {

    int count = 0;
    int maxcount = 0;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] == 1) {
            count++;
            maxcount = max(maxcount, count);
        }
        else {
            count = 0;
        }
    }

    return maxcount;
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements (0 or 1): ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = findMaxConsecutiveOnes(nums);

    cout << "\nMaximum Consecutive Ones = " << ans << endl;

    return 0;
}