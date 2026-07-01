#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {

    sort(nums.begin(), nums.end());

    int duplicate = -1;
    int missing = 1;

    int n = nums.size();

    for(int i = 1; i < n; i++) {

        if(nums[i] == nums[i - 1]) {

            duplicate = nums[i];
        }

        else if(nums[i] > nums[i - 1] + 1) {

            missing = nums[i - 1] + 1;
        }
    }

    // If the missing number is n
    if(nums[n - 1] != n) {

        missing = n;
    }

    return {duplicate, missing};
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

    vector<int> ans = findErrorNums(nums);

    cout << "Duplicate Number = " << ans[0] << endl;
    cout << "Missing Number = " << ans[1] << endl;

    return 0;
}