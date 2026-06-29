#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums) {

    int sum = 0;
    int maxsum = INT_MIN;

    for(int i = 0; i < nums.size(); i++) {

        sum += nums[i];

        // Store the maximum sum
        maxsum = max(maxsum, sum);

        // If sum becomes negative,
        // start a new subarray
        if(sum < 0) {
            sum = 0;
        }
    }

    return maxsum;
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

    int ans = maxSubArray(nums);

    cout << "Maximum Subarray Sum = " << ans << endl;

    return 0;
}